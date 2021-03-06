#ifndef TIME
#define TIME
#include <SFML/Graphics.hpp>
#include "Dijkstra.h"
class TimeManager
{
private:
    float TickDuration;
    float Tick;
    int FramesPerSecond;
    float FPSTimer;
    float FiveSecondsTicker;
    int CurrentFood;
    int CurrentAnt;
    Dijkstra d;
public:
    int totalTicks;
    TimeManager(float TickDuration);
    ~TimeManager();
    void SetTickDuration(float newDuration);
    void Update(float delta);
    void TickSimulation();
    void fiveSecondsTick() const;
    void oneSecondTick() const;
    int getTick() const;
    void clear();
    bool isAnt(int Index) const;
    bool isFood(int Index) const;
};

#endif