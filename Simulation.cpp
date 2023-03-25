//
// Created by kkoz34 on 25.03.23.
//

#include <random>
#include "Simulation.h"


void Simulation::init() {
    this->drawingEngine->init(*renderWindow);
    renderWindow->display();
    static std::default_random_engine e;
    static std::uniform_real_distribution<> dis(0, MAP_SIZE);
    for (int i = 0; i < AGENTS_NO; ++i) {
        agents.emplace_back();
    }
    for (int i = 0; i < SICK_AGENTS_NO; ++i) {
        agents[i].isSick = true;
    }
}

Simulation::Simulation(std::shared_ptr<RenderWindow> window) : renderWindow(std::move(window)),
                                                               drawingEngine(std::make_unique<DrawingEngine>(
                                                                       SIMULATION_HEIGHT, SIMULATION_WIDTH)) {

}

void Simulation::start() {
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

        this->update(frameTime);
    }
}



void Simulation::update(Time time) {
    std::cout<<"DRAWING"<<std::endl;
    for(Agent agent: agents) {
        agent.move(time);
    }
    drawingEngine->draw(*renderWindow, agents);
    renderWindow->display();
}

/**
 * klatka - obliczenie pozycji ludzi
 * przechowywanie czasu -> ile minęło od poprzedniej klatki o tyle przesuń chujka
 */


