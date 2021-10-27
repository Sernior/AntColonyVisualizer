#ifndef GLOBALS
#define GLOBALS
#include<memory>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "Menu.h"
#include "Map.h"
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
#endif