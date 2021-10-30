#ifndef GLOBALS
#define GLOBALS
#include<memory>
#include <SFML/Graphics.hpp>
#include <vector>
#include <unordered_map>
#include "Menu.h"
#include "Map.h"
#include "TimeManager.h"
extern int gridsize;
extern int gridsizeX;
extern int gridsizeY;
extern int WindowWidth;
extern int GridWidth;
extern int WindowHeight;
extern int MenuWidth;
extern std::shared_ptr<sf::RenderWindow> window;
extern std::shared_ptr<Map> map;
extern std::shared_ptr<Menu> menu;
extern std::shared_ptr<sf::Font> font;
extern std::unordered_map<int,sf::Color> WeightColors;
extern std::shared_ptr<TimeManager> timeManager;
extern std::vector<int> Colony;
extern std::vector<int> FoodSources;
#endif