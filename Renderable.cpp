#include "Renderable.h"
#include "Globals.h"

Renderable::Renderable(){
}
Renderable::~Renderable(){
}

void Renderable::render() {
    for (auto& dt : DrawTarget){
        window->draw(*dt);
    }
}
