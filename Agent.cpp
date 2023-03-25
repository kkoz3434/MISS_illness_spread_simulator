//
// Created by kkoz34 on 25.03.23.
//

#include "Agent.h"

Agent::Agent(const sf::Vector2f &position, const sf::Vector2f &speed, bool isSick) : position(position), speed(speed),
                                                                                     isSick(isSick) {}

void Agent::move(sf::Time time) {
    position += speed * time.asSeconds();

}

