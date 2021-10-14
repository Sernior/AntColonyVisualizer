#ifndef MAP
#define MAP
#include "tile_view.h"
#include <vector>
class Map{
    std::vector<tile_view> tilegrid;
    public:
        Map();
        ~Map();
        void render();
};
#endif