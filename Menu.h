#ifndef MENU_H
#define MENU_H
#include "Gui.h"
#include <SFML/Graphics.hpp>
#include "Renderable.h"
#include <vector>
#include <memory>
class Menu : public Renderable
{
public:
    Menu();
    ~Menu();
    void render();
    std::vector<std::shared_ptr<Gui::Button>> buttons;
};


#endif