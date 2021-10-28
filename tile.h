#ifndef TILE
#define TILE
#include <SFML/Graphics.hpp>
class tile{
    private:
    public:
        uint32_t Index;
        sf::Vector2i Position;
        int Weight;
        bool Wall;
        bool isColony;
        bool isFoodSource;
        tile(int index);
        tile();
        ~tile();
        sf::Vector2i getPosition();
        float getDistance(tile t); //calculate the distance from this to t
        float getDistanceSquared(tile t);
        int getWeight();
        bool isWall();
        void Clear();
        void IncreaseWeight();
        void DecreaseWeight();
        //int to pos -> pos to int
};

#endif