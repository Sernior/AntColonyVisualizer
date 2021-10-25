#ifndef MAP
#define MAP
#include "tile_view.h"
#include <vector>
#include <SFML/Graphics.hpp>
class Map{
    private:
        std::vector<tile_view> tilegrid;
        //std::unordered_map<sf::Vector2i,int> RelativeTilePositionToIndex;
        tile_view IndexToTile(int index);
    public:
        Map();
        ~Map();
        void render();
        void SetWall(int Index);
        void SetWeight(int Index, int Weight);
        int PositionToTileIndex(int x,int y);
        void NotifyLeftClick(int x, int y);
        void NotifyLeftRelease();
};
#endif