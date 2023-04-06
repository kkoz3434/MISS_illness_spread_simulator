//
// Created by kkoz34 on 25.03.23.
//

#include <random>
#include <utility>
#include "Simulation.h"

Simulation::Simulation(std::shared_ptr<RenderWindow> window, std::shared_ptr<GraphDrawer> graphDrawer,
                       std::shared_ptr<RenderWindow> graphWindow) : renderWindow(std::move(window)),
                                                                    drawingEngine(std::make_unique<DrawingEngine>(
                                                                            SIMULATION_HEIGHT, SIMULATION_WIDTH)),
                                                                    graphDrawer(std::move(graphDrawer)),
                                                                    graphWindow(std::move(graphWindow)) {
}

void Simulation::init() {
    drawingEngine->init(*renderWindow);
    renderWindow->display();

    //initialize agents
    for (int i = 0; i < AGENTS_NO; ++i) {
        agents.emplace_back();
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
    int counter = 0;
    while (renderWindow->isOpen() && graphWindow->isOpen()) {
        renderWindow->clear();
        Event event{};
        while (renderWindow->pollEvent(event)) {
            if (event.type == Event::Closed) {
                renderWindow->close();
            }
        }
        while(graphWindow->pollEvent(event)){
            if (event.type == Event::Closed) {
                renderWindow->close();
            }
        }
        endFrameTime = clock.getElapsedTime();
        frameTime = endFrameTime - startFrameTime;
        startFrameTime = clock.getElapsedTime();

        update(frameTime);
        counter++;
        if (counter % 1 == 0) {
            graphDrawer->updateGraph(graphWindow, agents);
            counter = 1;
        }
    }
}

void Simulation::update(Time frameTime) {
    for (Agent &agent: agents) {
        agent.update(frameTime, agents);
    }
    drawingEngine->draw(*renderWindow, agents);
    renderWindow->display();
}

