#include "tile.h"
#include "Globals.h"
#include <cmath> 
tile::tile(int Index){
    this->Index = Index;
    this->Position.x = int(Index % gridsizeX);
    this->Position.y = int(Index / gridsizeX);
    this->Wall = false;
    this->Weight = 0;
}
tile::tile(){// Index = y * gridsizeX + X
}
tile::~tile(){
}

sf::Vector2i tile::getPosition(){
    return this->Position;
}

float tile::getDistance(tile tile){
    return sqrt(getDistanceSquared(tile));
}

float tile::getDistanceSquared(tile tile){
    return pow(abs(tile.getPosition().x - this->getPosition().x),2) + pow(abs(tile.getPosition().y - this->getPosition().y),2);
}

int tile::getWeight(){
    return this->Weight;
}

bool tile::isWall(){
    return this->Wall;
}
void tile::Clear(){
    Wall = false;
    Weight = 0;
    isFoodSource = false;
    isColony = false;
}
void tile::IncreaseWeight(){
    if(Weight == 20){
        return;
    }
    Weight++;
}
void tile::DecreaseWeight(){
    if(Weight == 0){
        return;
    }
    Weight--;
}
std::vector<int> tile::Adj4(){
    std::vector<int> result;
    if(Position.x+1 <= 99 && Position.x+1 >=0){
        result.push_back(map->RelativePositionToTileIndex(this->Position.x+1,this->Position.y));
    }
    if(Position.x-1 <= 99 && Position.x-1 >=0){
        result.push_back(map->RelativePositionToTileIndex(this->Position.x-1,this->Position.y));
    }
    if(Position.y+1 <= 99 && Position.y+1 >=0){
        result.push_back(map->RelativePositionToTileIndex(this->Position.x,this->Position.y+1));
    }
    if(Position.y-1 <= 99 && Position.y-1 >=0){
        result.push_back(map->RelativePositionToTileIndex(this->Position.x,this->Position.y-1));
    }
    return result;
}