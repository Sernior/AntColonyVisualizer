#ifndef RENDERABLE
#define RENDERABLE
#include <SFML/Graphics.hpp>
#include <memory>
class Renderable{
    public:
        std::shared_ptr<sf::Drawable> DrawTarget;
        //sf::Drawable* DrawTarget;
        Renderable();
        ~Renderable();
        void render();
};


#endif