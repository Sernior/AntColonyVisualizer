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
    SpecificTarget->setOutlineColor(sf::Color(120,120,120,80));
    SpecificTarget->setOutlineThickness(1);

    set_thisCycle = false;
}
void tile_view::SetWall(){//the left mouse button cycle currently only works for walls
    if(set_thisCycle){
        return;
    }
    set_thisCycle = true;
    if(Wall){
        Wall = false;
        return;
    }
    Wall = true;
    isColony = false;
    isFoodSource = false;
}
void tile_view::SetColony(){
    if(set_thisCycle){
        return;
    }
    set_thisCycle = true;
    isColony = !isColony;
    if(isColony){
        Wall = false;
        isFoodSource = false;
        Colony.push_back(Index);
        return;
    }
    remove(Colony.begin(),Colony.end(),Index);
    Colony[Index] = isColony;

}
void tile_view::SetFoodSource(){
    if(set_thisCycle){
        return;
    }
    set_thisCycle = true;
    isFoodSource = !isFoodSource;
    if(isFoodSource){
        Wall = false;
        isColony = false;
        FoodSources.push_back(Index);
        return;
    }
    remove(FoodSources.begin(),FoodSources.end(),Index);
    FoodSources[Index] = isFoodSource;
}
void tile_view::Click(){
    switch(menu->State){
        case(MenuState::SettingWalls):
            SetWall();
            break;
        case(MenuState::IncreasingWeights):
            IncreaseWeight();
            break;
        case(MenuState::DecreasingWeights):
            DecreaseWeight();
            break;
        case(MenuState::SettingColony):
            SetColony();
            break;
        case(MenuState::SettingFood):
            SetFoodSource();
            break;
        default:
            return;
    }
}

void tile_view::render(){
    auto SpecificTarget = std::dynamic_pointer_cast<sf::RectangleShape>(DrawTarget.front());
    SpecificTarget->setFillColor(WeightColors[Weight]);
    if(isFoodSource){
        SpecificTarget->setFillColor(sf::Color(0,255,0,100));
        Renderable::render();
        return;
    }
    if(isColony){
        SpecificTarget->setFillColor(sf::Color(255,0,0,100));
        Renderable::render();
        return;
    }
    if(Wall){
        SpecificTarget->setFillColor(sf::Color::Black);
        Renderable::render();
        return;
    }
    if(map->isPath(Index)){
        SpecificTarget->setFillColor(sf::Color::Cyan);
        Renderable::render();
        return;
    }
    if(map->isFound(Index)){
        SpecificTarget->setFillColor(sf::Color::Magenta);
        Renderable::render();
        return;
    }
    Renderable::render();
}
