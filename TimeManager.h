#ifndef TIME
#define TIME
#include <SFML/Graphics.hpp>
#include "Dijkstra.h"
class TimeManager
{
private:
    float TickDuration;
    float Tick;
    uint32_t FramesPerSecond;
    float FPSTimer;
    float FiveSecondsTicker;
    int CurrentFood;
    int CurrentAnt;
    Dijkstra d;
public:
    uint64_t totalTicks;
    TimeManager(float TickDuration);
    ~TimeManager();
    void SetTickDuration(float newDuration);
    void Update(float delta);
    void TickSimulation();
    void fiveSecondsTick() const;
    void oneSecondTick() const;
};

#endif