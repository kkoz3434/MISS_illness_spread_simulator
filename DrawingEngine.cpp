//
// Created by kkoz34 on 25.03.23.
//

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include "DrawingEngine.h"
#include "Simulation.h"

void DrawingEngine::init(RenderWindow &window) {
    window.draw(background);
}

DrawingEngine::DrawingEngine(float width, float height) : simulationHeight(height), simulationWidth(width) {
    background = RectangleShape(Vector2f(height, width));
    background.setFillColor(Color(255, 255, 255));
    background.setPosition(0, 0);
}

void DrawingEngine::draw(RenderWindow &window, const std::vector<Agent> &agents) {
    window.clear(Color(255, 255, 255));
    for (const Agent &agent: agents) {
        sf::CircleShape shape = CircleShape(INFECTION_DISTANCE);
        if (agent.checkSickness()) {
            shape.setFillColor(Color(255, 0, 0, 255)); //todo: extract
        } else {
            shape.setFillColor(Color(0, 255, 0, 255));
        }
        shape.setOrigin(INFECTION_DISTANCE, INFECTION_DISTANCE);
        shape.setPosition((agent.getPosition() * MAP_SIZE / 100.f));
        window.draw(shape);
    }
}



