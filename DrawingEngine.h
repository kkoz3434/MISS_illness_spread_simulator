//
// Created by kkoz34 on 25.03.23.
//

#ifndef MISS_DRAWINGENGINE_H
#define MISS_DRAWINGENGINE_H
#define AGENT_SIZE 10.

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "Agent.h"

using namespace sf;

class DrawingEngine {
public:
    DrawingEngine(float width, float height);

    float simulationHeight{};
    float simulationWidth{};
    RectangleShape background;

    void init(RenderWindow& window);
    static void draw(RenderWindow& window, std::vector<Agent> agents);
};


#endif //MISS_DRAWINGENGINE_H
