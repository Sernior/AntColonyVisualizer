#include "tile_view.h"
#include "tile.h"
#include "Globals.h"
#include <memory>
tile_view::tile_view(){

}

tile_view::~tile_view(){

}

tile_view::tile_view(int Index)
    : tile::tile(Index)
{
    auto SpecificTarget = std::make_shared<sf::RectangleShape>();
    DrawTarget.push_back(SpecificTarget);
    this->IntRect = sf::Rect<int>(Position.x*10+(WindowWidth-GridWidth),Position.y*10,10,10);//magic numbers like in the view.
    SpecificTarget->setSize(sf::Vector2f(10, 10)); // will change magic numbers
    SpecificTarget->setPosition(((getPosition().x*10)+(WindowWidth-GridWidth)),getPosition().y*10);
    SpecificTarget->setFillColor(sf::Color::White);
    SpecificTarget->setOutlineColor(sf::Color::Black);
    SpecificTarget->setOutlineThickness(1);
    /*
    auto Text = std::make_shared<sf::Text>("0",*font);
    Text->setCharacterSize(8);
    Text->setFillColor(sf::Color::Black);
    Text->setStyle(sf::Text::Bold);
    Text->setPosition(((getPosition().x*10)+(WindowWidth-GridWidth)),getPosition().y*10);
    DrawTarget.push_back(Text);*/
}

