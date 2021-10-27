#include "Menu.h"
#include "Globals.h"

Menu::Menu()
{
    State = MenuState::NothingSet;
    //this is the definition of the background of the menu
    auto SpecificTarget = std::make_shared<sf::RectangleShape>();
    DrawTarget.push_back(SpecificTarget);
    SpecificTarget->setSize(sf::Vector2f(MenuWidth, WindowHeight));
    SpecificTarget->setPosition(0,0);
    SpecificTarget->setFillColor(sf::Color::White);

    AddButton(20,20,40,20, "Wall",4);//0
    AddButton(80,20,40,20,"Clear",0);
}

Menu::~Menu() {
    
}

void Menu::AddButton(int x, int y, int width, int height, std::string name,int center){
    buttons.push_back(std::make_shared<Gui::Button>(x,y,width,height,name,center));
}
void Menu::render(){
    Renderable::render();
    for (auto& b : buttons){
        b->render();
    }
    //the rest of the menu's components rendering is done here.
}
bool containedIn(int x, int y, int startX, int startY, int Width, int Height){
    return x >= startX && x <= startX+Width && y >= startY && y <= startY+Height;
}
void Menu::NotifyLeftClick(int x, int y){
    if (containedIn(x,y,20,20,40,20)){ //Wall
        if(buttons[0]->Click()){
            State = MenuState::SettingWalls;
        }
        else{
            State = MenuState::NothingSet;
        }
    }
    if (containedIn(x,y,80,20,40,20)){ //Clear
        printf("clearning");
        map->ClearTiles();
    }
}
