#include "Globals.h"
int WindowWidth = 1500; // 1500
int WindowHeight = 1000; // 1000
int MenuWidth = 500; // 500
int GridWidth = 1000; // 1000
int gridsizeX = 100;  // 100
int gridsizeY = 100;  // 100
int gridsize;  //  gridsizeX * gridsizeY
std::shared_ptr<Menu> menu(nullptr); // the tile_view grid
std::shared_ptr<Map> map(nullptr); // the tile_view grid
std::shared_ptr<sf::RenderWindow> window(nullptr);
std::shared_ptr<sf::Font> font(nullptr);
std::unordered_map<int,sf::Color> WeightColors;