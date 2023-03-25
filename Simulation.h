//
// Created by kkoz34 on 25.03.23.
//

#ifndef MISS_SIMULATION_H
#define MISS_SIMULATION_H


#define SIMULATION_HEIGHT 800.0
#define SIMULATION_WIDTH 800.0
#define AGENTS_NO 500
#define AGENT_SPEED 100
#define SICK_AGENTS_NO 1
#define INFECTION_DISTANCE 2
#define BEHAVIOUR_CONSISTENCY 0.98

#include <memory>
#include "DrawingEngine.h"
#include "Agent.h"
#include <utility>
#include <SFML/Window/Event.hpp>
#include <iostream>
#include <boost/random.hpp>

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
