#include "Map.h"
#include "Globals.h"

Map::Map() {
    tilegrid.resize(gridsize);
    for(int i = 0; i != gridsize; i++){
        tilegrid[i] = tile_view(i);
        found[i]=false;
    }
}

Map::~Map() {
}

void Map::render() {
    for(int i = 0; i != gridsize; i++){
        tilegrid[i].render();
    }
}

tile_view Map::IndexToTile(int Index){
    return tilegrid[Index];
}

int Map::PositionToTileIndex(int x , int y){

    int relx = ((int)(x-MenuWidth)/10);
    int rely = (int)(y/10);
    return rely * gridsizeX + relx;
}
int PositionToTileIndex(sf::Vector2i pos){
    int relx = ((int)(pos.x-MenuWidth)/10);
    int rely = (int)(pos.y/10);
    return rely * gridsizeX + relx;
}
int Map::RelativePositionToTileIndex(int x, int y){
    return y * gridsizeX + x;
}
void Map::SetWall(int Index){
    if(tilegrid[Index].Wall){
        tilegrid[Index].Wall = false;
        return;
    }
    tilegrid[Index].Wall = true;
}

void Map::SetWeight(int Index, int Weight){
    tilegrid[Index].Weight = Weight;
}

void Map::NotifyLeftClick(int x, int y){
    int tileIndex = PositionToTileIndex(x,y);
    tilegrid[tileIndex].Click();
}
void Map::NotifyLeftRelease(){
    for(auto& t : tilegrid){
        t.set_thisCycle = false;
    }
}
void Map::ClearTiles(){
    found.clear();
    for(auto& t : tilegrid){
        t.Clear();
    }
}
void Map::RandomizeWeights(){
    for(auto& t : tilegrid){
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distr(0, 20);
        t.Weight = distr(gen);
    }
}
std::vector<int> Map::Adj4(int index){
    return IndexToTile(index).Adj4();
}
int Map::GetWeight(int index){
    return IndexToTile(index).getWeight();
}
void Map::NotifyTileFound(int index){
    found[index]=true;
}
bool Map::isFound(int index){
    return found[index];
}