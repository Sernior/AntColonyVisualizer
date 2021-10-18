#include "Menu.h"
#include "Globals.h"

Menu::Menu()
{
    //this is the definition of the background of the menu
    auto SpecificTarget = std::make_shared<sf::RectangleShape>();
    DrawTarget.push_back(SpecificTarget);
    SpecificTarget->setSize(sf::Vector2f(MenuWidth, WindowHeight));
    SpecificTarget->setPosition(0,0);
    SpecificTarget->setFillColor(sf::Color::White);

    buttons.push_back(std::make_shared<Gui::Button>(10,10,10,10));
}

Menu::~Menu() {
    
}
void Menu::render(){
    Renderable::render();
    for (auto& b : buttons){
        b->render();
    }
    //the rest of the menu's components rendering is done here.
}