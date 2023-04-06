//
// Created by kkoz34 on 06.04.23.
//

#ifndef MISS_STATSDRAWER_H
#define MISS_STATSDRAWER_H


#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>

class StatsDrawer {
public:
    sf::Font font;
    sf::Text agentsTotal;
    sf::Text agentsAlive;
    sf::Text agentsIll;
    sf::Text agentsHealed;
    sf::Text agentsDead;
    sf::Text timeElapsed;
    sf::CircleShape aliveCircle;
    sf::CircleShape deadCircle;
    sf::CircleShape healedCircle;
    sf::CircleShape illCircle;

    float xSpacing = 20;
    float ySpacing = 20;
    int interLine;

    void init();

    void
    updateStats(std::shared_ptr<sf::RenderWindow> infoWindow, int healthy, int infected, int dead, int healed, sf::Time elapsedTime);

};


#endif //MISS_STATSDRAWER_H
