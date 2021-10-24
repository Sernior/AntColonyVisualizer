#include "Gui.h"
#include "Globals.h"
Gui::Button::Button(){

}

Gui::Button::Button(int x, int y, int width, int height, std::string name) {
    id = name;
    status = false;

    auto SpecificTarget = std::make_shared<sf::RectangleShape>();
    DrawTarget.push_back(SpecificTarget);
    SpecificTarget->setSize(sf::Vector2f(width, height));
    SpecificTarget->setPosition(x,y);
    SpecificTarget->setFillColor(sf::Color::White);
    SpecificTarget->setOutlineColor(sf::Color::Black);
    SpecificTarget->setOutlineThickness(1);

    auto Text = std::make_shared<sf::Text>(name ,*font);
    Text->setCharacterSize(14);
    Text->setFillColor(sf::Color::Black);
    Text->setStyle(sf::Text::Bold);
    Text->setPosition(x+(width*1.3),y);
    DrawTarget.push_back(Text);
}

Gui::Button::~Button() {
    
}

bool Gui::Button::Click() {
    auto SpecificTarget = std::dynamic_pointer_cast<sf::RectangleShape>(DrawTarget.front());
    printf("%d",status);
    if(!status){
        status = true;
        SpecificTarget->setFillColor(sf::Color::Yellow);
    }
    else{
        status = false;
        SpecificTarget->setFillColor(sf::Color::White);
    }
    return status;
}