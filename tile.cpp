#include "tile.h"
#include "Globals.h"
#include <cmath> 
tile::tile(int Index){
    this->Position.x = int(Index % gridsizeX);
    this->Position.y = int(Index / gridsizeX);
    this->Wall = false;
    this->Weight = 0;
}
tile::tile(){
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