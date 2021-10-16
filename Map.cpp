#include "Map.h"
#include "Globals.h"


Map::Map() {
    tilegrid.resize(gridsize);
    for(int i = 0; i != gridsize; i++){
        tilegrid[i] = tile_view(i);
        //RelativeTilePositionToIndex[tilegrid[i].Position] = i;
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

int Map::PositionToTileIndex(int x , int y){ // this can be greatly optimized

    int relx = ((int)(x-500)/10);
    int rely = (int)(y/10);
    return rely * gridsizeX + relx;
    printf("\n%d ,%d \n",relx,rely);


    for(int i = 0; i != gridsize; i++){
        if(tilegrid[i].IntRect.contains(x,y)){
            return i;
        }
    }
    return -1;
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

