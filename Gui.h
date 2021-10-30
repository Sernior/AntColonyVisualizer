#ifndef GUI
#define GUI
#include <SFML/Graphics.hpp>
#include <deque>
#include "Renderable.h"

namespace Gui{


enum State
{
    StateDefault,
    StateHovered,
    StatePressed,
    StateFocused
};
class Console: public Renderable{
    public:
    std::deque<std::string> messages;
    Console();
    ~Console();
    void pushMessage(std::string message);
    void render();
};
class Button : public Renderable{
    public:
    std::string id;
    bool status;
    bool Click();
    Button();
    Button(int x, int y, int width, int height, std::string name, int center);
    ~Button();
    private:

};

}
#endif