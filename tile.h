#include <SFML/Graphics.hpp>
#ifndef TILE
#define TILE
class tile{
    private:
        sf::Vector2i Position;
        int Weight;
        bool Wall;
    public:
        tile(int index);
        tile();
        ~tile();
        sf::Vector2i getPosition();
        float getDistance(tile t); //calculate the distance from this to t
        float getDistanceSquared(tile t);
        int getWeight();
        bool isWall();
        //int to pos -> pos to int
};

#endif