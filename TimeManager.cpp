#include "TimeManager.h"
#include "Globals.h"

TimeManager::TimeManager(float TickDuration) {
    this->TickDuration = TickDuration;
    Tick = 0.0f;
    FPSTimer = 0.0f;
    FramesPerSecond = 0;
    totalTicks = 0;
    FiveSecondsTicker = 0.0f;
    CurrentFood = -1;
    CurrentAnt = -1;
}

TimeManager::~TimeManager() {
    
}

void TimeManager::SetTickDuration(float newDuration) {
    this->TickDuration = newDuration;
}

void TimeManager::Update(float deltatime) {
    FramesPerSecond++;
    FiveSecondsTicker+=deltatime;
    FPSTimer+=deltatime;
    Tick+=deltatime;
    if(FPSTimer>1.0f){
        FPSTimer = 0.0f;
        oneSecondTick();
        FramesPerSecond = 0;
    }
    if(FiveSecondsTicker>5.0f){
        FiveSecondsTicker = 0.0f;
        fiveSecondsTick();
    }
    if(Tick>TickDuration){ //only 1 Tick every TickDuration, TickDuration = 1.0f means 1 tick every 1 seconds.
        totalTicks++;
        TickSimulation();
        Tick = 0.0f;
    }
}
void TimeManager::fiveSecondsTick() const{
    //printf(" 5sec tick! ");
}
void TimeManager::oneSecondTick() const{
    //menu->console.pushMessage(std::string("FPS :: ").append(std::to_string(FramesPerSecond)));
}
void TimeManager::TickSimulation(){
    if(menu->Simulationstate == SimulationState::Simulating || menu->Simulationstate == SimulationState::LoopSimulation){
        if (!d.isInit())
        {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> distr(0, FoodSources.size()-1);
            CurrentFood = FoodSources[distr(gen)];
            std::random_device rd1;
            std::mt19937 gen1(rd1());
            std::uniform_int_distribution<> distr1(0, Colony.size()-1);
            CurrentAnt = Colony[distr1(gen1)];
            d.Clear();
            d.init(CurrentAnt,CurrentFood);
            map->NotifyPathFound();
        }
        if(d.Step()){
            menu->console.pushMessage("FOUND!");
            d.RenderPath();
            d.inited = false;
            if(menu->Simulationstate == SimulationState::Simulating){
                 menu->Simulationstate = SimulationState::NotSimulating;
            }
        }
    }
}
void TimeManager::clear(){
    d.Clear();
    CurrentAnt=-1;
    CurrentFood=-1;
}
int TimeManager::getTick() const{
    return totalTicks;
}
bool TimeManager::isAnt(int Index) const{
    return Index == CurrentAnt;
}
bool TimeManager::isFood(int Index) const{
    return Index == CurrentFood;
}