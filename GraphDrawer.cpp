//
// Created by kkoz34 on 27.03.23.
//

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "GraphDrawer.h"
#include "Simulation.h"

GraphDrawer::GraphDrawer(){
    healthyAgents.push_back(AGENTS_NO);
    infectedAgents.push_back(SICK_AGENTS_NO);
    deadAgents.push_back(0);
    healedAgents.push_back(0);
    agentsAmount = AGENTS_NO;
}

void GraphDrawer::updateGraph(std::shared_ptr<RenderWindow> renderWindow, std::vector<Agent> &agents) {
    float healthy = 0;
    float infected = 0;
    float dead = 0;
    float healed = 0;
    for (const Agent &agent: agents) {
        if (!agent.checkIsAlive()) {
            dead++;
            //std::cout<<"DEAD"<<std::endl;
        } else if (!agent.checkIsSick() && agent.checkAfterRecovery()) {
            healed++;
           // std::cout<<"healed"<<std::endl;
        } else if (!agent.checkIsSick()) {
            healthy++;
        } else if (agent.checkIsSick()) {
            infected++;
          //  std::cout<<"infected"<<std::endl;
        }
    }

    healthyAgents.push_back(healthy);
    infectedAgents.push_back(infected);
    deadAgents.push_back(dead);
    healedAgents.push_back(healed);
    //std::cout<<healedAgents.size()<<std::endl;

    drawGraph(renderWindow);
}

void drawLine(sf::Image &graph, const std::vector<float>& vector, float yMax, float start, sf::Color color) {
    float currentX = start;
    for (const float value: vector) {
        std::cout<<(unsigned int) abs(currentX)<<" "<<(unsigned int) abs((yMax * (1-(value*1.0 / AGENTS_NO))))<<std::endl;
        graph.setPixel((unsigned int) abs(currentX), (unsigned int) abs((yMax * (1-(value*1.0 / AGENTS_NO)))), color);
        currentX++;
    }
    std::cout<<"XD"<<std::endl;
}

std::vector<float> getLastN(std::vector<float> &vector, int N) {
    if(vector.size() > N){
        std::vector<float> result(vector.end() - N, vector.end());
        return (result);
    }
    return vector;
}

void GraphDrawer::drawGraph(std::shared_ptr<RenderWindow> &graphWindow) {
    graphWindow->clear(Color(255, 255, 255));
    float graphWidth = GRAPH_WIDTH - xSpacing;
    float graphHeight = GRAPH_HEIGHT - ySpacing;
    float measurementsAmount =  fmod(healedAgents.size(), graphWidth);
    sf::Image graph;
    graph.create((unsigned int) graphWidth, (unsigned int)graphHeight, Color(255, 255, 255));
    float startX = (graphWidth) -  measurementsAmount;
    drawLine(graph, getLastN(healthyAgents, (int) measurementsAmount), graphHeight, startX, sf::Color(0, 255, 0));
    drawLine(graph, getLastN(infectedAgents, (int) measurementsAmount), graphHeight, startX, sf::Color(255, 0, 0));
    // todo: dowiedzieć sie czemu nie działa tak jak ma działać
    //drawLine(graph, getLastN(deadAgents, (int) measurementsAmount), graphHeight, startX, sf::Color(0, 0, 0));
    //drawLine(graph, getLastN(healedAgents, (int) measurementsAmount), graphHeight, startX, sf::Color(0, 0, 255));

    sf::Texture texture;
    texture.loadFromImage(graph);
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition((float)(xSpacing*1./2.f),(float) (ySpacing*1./2));

    graphWindow->draw(sprite);
    graphWindow->display();
}



