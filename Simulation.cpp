//
// Created by kkoz34 on 25.03.23.
//

#include <utility>
#include "Simulation.h"

Simulation::Simulation(std::shared_ptr<RenderWindow> window, std::shared_ptr<GraphDrawer> graphDrawer,
                       std::shared_ptr<RenderWindow> graphWindow, std::shared_ptr<RenderWindow> infoWindow, std::shared_ptr<StatsDrawer> statsDrawer) : renderWindow(std::move(window)),
                                                                    drawingEngine(std::make_unique<DrawingEngine>(
                                                                            SIMULATION_HEIGHT, SIMULATION_WIDTH)),
                                                                    graphDrawer(std::move(graphDrawer)),
                                                                    graphWindow(std::move(graphWindow)),
                                                                    infoWindow(std::move(infoWindow)),
                                                                    statsDrawer(std::move(statsDrawer)){
}

void Simulation::init() {
    drawingEngine->init(*renderWindow);
    renderWindow->display();

    statsDrawer->init();
    //initialize agents
    for (int i = 0; i < AGENTS_NO; ++i) {
        agents.emplace_back();
    }

    for (Agent& agent : agents) {
        agent.makeFriends();
    }

    auto iterator = agents.begin();
    for (int i = 0; i < SICK_AGENTS_NO; ++i) {
        iterator->makeSick();
        iterator++;
    }
}

void Simulation::run() {
    Time startFrameTime = clock.getElapsedTime();
    Time endFrameTime = clock.getElapsedTime();
    Time frameTime;
    int counter = GRAPH_UPDATE;
    while (renderWindow->isOpen() || graphWindow->isOpen() || infoWindow->isOpen()) {
        renderWindow->clear();
        Event event{};
        while (renderWindow->pollEvent(event)) {
            if (event.type == Event::Closed) {
                renderWindow->close();
            }
        }
        while (graphWindow->pollEvent(event)) {
            if (event.type == Event::Closed) {
                graphWindow->close();
            }
        }
        while (infoWindow->pollEvent(event)) {
            if (event.type == Event::Closed) {
                infoWindow->close();
            }
        }
        endFrameTime = clock.getElapsedTime();
        frameTime = endFrameTime - startFrameTime;
        startFrameTime = clock.getElapsedTime();

        // collect data to stats features
        float healthy = 0;
        float infected = 0;
        float dead = 0;
        float healed = 0;
        for (const Agent &agent: agents) {
            if (!agent.checkIsAlive()) {
                dead++;
            } else if (!agent.checkIsSick() && agent.checkAfterRecovery()) {
                healed++;
            } else if (!agent.checkIsSick()) {
                healthy++;
            } else if (agent.checkIsSick()) {
                infected++;
            }
        }

        update(frameTime);
        statsDrawer->updateStats(infoWindow, healthy, infected, dead, healed, clock.getElapsedTime());
        if (counter % GRAPH_UPDATE == 0) {
            graphDrawer->updateGraph(graphWindow, healthy, infected, dead, healed);
            counter = 1;
        }
        counter++;
    }
}

void Simulation::update(Time frameTime) {
    for (Agent &agent: agents) {
        agent.update(frameTime, agents);
    }
    drawingEngine->draw(*renderWindow, agents);
    renderWindow->display();
}