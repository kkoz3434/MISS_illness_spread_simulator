//
// Created by kkoz34 on 27.03.23.
//

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Text.hpp>
#include "GraphDrawer.h"
#include "Simulation.h"

GraphDrawer::GraphDrawer() : dots(GRAPH_WIDTH) {
    healthyAgents.push_back(AGENTS_NO);
    infectedAgents.push_back(SICK_AGENTS_NO);
    deadAgents.push_back(0);
    healedAgents.push_back(0);
    agentsAmount = AGENTS_NO;
    font.loadFromFile("../fonts/Montserrat.ttf");
}

void drawMenu(std::shared_ptr<RenderWindow> renderWindow, int xSpacing, int ySpacing, int windowHeight, int windowWidth,
              sf::Font font) {
    sf::VertexArray lineX(sf::LineStrip, 2);
    lineX[0] = sf::Vector2f(xSpacing, windowHeight + ySpacing / 4);
    lineX[1] = sf::Vector2f(windowWidth, windowHeight + ySpacing / 4);
    lineX[0].color = sf::Color::Black;
    lineX[1].color = sf::Color::Black;

    sf::VertexArray lineY(sf::LineStrip, 2);
    lineY[0] = sf::Vector2f(xSpacing, ySpacing / 4);
    lineY[1] = sf::Vector2f(xSpacing, windowHeight + ySpacing / 4);
    lineY[0].color = sf::Color::Black;
    lineY[1].color = sf::Color::Black;

    sf::Text text100;
    text100.setFillColor(sf::Color::Black);
    text100.setCharacterSize(16);
    text100.setPosition(xSpacing / 10, ySpacing / 4);
    text100.setString("100%");
    text100.setFont(font);

    sf::Text text0;
    text0.setFillColor(sf::Color::Black);
    text0.setCharacterSize(16);
    text0.setPosition(xSpacing / 10, windowHeight + ySpacing / 4 - 16);
    text0.setString("0%");
    text0.setFont(font);

    renderWindow->draw(text100);
    renderWindow->draw(text0);
    renderWindow->draw(lineX);
    renderWindow->draw(lineY);
}


sf::CircleShape makeDot(sf::Color color, float value, float maxX, float maxY, int ySpacing) {
    CircleShape circle = CircleShape(1);
    circle.setPosition(Vector2f(maxX, ySpacing / 4 + abs((maxY * (1 - (value * 1.0 / AGENTS_NO))))));
    circle.setFillColor(color);
    return circle;
}

void updateDots(std::vector<sf::CircleShape> &dots, int xSpacing) {
    std::vector<CircleShape> toSave;
    for (CircleShape &circle: dots) {
        if (circle.getPosition().x > xSpacing) {
            circle.setPosition(circle.getPosition().x - 1, circle.getPosition().y);
            toSave.push_back(circle);
        }
    }
    dots = toSave;
}

void GraphDrawer::updateGraph(std::shared_ptr<RenderWindow> renderWindow, float healthy, float infected, float dead, float healed) {
    renderWindow->clear(Color(255, 255, 255));
    float graphWidth = GRAPH_WIDTH - xSpacing;
    float graphHeight = GRAPH_HEIGHT - ySpacing;

    dots.push_back(makeDot(Color(0, 255, 0, 120), healthy, graphWidth, graphHeight, ySpacing));
    dots.push_back(makeDot(Color(255, 0, 0, 120), infected, graphWidth, graphHeight, ySpacing));
    dots.push_back(makeDot(Color(0, 0, 255, 120), healed, graphWidth, graphHeight, ySpacing));
    dots.push_back(makeDot(Color(0, 0, 0, 120), dead, graphWidth, graphHeight, ySpacing));

    updateDots(dots, xSpacing);
    for (CircleShape &dot: dots) {
        renderWindow->draw(dot);
    }
    drawMenu(renderWindow, xSpacing, ySpacing, graphHeight, graphWidth, font);
    renderWindow->display();
}





