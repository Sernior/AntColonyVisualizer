#ifndef TILE_V
#define TILE_V
#include "tile.h"
#include "Renderable.h"
#include <SFML/Graphics.hpp>
class tile_view : public tile , public Renderable
{
    public:
        sf::Rect<int> IntRect;
        sf::RectangleShape rect;
        tile_view();
        tile_view(int Index);
        ~tile_view();
        bool operator==(const tile_view &other) const;
};
#endif