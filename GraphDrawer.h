//
// Created by kkoz34 on 27.03.23.
//

#ifndef MISS_GRAPHDRAWER_H
#define MISS_GRAPHDRAWER_H


#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include <list>
#include <SFML/Graphics/CircleShape.hpp>
#include "Agent.h"

class GraphDrawer {
public:
    void updateGraph(std::shared_ptr<sf::RenderWindow> graphWindow,std::list<Agent> &agents);

    explicit GraphDrawer();
private:
    std::list<float> healthyAgents;
    std::list<float> healedAgents;
    std::list<float> infectedAgents;
    std::list<float> deadAgents;

    std::vector<sf::CircleShape> dots;
    int agentsAmount;

    int xSpacing = 50;
    int ySpacing = 50;

    void drawGraph(std::shared_ptr<sf::RenderWindow> &graphWindow);


};


#endif //MISS_GRAPHDRAWER_H
