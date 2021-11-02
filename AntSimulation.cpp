#include "AntSimulation.h"
#include "Menu.h"
#include "Globals.h"
#include <memory>
#include <random>
void AntSimulation::initWindow(){
    window = std::make_shared<sf::RenderWindow>(sf::VideoMode(WindowWidth,WindowHeight),this->title);
    window->setKeyRepeatEnabled(false);
}


AntSimulation::AntSimulation(std::string title){ // initialize globals
    gridsize = gridsizeX*gridsizeY;
    font = std::make_shared<sf::Font>();
    if(!font->loadFromFile("fonts/Dosis-Light.ttf")){
        printf("Couldn't Load font");
    }
    WeightColors[0] = sf::Color::White;
    for(int i = 20; i != 0; i--){
        WeightColors[21-i] = sf::Color(i*12,i*12,i*12);
    }
    map = std::make_shared<Map>();
    menu = std::make_shared<Menu>();
    timeManager = std::make_shared<TimeManager>(0.1f);
    this->title = title;
    this->initWindow();
}

AntSimulation::~AntSimulation(){
}


void AntSimulation::updateDt(){
    dt = this->dtClock.restart().asSeconds();
    timeManager->Update(dt);
}

void AntSimulation::update(){
    sf::Event event;
    sf::Mouse mouse;
    sf::Vector2i mousePos = mouse.getPosition(*window);
    sf::Vector2f relativemousePos = window->mapPixelToCoords(mousePos);
    /*Menu buttons positions: */
    if (window->pollEvent(event))
    {
        /* // can be used for hovering
        if(cursorPos.x < MenuWidth){
            if(cursorPos.x >= 10 && cursorPos.x <= 20 && cursorPos.y >= 10 && cursorPos.y <= 20){

            }
        }*/
        if(sf::Event::MouseButtonReleased){
            if(event.mouseButton.button == sf::Mouse::Left){
                map->NotifyLeftRelease();
            }
        }
        if (event.type == sf::Event::Closed){
            window->close();
        }
        if (mouse.isButtonPressed(sf::Mouse::Left)){
            if(mousePos.x > MenuWidth && mousePos.x < WindowWidth && mousePos.y > 0 && mousePos.y < WindowHeight){
                map->NotifyLeftClick(mousePos.x,mousePos.y);
            }
        }
        if (event.type == sf::Event::MouseButtonPressed){
            if(event.mouseButton.button == sf::Mouse::Left){
                if(event.mouseButton.x < MenuWidth){
                    menu->NotifyLeftClick(event.mouseButton.x,event.mouseButton.y);
                }
                //printf(": %d , %d , %d , %d :",mousePos.x,mousePos.y,event.mouseButton.x,event.mouseButton.y);
            }
        }
    }
}

void AntSimulation::render(){
    window->clear();

    if(menu->MapRendering == MapRenderingState::Rendering){
        map->render();
    }
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
