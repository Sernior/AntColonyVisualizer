#ifndef MENU_H
#define MENU_H
#include "Gui.h"
#include <SFML/Graphics.hpp>
#include "Renderable.h"
#include <vector>
#include <memory>
enum MenuState
{
    NothingSet,
    SettingWalls,
    SettingWeights,
    SettingColony,
    SettingFood
};
class Menu : public Renderable
{
public:
    Menu();
    ~Menu();
    void render();
    void AddButton(int x, int y, int width, int height,std::string name);
    void NotifyLeftClick(int x, int y);
    std::vector<std::shared_ptr<Gui::Button>> buttons;
    MenuState State;
};


#endif