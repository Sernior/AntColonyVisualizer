#include "AntSimulation.h"
#include "Globals.h"
#include <memory>
void AntSimulation::initWindow(){
    window = std::make_shared<sf::RenderWindow>(sf::VideoMode(WindowWidth,WindowHeight),this->title);
}


AntSimulation::AntSimulation(std::string title){
    gridsize = gridsizeX*gridsizeY;
    map = std::make_shared<Map>();

    this->title = title;
    this->initWindow();
}

AntSimulation::~AntSimulation(){
}


void AntSimulation::updateDt(){
    this->dt = this->dtClock.restart().asSeconds();
}

void AntSimulation::update(){
    sf::Event event;
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed){ // controller will be here depending on the user events we get
            window->close();
        }
        if (event.type == sf::Event::MouseButtonPressed){
            if(event.mouseButton.button == sf::Mouse::Left){
                if(event.mouseButton.x < WindowWidth-GridWidth){
                    continue; // this is a left mouse click on the menu
                }
                printf("%d,", map->PositionToTileIndex(event.mouseButton.x,event.mouseButton.y));
            }
        }
    }
}

void AntSimulation::render(){
    window->clear();

    map->render();

    window->display();
}

void AntSimulation::run(){
    while (window->isOpen()){
        this->updateDt();
		this->update();// logic of the simulation update
		this->render();
    }
}