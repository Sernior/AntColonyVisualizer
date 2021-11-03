#ifndef MENU_H
#define MENU_H
#include "Gui.h"
#include <SFML/Graphics.hpp>
#include "Renderable.h"
#include <vector>
#include <memory>
enum SimulationState{
    Simulating,
    NotSimulating,
    LoopSimulation
};
enum MapRenderingState{
    Rendering,
    NotRendering
};
enum MenuState
{
    NothingSet,
    SettingWalls,
    IncreasingWeights,
    DecreasingWeights,
    SettingColony,
    SettingFood
};
class Menu : public Renderable
{
public:
    Menu();
    ~Menu();
    void render();
    void AddButton(int x, int y, int width, int height,std::string name, int center);
    void NotifyLeftClick(int x, int y);
    void ResetButtons(std::string exclude);
    std::vector<std::shared_ptr<Gui::Button>> buttons;
    MenuState State;
    MapRenderingState MapRendering;
    SimulationState Simulationstate;
    Gui::Console console;
};


#endif