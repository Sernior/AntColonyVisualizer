#ifndef RENDERABLE
#define RENDERABLE
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
class Renderable{
    public:
        std::vector<std::shared_ptr<sf::Drawable>> DrawTarget;
        Renderable();
        ~Renderable();
        void render();
};


#endif