#include "TimeManager.h"
#include "Globals.h"

TimeManager::TimeManager(float TickDuration) {
    this->TickDuration = TickDuration;
    Tick = 0.0f;
    FPSTimer = 0.0f;
    FramesPerSecond = 0;
    totalTicks = 0;
    FiveSecondsTicker = 0.0f;
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
        menu->console.pushMessage(std::string("FPS :: ").append(std::to_string(FramesPerSecond)));
        FramesPerSecond = 0;
        oneSecondTick();
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
    //menu->console.pushMessage(std::string("tick :: ").append(std::to_string(FiveSecondsTicker)));
}
void TimeManager::TickSimulation() const{
}
