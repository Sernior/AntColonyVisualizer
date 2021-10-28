#ifndef TIME
#define TIME
#include <SFML/Graphics.hpp>
class TimeManager
{
private:
    float TickDuration;
    float Tick;
    uint32_t FramesPerSecond;
    float FPSTimer;
public:
    TimeManager(float TickDuration);
    ~TimeManager();
    void SetTickDuration(float newDuration);
    void Update(float delta);
    void TickSimulation() const;
};

#endif