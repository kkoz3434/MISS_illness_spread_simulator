//
// Created by kkoz34 on 25.03.23.
//

#ifndef MISS_DRAWINGENGINE_H
#define MISS_DRAWINGENGINE_H


#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "Agent.h"

using namespace sf;

class DrawingEngine {
public:
    DrawingEngine(float width, float height);

    void init(RenderWindow &window);

    void draw(RenderWindow &window, const std::list<Agent> &agents);

private:
    float simulationHeight;
    float simulationWidth;
    RectangleShape background;

};


#endif //MISS_DRAWINGENGINE_H
