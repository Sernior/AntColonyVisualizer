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
    DrawTarget = std::make_shared<sf::RectangleShape>();
    auto SpecificTarget = std::dynamic_pointer_cast<sf::RectangleShape>(DrawTarget);
    this->IntRect = sf::Rect<int>(Position.x*10+(WindowWidth-GridWidth),Position.y*10,10,10);//magic numbers like in the view.
    
    SpecificTarget->setSize(sf::Vector2f(10, 10)); // will change magic numbers
    SpecificTarget->setPosition(((getPosition().x*10)+(WindowWidth-GridWidth)),getPosition().y*10);
    SpecificTarget->setFillColor(sf::Color::White);
    SpecificTarget->setOutlineColor(sf::Color::Black);
    SpecificTarget->setOutlineThickness(1);

}

