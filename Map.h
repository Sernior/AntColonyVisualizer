#ifndef MAP
#define MAP
#include "tile_view.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include <random>
#include<unordered_map>
class Map{
    private:
        std::vector<tile_view> tilegrid;
        std::unordered_map<int,bool> found;
        tile_view IndexToTile(int index);
    public:
        Map();
        ~Map();
        void render();
        void SetWall(int Index);
        void SetWeight(int Index, int Weight);
        int PositionToTileIndex(int x,int y);
        int PositionToTileIndex(sf::Vector2i pos);
        int RelativePositionToTileIndex(int x, int y);
        void NotifyLeftClick(int x, int y);
        void NotifyLeftRelease();
        void ClearTiles();
        void NotifyTileFound(int index);
        void RandomizeWeights();
        std::vector<int> Adj4(int index);
        int GetWeight(int index);
        bool isFound(int index);
};
#endif