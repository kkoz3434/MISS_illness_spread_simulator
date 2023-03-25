//
// Created by kkoz34 on 25.03.23.
//

#include <random>
#include "Agent.h"
#include "Simulation.h"

Agent::Agent(const sf::Vector2f &position, const sf::Vector2f &speed, bool isSick) : position(position), speed(speed),
                                                                                     isSick(isSick) {}

void Agent::update(sf::Time time, std::vector<Agent> &agents, float simulation_width, float simulation_height) {
    position += speed * time.asSeconds();
    wrapPosition(simulation_width, simulation_height);
    updateSickness(agents);
    shuffleAgentBehaviour();
}

Agent::Agent() {
    float x = Agent::getRandom(0, SIMULATION_WIDTH);
    float y = Agent::getRandom(0, SIMULATION_HEIGHT);
    float dx = Agent::getRandom(-AGENT_SPEED, AGENT_SPEED);
    float dy = Agent::getRandom(-AGENT_SPEED, AGENT_SPEED);
    Vector2f randPosition = Vector2f(x, y);
    Vector2f randSpeed = Vector2f(dx, dy);
    this->position = randPosition;
    this->speed = randSpeed;
    this->isSick = false;
}

float Agent::getRandom(float a, float b) {
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_real_distribution<> distribution(a, b); // define the range
    return distribution(gen);
    // return ((b - a) * ((float)rand() / RAND_MAX)) + a; //bad alternative
}

void Agent::shuffleAgentBehaviour() {
    if (getRandom(0, 1) > BEHAVIOUR_CONSISTENCY) {
        float dx = Agent::getRandom(-AGENT_SPEED, AGENT_SPEED);
        float dy = Agent::getRandom(-AGENT_SPEED, AGENT_SPEED);
        Vector2f randSpeed = Vector2f(dx, dy);
        speed = randSpeed;
    }
}

void Agent::wrapPosition(float simulation_width, float simulation_height) {
    float x = position.x;
    if (x > simulation_width) {
        position.x -= abs(x - simulation_width);
        speed.x = -1 * speed.x;
    }
    if (x < 0) {
        position.x += abs(x);
        speed.x = -1 * speed.x;
    }

    float y = position.y;
    if (y > simulation_width) {
        position.y -= abs(y - simulation_height);
        speed.y = -1 * speed.y;
    }
    if (y < 0) {
        position.y += abs(y);
        speed.y = -1 * speed.y;

    }
}

void Agent::updateSickness(const std::vector<Agent> &agents) {
    //todo dodać różne strategie zarażania, coś jak command -> command.willInfect(agent1, agent2), command drugim parametrem
    for (Agent agent: agents) {
        Vector2f a = agent.position - position;
        float distance = a.x * a.x + a.y * a.y;
        if (distance < pow(INFECTION_DISTANCE, 2) && agent.isSick) {
            isSick = true;
            return;
        }
    }
}


