#include "Map.h"
#include "Globals.h"


Map::Map() {
    tilegrid.resize(gridsize);
    for(int i = 0; i != gridsize; i++){
        tilegrid[i] = tile_view(i);
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

    int relx = ((int)(x-500)/10);
    int rely = (int)(y/10);
    return rely * gridsizeX + relx;
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

