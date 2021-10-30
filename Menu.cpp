#include "Menu.h"
#include "Globals.h"

Menu::Menu()
{
    State = MenuState::NothingSet;
    MapRendering = MapRenderingState::Rendering;
    Simulationstate = SimulationState::NotSimulating;
    console = Gui::Console();
    //this is the definition of the background of the menu
    auto SpecificTarget = std::make_shared<sf::RectangleShape>();
    DrawTarget.push_back(SpecificTarget);
    SpecificTarget->setSize(sf::Vector2f(MenuWidth, WindowHeight-200));
    SpecificTarget->setPosition(0,0);
    SpecificTarget->setFillColor(sf::Color::White);

    AddButton(20,20,40,20, "Wall",4);//0
    AddButton(20,200,40,20,"Clear",1);//1
    AddButton(80,20,95,20,"Add Weight",1);//2
    AddButton(195,20,135,20,"Decrease Weight",1);//3
    AddButton(20,60,155,20, "Randomize Weights",1);//4
    AddButton(20,240,95,20,"Render Map",1);//5
    AddButton(20,100,105,20,"Make Colony",1);//6
    AddButton(155,100,95,20,"Make Food",1);//7
    AddButton(20,660,85,20,"Simulating",1);//8
    AddButton(155,660,135,20,"Stop Simulating",1);//9
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
    console.render();
    //the rest of the menu's components rendering is done here.
}
bool containedIn(int x, int y, int startX, int startY, int Width, int Height){//utility function to determine where the click was
    return x >= startX && x <= startX+Width && y >= startY && y <= startY+Height;
}
void Menu::ResetButtons(std::string exclude){
    for(auto& b : buttons){
        if(b->id == exclude || b->id == "Render Map"){
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
    if (containedIn(x,y,20,200,40,20)){ //Clear
        Colony.clear();
        FoodSources.clear();
        map->ClearTiles();
    }
    if (containedIn(x,y,80,20,95,20)){ //IncreaseWeight
        State = MenuState::NothingSet;
        if(buttons[2]->Click()){
            ResetButtons("Add Weight");
            State = MenuState::IncreasingWeights;
        }
    }
    if (containedIn(x,y,195,20,135,20)){//DecreaseWeight
        State = MenuState::NothingSet;
        if(buttons[3]->Click()){
            ResetButtons("Decrease Weight");
            State = MenuState::DecreasingWeights;
        }
    }
    if (containedIn(x,y,20,60,155,20)){//RandomizeWeights
        map->RandomizeWeights();
    }
    if (containedIn(x,y,20,240,95,20)){//Render Map
        MapRendering = !buttons[5]->Click()? MapRenderingState::Rendering : MapRenderingState::NotRendering; 
    }
    if (containedIn(x,y,20,100,105,20)){
        State = MenuState::NothingSet;
        if(buttons[6]->Click()){
            ResetButtons("Make Colony");
            State = MenuState::SettingColony;
        }
    }
    if (containedIn(x,y,155,100,95,20)){
        State = MenuState::NothingSet;
        if(buttons[7]->Click()){
            ResetButtons("Make Food");
            State = MenuState::SettingFood;
        }
    }
    if (containedIn(x,y,20,660,85,20)){
        if(Simulationstate == SimulationState::Simulating)return;
        Simulationstate = SimulationState::Simulating;
        console.pushMessage(std::string("Starting the simulation at Tick ").append(std::to_string(timeManager->totalTicks)));
    }
    if (containedIn(x,y,155,660,135,20)){
        if(Simulationstate == SimulationState::NotSimulating)return;
        Simulationstate = SimulationState::NotSimulating;
        console.pushMessage(std::string("Ending the simulation at Tick ").append(std::to_string(timeManager->totalTicks)));
    }
}
