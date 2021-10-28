#include "TimeManager.h"


TimeManager::TimeManager(float TickDuration) {
    this->TickDuration = TickDuration;
    Tick = 0.0f;
    FPSTimer = 0.0f;
    FramesPerSecond = 0;
}

TimeManager::~TimeManager() {
    
}

void TimeManager::SetTickDuration(float newDuration) {
    this->TickDuration = newDuration;
}

void TimeManager::Update(float deltatime) {
    FramesPerSecond++;
    FPSTimer+=deltatime;
    Tick+=deltatime;
    if(FPSTimer>1.0f){
        FPSTimer = 0.0f;
        printf("FPS: %d-",FramesPerSecond);
        FramesPerSecond = 0;
        //this truly shows how costly the rendering of the map is for benchmarking purposes, an option to stop rendering the map is absolutly needed as all the results would be hidden
        // by the noise of the rendering complexity. Alternatively I could cap the fps at a very low number.
        // certain metrics like food found per nodes that are unrelated to real time could still be useful even if the complexity of the UI is loud.
    }
    if(Tick>TickDuration){ //only 1 Tick every TickDuration, TickDuration = 1.0f means 1 tick every 1 seconds.
        TickSimulation();
        Tick = 0.0f;
    }
}

void TimeManager::TickSimulation() const{
    
}
