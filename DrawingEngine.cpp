//
// Created by kkoz34 on 25.03.23.
//

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <iostream>
#include "DrawingEngine.h"

void DrawingEngine::init(RenderWindow& window) {
    window.draw(background);
}

DrawingEngine::DrawingEngine(float width, float height): simulationHeight(height), simulationWidth(width){
    background = RectangleShape(Vector2f(height, width));
    background.setFillColor(Color(255,255,255));
    background.setPosition(0,0);
}

void DrawingEngine::draw(RenderWindow &window, std::vector<Agent> agents) {
    window.clear(Color(255,255,255));
    for (Agent agent: agents) {
        sf::CircleShape shape = CircleShape(AGENT_SIZE);
        shape.setFillColor(Color(255,0,0, 255));
        shape.setOrigin(AGENT_SIZE, AGENT_SIZE);
        shape.setPosition((agent.position*MAP_SIZE/100.f));
        window.draw(shape);
        std::cout<<"X";
    }
    std::cout<<std::endl;
}



