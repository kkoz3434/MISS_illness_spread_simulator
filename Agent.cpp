//
// Created by kkoz34 on 25.03.23.
//

#include "Agent.h"
#include "Simulation.h"

Agent::Agent(const sf::Vector2f &position, const sf::Vector2f &speed, bool isSick) : position(position), speed(speed),
                                                                                     isSick(isSick) {}

void Agent::move(sf::Time time) {
    //position += speed * time.asSeconds(); //todo not working
    position.x += speed.x * time.asSeconds();
    position.y+= speed.y * time.asSeconds();
}

Agent::Agent() {
    float x = ((MAP_SIZE) * ((float) rand() / RAND_MAX));
    float y = ((MAP_SIZE) * ((float) rand() / RAND_MAX));
    float dx = ((AGENT_SPEED) * ((float) rand() / RAND_MAX));
    float dy = ((AGENT_SPEED) * ((float) rand() / RAND_MAX));
    Vector2f randPosition = Vector2f(x, y);
    Vector2f randSpeed = Vector2f(dx, dy);

    this->position = randPosition;
    this->speed = randSpeed;
}


