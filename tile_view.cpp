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

    set_thisCycle = false;
}
void tile_view::SetWall(){
    auto SpecificTarget = std::dynamic_pointer_cast<sf::RectangleShape>(DrawTarget.front());
    if(set_thisCycle){
        return;
    }
    set_thisCycle = true;
    if(Wall){
        Wall = false;
        SpecificTarget->setFillColor(sf::Color::White);
        return;
    }
    Wall = true;
    SpecificTarget->setFillColor(sf::Color::Black);
}
void tile_view::Click(){
    switch(menu->State){
        case(MenuState::SettingWalls):
            SetWall();
            break;
        default:
            return;
    }
}
