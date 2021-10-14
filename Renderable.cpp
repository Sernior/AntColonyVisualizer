#include "Renderable.h"
#include "Globals.h"

Renderable::Renderable(){
}
Renderable::~Renderable(){
}

void Renderable::render() {
    window->draw(*DrawTarget);
}
