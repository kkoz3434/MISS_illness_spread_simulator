#include <iostream>
#include <SFML/Graphics.hpp>
#include "Simulation.h"

#define TITLE "title"
#define WINDOW_HEIGHT 800
#define WINDOW_WIDTH 800


int main() {
    std::shared_ptr<RenderWindow> renderWindow = std::make_shared<RenderWindow>(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
                                                                                TITLE);
    renderWindow->setVerticalSyncEnabled(true);
    Simulation simulation = Simulation(renderWindow);
    simulation.init();
    simulation.run();
    return 0;
}
