//
// Created by kkoz34 on 25.03.23.
//

#ifndef MISS_SIMULATION_H
#define MISS_SIMULATION_H


#define SIMULATION_HEIGHT 800.0
#define SIMULATION_WIDTH 800.0
#define GRAPH_HEIGHT 300
#define GRAPH_WIDTH 500
#define GRAPH_UPDATE 10
#define INFO_HEIGHT 500
#define INFO_WIDTH 400
#define INFO_FONT_SIZE 16
#define AGENTS_NO 1000
#define AGENT_SPEED 100
#define SICK_AGENTS_NO 10
#define INFECTION_DISTANCE 2
#define BEHAVIOUR_CONSISTENCY 0.7
#define INFECTION_CHANCE 0.9
#define INFECTION_TIME_MAX 3000
#define INFECTION_TIME_MIN 200
#define DEATH_RATE 0.1
#define DEATH_RATE_AFTER_RECOVERY 0.05


#include <memory>
#include "DrawingEngine.h"
#include "Agent.h"
#include "GraphDrawer.h"
#include "StatsDrawer.h"
#include <utility>
#include <SFML/Window/Event.hpp>
#include <iostream>
#include <boost/random.hpp>

class Simulation {
public:
    explicit Simulation(std::shared_ptr<RenderWindow> window, std::shared_ptr<GraphDrawer> graphDrawer,
                        std::shared_ptr<RenderWindow> graphWindow, std::shared_ptr<RenderWindow> infoWindow, std::shared_ptr<StatsDrawer> statsDrawer);

    void init();

    void run();

private:
    std::shared_ptr<RenderWindow> renderWindow;
    std::shared_ptr<RenderWindow> graphWindow;
    std::shared_ptr<RenderWindow> infoWindow;
    std::unique_ptr<DrawingEngine> drawingEngine;
    Clock clock;
    std::list<Agent> agents;
    std::shared_ptr<GraphDrawer> graphDrawer;
    std::shared_ptr<StatsDrawer> statsDrawer;

    void update(Time frameTime);
};


#endif //MISS_SIMULATION_H
