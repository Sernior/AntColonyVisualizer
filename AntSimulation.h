#ifndef SIMULATION
#define SIMULATION
#include <SFML/Graphics.hpp>
#include <string>
#include "Map.h"
#include "Menu.h"
class AntSimulation{
    private:
        std::string title;
        sf::Event sfEvent;
	    sf::Clock dtClock;
        float dt;
        void initWindow();

    public:
        AntSimulation(std::string title);
        ~AntSimulation();// may be needed later to restart the simulation and not leak memory
        void updateDt();
	    void update();
	    void render();
	    void run();
};


#endif