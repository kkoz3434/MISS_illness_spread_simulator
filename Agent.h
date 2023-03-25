//
// Created by kkoz34 on 25.03.23.
//

#ifndef MISS_AGENT_H
#define MISS_AGENT_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Time.hpp>

#define MAP_SIZE 100.f

class Agent {
public:
    sf::Vector2f position;
    sf::Vector2f speed;
    bool isSick;

    Agent();

    Agent(const sf::Vector2f &position, const sf::Vector2f &speed, bool isSick);

    void shuffleAgentBehaviour();

    static float getRandom(float a, float b);

    void update(sf::Time time, std::vector<Agent> &agents, float simulation_width, float simulation_height);


private:
    void wrapPosition(float simulation_width, float simulation_height);

    void updateSickness(const std::vector<Agent> &agents);
};


#endif //MISS_AGENT_H
