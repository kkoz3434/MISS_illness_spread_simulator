#include <iostream>
#include <SFML/Graphics.hpp>
#include "Simulation.h"
#include "GraphDrawer.h"

#define TITLE "title"
#define WINDOW_HEIGHT 800
#define WINDOW_WIDTH 800


int main() {
    std::shared_ptr<RenderWindow> renderWindow = std::make_shared<RenderWindow>(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
                                                                                TITLE);
    renderWindow->setVerticalSyncEnabled(true);
    std::shared_ptr<RenderWindow> graphWindow = std::make_shared<RenderWindow>(VideoMode(GRAPH_WIDTH, GRAPH_HEIGHT),
                                                                               TITLE);
    graphWindow->setVerticalSyncEnabled(true);
    std::shared_ptr<GraphDrawer> graphDrawer = std::make_shared<GraphDrawer>();


    Simulation simulation = Simulation(renderWindow, graphDrawer, graphWindow);
    simulation.init();
    simulation.run();
    return 0;
}
