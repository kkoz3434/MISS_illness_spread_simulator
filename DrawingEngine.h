//
// Created by kkoz34 on 25.03.23.
//

#ifndef MISS_DRAWINGENGINE_H
#define MISS_DRAWINGENGINE_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

using namespace sf;

class DrawingEngine {
public:
    DrawingEngine(float width, float height);

    float simulationHeight{};
    float simulationWidth{};
    RectangleShape background;

    void init(RenderWindow& window);

};


#endif //MISS_DRAWINGENGINE_H
