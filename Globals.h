#ifndef GLOBALS
#define GLOBALS
#include<memory>
#include <SFML/Graphics.hpp>
#include "Map.h"
extern int gridsize;
extern int gridsizeX;
extern int gridsizeY;
extern int WindowWidth;
extern int GridWidth;
extern int WindowHeight;
extern std::shared_ptr<sf::RenderWindow> window;
extern std::shared_ptr<Map> map;
#endif