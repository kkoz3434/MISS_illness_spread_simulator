//
// Created by kkoz34 on 25.03.23.
//

#ifndef MISS_SIMULATION_H
#define MISS_SIMULATION_H


#define SIMULATION_HEIGHT 800.0
#define SIMULATION_WIDTH 800.0
#define AGENTS_NO 100
#define AGENT_SPEED 10
#define SICK_AGENTS_NO 5

#include <memory>
#include "DrawingEngine.h"
#include "Agent.h"
#include <utility>
#include <SFML/Window/Event.hpp>
#include <iostream>

class Simulation {
public:
    explicit Simulation(std::shared_ptr<RenderWindow> window);

    std::shared_ptr<RenderWindow> renderWindow;
    std::unique_ptr<DrawingEngine> drawingEngine;
    Clock clock;
    std::vector<Agent> agents;


    void init();

    void start();

    void update(Time time);
};


#endif //MISS_SIMULATION_H
