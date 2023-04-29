//
// Created by kkoz34 on 25.03.23.
//

#ifndef MISS_AGENT_H
#define MISS_AGENT_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Time.hpp>
#include <list>

#define MAP_SIZE 100.f

class Agent {
public:
    Agent();

    void update(sf::Time time, std::vector<Agent> &agents);

    void makeSick();

    void makeFriends();

    inline bool checkIsSick() const { return isSick; }

    inline bool checkIsAlive() const { return isAlive; }

    inline sf::Vector2f getPosition() const { return position; }

    inline bool checkAfterRecovery() const { return afterRecovery; }

private:
    sf::Vector2f position;
    sf::Vector2f speed;
    bool isSick;
    bool isAlive;
    bool afterRecovery;
    long infectionTime;
    long infectionElapsedTime;
    float deathChance;
    std::vector<int> friends;
    long lastMeeting;

    void updatePosition(sf::Time &frameTime);

    void updateAgentBehaviour();

    static float getRandomFloat(float a, float b);

    void updateSickness(const std::vector<Agent> &agents);

    static int getRandomInt(int a, int b);


};


#endif //MISS_AGENT_H
