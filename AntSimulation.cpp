#include "AntSimulation.h"
#include "Menu.h"
#include "Globals.h"
#include <memory>
void AntSimulation::initWindow(){
    window = std::make_shared<sf::RenderWindow>(sf::VideoMode(WindowWidth,WindowHeight),this->title);
}


AntSimulation::AntSimulation(std::string title){
    gridsize = gridsizeX*gridsizeY;
    font = std::make_shared<sf::Font>();
    if(!font->loadFromFile("fonts/Dosis-Light.ttf")){
        printf("Couldn't Load font");
    }
    map = std::make_shared<Map>();
    menu = std::make_shared<Menu>();
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
    sf::Mouse mouse;
    sf::Vector2i mousePos = mouse.getPosition(*window);
    sf::Vector2f relativemousePos = window->mapPixelToCoords(mousePos);
    /*Menu buttons positions: */
    while (window->pollEvent(event))
    {
        /* // can be used for hovering
        if(cursorPos.x < MenuWidth){
            if(cursorPos.x >= 10 && cursorPos.x <= 20 && cursorPos.y >= 10 && cursorPos.y <= 20){

            }
        }*/
        if (event.type == sf::Event::Closed){ // controller will be here depending on the user events we get
            window->close();
        }
        if (mouse.isButtonPressed(sf::Mouse::Left)){
            if(mousePos.x > MenuWidth){
                map->NotifyLeftClick(mousePos.x,mousePos.y);
            }
        }
        if (event.type == sf::Event::MouseButtonPressed){
            if(event.mouseButton.button == sf::Mouse::Left){
                if(event.mouseButton.x < MenuWidth){
                    menu->NotifyLeftClick(event.mouseButton.x,event.mouseButton.y);
                    continue;
                }
                //printf("%d,", map->PositionToTileIndex(event.mouseButton.x,event.mouseButton.y));
                printf(": %d , %d , %d , %d :",mousePos.x,mousePos.y,event.mouseButton.x,event.mouseButton.y);
                map->NotifyLeftClick(event.mouseButton.x,event.mouseButton.y);
            }
        }
    }
}

void AntSimulation::render(){
    window->clear();

    map->render();
    menu->render();

    window->display();
}

void AntSimulation::run(){
    while (window->isOpen()){
        this->updateDt();
		this->update();// logic of the simulation update
		this->render();
    }
}