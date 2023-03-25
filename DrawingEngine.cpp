//
// Created by kkoz34 on 25.03.23.
//

#include <SFML/Graphics/RectangleShape.hpp>
#include "DrawingEngine.h"

void DrawingEngine::init(RenderWindow& window) {
    window.draw(background);
}

DrawingEngine::DrawingEngine(float width, float height): simulationHeight(height), simulationWidth(width){
    background = RectangleShape(Vector2f(height, width));
    background.setFillColor(Color(255,255,255));
    background.setPosition(0,0);
}

