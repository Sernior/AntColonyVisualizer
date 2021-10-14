#ifndef SIMULATION
#define SIMULATION
#include <SFML/Graphics.hpp>
#include <string>
#include "Map.h"
//#include "tile_view.h"//debugging
class AntSimulation{
    private:
        std::string title;
        Map map; //this will be the tile grid
        //std::vector<tile_view> v;//debugging
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