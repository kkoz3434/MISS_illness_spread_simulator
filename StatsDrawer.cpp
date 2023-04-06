//
// Created by kkoz34 on 06.04.23.
//

#include "StatsDrawer.h"
#include "Simulation.h"


sf::CircleShape initCircle(sf::Color color) {
    sf::CircleShape shape;
    shape.setRadius(INFO_FONT_SIZE/2);
    shape.setFillColor(color);
    return shape;
}


void StatsDrawer::updateStats(std::shared_ptr<sf::RenderWindow> infoWindow, int healthy, int infected, int dead,
                              int healed, sf::Time elapsedTime) {
    infoWindow->clear(Color(255, 255, 255));
    agentsAlive.setString("Healthy: " + std::to_string(healthy) + "   (" + std::to_string((int)(healthy*1.0/AGENTS_NO*100))+"%)");
    agentsIll.setString("Infected: " + std::to_string(infected) + "   (" + std::to_string((int)(infected*1.0/AGENTS_NO*100))+"%)");
    agentsDead.setString("Dead: " + std::to_string(dead) + "   (" + std::to_string((int)(dead*1.0/AGENTS_NO*100))+"%)");
    agentsHealed.setString("Healed: " + std::to_string(healed) + "   (" + std::to_string((int)(healed*1.0/AGENTS_NO*100))+"%)");
    timeElapsed.setString("Time elapsed: " + std::to_string((int) elapsedTime.asSeconds()/60) + "m " +std::to_string((int) elapsedTime.asSeconds()%60)+"s");
    infoWindow->draw(agentsAlive);
    infoWindow->draw(aliveCircle);
    infoWindow->draw(agentsIll);
    infoWindow->draw(illCircle);
    infoWindow->draw(agentsTotal);
    infoWindow->draw(agentsDead);
    infoWindow->draw(deadCircle);
    infoWindow->draw(agentsHealed);
    infoWindow->draw(healedCircle);
    infoWindow->draw(timeElapsed);
    infoWindow->display();
}

void StatsDrawer::init() {
    font.loadFromFile("../fonts/Montserrat.ttf");

    interLine = INFO_FONT_SIZE*2;

    agentsTotal.setFillColor(sf::Color::Black);
    agentsTotal.setCharacterSize(INFO_FONT_SIZE);
    agentsTotal.setPosition(xSpacing, ySpacing);
    agentsTotal.setFont(font);
    agentsTotal.setString("Agents amount: " + std::to_string(AGENTS_NO));

    agentsAlive.setFillColor(sf::Color::Black);
    agentsAlive.setCharacterSize(INFO_FONT_SIZE);
    agentsAlive.setPosition(xSpacing + 2* INFO_FONT_SIZE, ySpacing + interLine);
    agentsAlive.setFont(font);
    aliveCircle = initCircle(sf::Color(0, 255, 0));
    aliveCircle.setPosition(xSpacing, ySpacing + interLine + INFO_FONT_SIZE/4);


    agentsIll.setFillColor(sf::Color::Black);
    agentsIll.setCharacterSize(INFO_FONT_SIZE);
    agentsIll.setPosition(xSpacing + 2* INFO_FONT_SIZE, ySpacing + 2*interLine);
    agentsIll.setFont(font);
    illCircle = initCircle(sf::Color(255, 0, 0));
    illCircle.setPosition(xSpacing, ySpacing + 2*interLine + INFO_FONT_SIZE/4);

    agentsDead.setFillColor(sf::Color::Black);
    agentsDead.setCharacterSize(INFO_FONT_SIZE);
    agentsDead.setPosition(xSpacing + 2* INFO_FONT_SIZE, ySpacing + 3*interLine);
    agentsDead.setFont(font);
    deadCircle = initCircle(sf::Color(0, 0, 0));
    deadCircle.setPosition(xSpacing, ySpacing + 3*interLine + INFO_FONT_SIZE/4);

    agentsHealed.setFillColor(sf::Color::Black);
    agentsHealed.setCharacterSize(INFO_FONT_SIZE);
    agentsHealed.setPosition(xSpacing + 2* INFO_FONT_SIZE, ySpacing + 4*interLine);
    agentsHealed.setFont(font);
    healedCircle = initCircle(sf::Color(0, 0, 255));
    healedCircle.setPosition(xSpacing, ySpacing + 4*interLine + INFO_FONT_SIZE/4);

    timeElapsed.setFillColor(sf::Color::Black);
    timeElapsed.setCharacterSize(INFO_FONT_SIZE);
    timeElapsed.setPosition(xSpacing, ySpacing + 5*interLine);
    timeElapsed.setFont(font);
}
