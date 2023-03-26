//
// Created by kkoz34 on 25.03.23.
//

#include <random>
#include "Agent.h"
#include "Simulation.h"

Agent::Agent() {
    float x = Agent::getRandom(0, SIMULATION_WIDTH);
    float y = Agent::getRandom(0, SIMULATION_HEIGHT);
    float dx = Agent::getRandom(-AGENT_SPEED, AGENT_SPEED);
    float dy = Agent::getRandom(-AGENT_SPEED, AGENT_SPEED);
    this->position = Vector2f(x, y);
    this->speed = Vector2f(dx, dy);
    this->isSick = false;
    this->isAlive = true;
    this->infectionTime = 0;
    this->deathChance = DEATH_RATE;
    this->afterRecovery = false;
}

void Agent::update(sf::Time time, std::vector<Agent> &agents) {
    updatePosition(time);
    updateSickness(agents);
    updateAgentBehaviour();
}

void Agent::updatePosition(sf::Time &frameTime) {
    if(isAlive) {
        position += speed * frameTime.asSeconds();
        float x = position.x;
        if (x > SIMULATION_WIDTH) {
            position.x -= abs(x - SIMULATION_WIDTH);
            speed.x = -1 * speed.x;
        }
        if (x < 0) {
            position.x += abs(x);
            speed.x = -1 * speed.x;
        }
        float y = position.y;
        if (y > SIMULATION_HEIGHT) {
            position.y -= abs(y - SIMULATION_HEIGHT);
            speed.y = -1 * speed.y;
        }
        if (y < 0) {
            position.y += abs(y);
            speed.y = -1 * speed.y;
        }
    }
}

void Agent::updateSickness(const std::vector<Agent> &agents) {
    if (isSick) {
        infectionTime++;
        if(infectionTime > INFECTION_TIME && isAlive){
            if(getRandom(0,1)<deathChance){
                isAlive = false;
                speed = Vector2f(0,0);
            } else {
                isSick = false;
                afterRecovery = true;
                deathChance = DEATH_RATE_AFTER_RECOVERY;
            }
        }
    }
    else {
        //todo dodać różne strategie zarażania, coś jak command -> command.willInfect(agent1, agent2), command drugim parametrem
        for (const Agent &agent: agents) {
            Vector2f a = agent.position - position;
            float distanceSquared = a.x * a.x + a.y * a.y;
            if (distanceSquared < pow(INFECTION_DISTANCE, 2) && agent.isSick && agent.isAlive) {
                if (getRandom(0, 1) < INFECTION_CHANCE) {
                    isSick = true;
                    return;
                }
            }
        }
    }
}

void Agent::updateAgentBehaviour() {
    if (isAlive && getRandom(0, 1) > BEHAVIOUR_CONSISTENCY) {
        float dx = Agent::getRandom(-AGENT_SPEED, AGENT_SPEED);
        float dy = Agent::getRandom(-AGENT_SPEED, AGENT_SPEED);
        speed = Vector2f(dx, dy);
    }
}

void Agent::makeSick() {
    isSick = true;
}

float Agent::getRandom(float a, float b) {
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_real_distribution<float> distribution(a, b); // define the range
    return distribution(gen);
    // return ((b - a) * ((float)rand() / RAND_MAX)) + a; //bad alternative
}




