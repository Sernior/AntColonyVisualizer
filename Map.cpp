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
