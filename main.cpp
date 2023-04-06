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

    std::shared_ptr<RenderWindow> infoWindow = std::make_shared<RenderWindow>(VideoMode(INFO_WIDTH, INFO_HEIGHT),
                                                                               TITLE);
    infoWindow->setVerticalSyncEnabled(true);

    std::shared_ptr<StatsDrawer> statsDrawer = std::make_shared<StatsDrawer>();


    Simulation simulation = Simulation(renderWindow, graphDrawer, graphWindow, infoWindow, statsDrawer);
    simulation.init();
    simulation.run();
    return 0;
}
