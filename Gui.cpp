#include "Gui.h"

Gui::Button::Button(){

}

Gui::Button::Button(int x, int y, int width, int height) {
    auto SpecificTarget = std::make_shared<sf::RectangleShape>();
    DrawTarget.push_back(SpecificTarget);
    SpecificTarget->setSize(sf::Vector2f(width, height)); // will change magic numbers
    SpecificTarget->setPosition(x,y);
    SpecificTarget->setFillColor(sf::Color::Red);
    SpecificTarget->setOutlineColor(sf::Color::Black);
    SpecificTarget->setOutlineThickness(1);
}

Gui::Button::~Button() {
    
}
