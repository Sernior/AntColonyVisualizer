#ifndef TILE_V
#define TILE_V
#include "tile.h"
#include "Renderable.h"
#include <SFML/Graphics.hpp>
class tile_view : public tile , public Renderable
{
    public:
        sf::Rect<int> IntRect;
        bool set_thisCycle;
        //sf::RectangleShape rect;
        tile_view();
        tile_view(int Index);
        ~tile_view();
        void Click();
        void SetWall();
        void SetColony();
        void SetFoodSource();
        void render();
};
#endif