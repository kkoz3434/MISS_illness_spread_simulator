//
// Created by kkoz34 on 25.03.23.
//

#include <random>
#include "Agent.h"
#include "Simulation.h"

Agent::Agent() {
    float x = Agent::getRandomInt(0, SIMULATION_WIDTH);
    float y = Agent::getRandomInt(0, SIMULATION_HEIGHT);
    float dx = Agent::getRandomInt(-AGENT_SPEED, AGENT_SPEED);
    float dy = Agent::getRandomInt(-AGENT_SPEED, AGENT_SPEED);
    this->position = Vector2f(x, y);
    this->speed = Vector2f(dx, dy);
    this->isSick = false;
    this->isAlive = true;
    this->infectionTime = 0;
    this->infectionElapsedTime = 0;
    this->deathChance = DEATH_RATE;
    this->afterRecovery = false;
    this->lastMeeting = 0;
}

void Agent::makeFriends(){
    for (int i = 0; i < AGENTS_FRIENDS_NO; ++i) {
        if(getRandomFloat(0, 1) > 0.5){
            friends.push_back(getRandomInt(0, AGENTS_NO));
        }
    }

    std::cout<<"FRIENDS_NO: "<<friends.size()<<std::endl;
}

void Agent::update(sf::Time time, std::vector<Agent> &agents) {
    updatePosition(time);
    updateSickness(agents);
    updateAgentBehaviour();
}

void Agent::updatePosition(sf::Time &frameTime) {
    if (isAlive) {
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
    lastMeeting++;
    if (isSick) {
        infectionElapsedTime++;
        if (infectionElapsedTime > infectionTime && isAlive) {
            if (getRandomFloat(0., 1.) < deathChance) {
                isAlive = false;
                speed = Vector2f(0, 0);
            } else {
                isSick = false;
                afterRecovery = true;
                deathChance = DEATH_RATE_AFTER_RECOVERY;
            }
        }
    } else {
        if(lastMeeting > AGENT_MEETING_PERIOD){
            lastMeeting = 0;
            for(int friendIndex: friends){
                if(agents[friendIndex].isSick){
                    if(getRandomFloat(0, 1) < AGENT_MEETING_INFECTION_CHANCE){
                        std::cout<<"INFECTED DURING MEETING, FROM AGENT "<< friendIndex <<std::endl;
                        this->makeSick();
                        return;
                    }
                }
            }
        }
        for (const Agent &agent: agents) {
            Vector2f a = agent.position - position;
            float distanceSquared = a.x * a.x + a.y * a.y;
            if (distanceSquared < pow(INFECTION_DISTANCE, 2) && agent.isSick && agent.isAlive) {
                if (getRandomFloat(0., 1.) < INFECTION_CHANCE) {
                    isSick = true;
                    infectionTime = (long) getRandomInt(INFECTION_TIME_MIN, INFECTION_TIME_MAX);
                    return;
                }
            }
        }
    }
}

void Agent::updateAgentBehaviour() {
    if (isAlive && getRandomInt(0, 1) > BEHAVIOUR_CONSISTENCY) {
        float dx = Agent::getRandomFloat(-AGENT_SPEED, AGENT_SPEED);
        float dy = Agent::getRandomFloat(-AGENT_SPEED, AGENT_SPEED);
        speed = Vector2f(dx, dy);
    }
}

void Agent::makeSick() {
    isSick = true;
    infectionTime = (long) getRandomInt(INFECTION_TIME_MIN, INFECTION_TIME_MAX);
}

float Agent::getRandomFloat(float a, float b) {
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_real_distribution<float> distribution(a, b); // define the range
    return distribution(gen);
    // return ((b - a) * ((float)rand() / RAND_MAX)) + a; //bad alternative
}

int Agent::getRandomInt(int a, int b) {
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<int> distribution(a, b); // define the range
    return distribution(gen);
    // return ((b - a) * ((float)rand() / RAND_MAX)) + a; //bad alternative
}




