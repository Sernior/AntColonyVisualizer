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
    AddButton(80,20,40,20,"Clear",0);//1
    AddButton(140,20,95,20,"Add Weight",1);//2
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
void Menu::ResetButtons(std::string exclude){
    for(auto& b : buttons){
        if(b->id == exclude){
            continue;
        }
        if(b->status){
            b->Click();
        }
    }
}
void Menu::NotifyLeftClick(int x, int y){
    if (containedIn(x,y,20,20,40,20)){ //Wall
        State = MenuState::NothingSet;
        if(buttons[0]->Click()){
            ResetButtons("Wall");
            State = MenuState::SettingWalls;
        }
    }
    if (containedIn(x,y,80,20,40,20)){ //Clear
        map->ClearTiles();
    }
    if (containedIn(x,y,140,20,95,20)){ //IncreaseWeight
        State = MenuState::NothingSet;
        if(buttons[2]->Click()){
            ResetButtons("Add Weight");
            State = MenuState::IncreasingWeights;
        }
    }
}
