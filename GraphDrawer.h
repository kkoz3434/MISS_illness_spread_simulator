//
// Created by kkoz34 on 27.03.23.
//

#ifndef MISS_GRAPHDRAWER_H
#define MISS_GRAPHDRAWER_H


#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Agent.h"

class GraphDrawer {
public:
    void updateGraph(std::shared_ptr<sf::RenderWindow> graphWindow,std::vector<Agent> &agents);

    explicit GraphDrawer();
private:
    std::vector<float> healthyAgents;
    std::vector<float> healedAgents;
    std::vector<float> infectedAgents;
    std::vector<float> deadAgents;
    int agentsAmount;

    int xSpacing = 50;
    int ySpacing = 50;

    void drawGraph(std::shared_ptr<sf::RenderWindow> &graphWindow);


};


#endif //MISS_GRAPHDRAWER_H
