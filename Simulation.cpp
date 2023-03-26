//
// Created by kkoz34 on 25.03.23.
//

#include <random>
#include "Simulation.h"


Simulation::Simulation(std::shared_ptr<RenderWindow> window) : renderWindow(std::move(window)),
                                                               drawingEngine(std::make_unique<DrawingEngine>(
                                                                       SIMULATION_HEIGHT, SIMULATION_WIDTH)) {
    agents.reserve(AGENTS_NO);
}

void Simulation::init() {
    drawingEngine->init(*renderWindow);
    renderWindow->display();

    //initialize agents
    for (int i = 0; i < AGENTS_NO; ++i) {
        agents.emplace_back();
    }
    for (int i = 0; i < SICK_AGENTS_NO; ++i) {
        agents[i].makeSick();
    }
}

void Simulation::run() {
    Time startFrameTime = clock.getElapsedTime();
    Time endFrameTime = clock.getElapsedTime();
    Time frameTime;
    while (renderWindow->isOpen()) {
        renderWindow->clear();
        Event event{};
        while (renderWindow->pollEvent(event)) {
            if (event.type == Event::Closed) {
                renderWindow->close();
            }
        }
        endFrameTime = clock.getElapsedTime();
        frameTime = endFrameTime - startFrameTime;
        startFrameTime = clock.getElapsedTime();

        update(frameTime);
    }
}

void Simulation::update(Time frameTime) {
    for (Agent &agent: agents) {
        agent.update(frameTime, agents);
    }
    drawingEngine->draw(*renderWindow, agents);
    renderWindow->display();
}

