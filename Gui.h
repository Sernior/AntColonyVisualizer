#ifndef GUI
#define GUI
#include <SFML/Graphics.hpp>
#include "Renderable.h"
namespace Gui{


enum State
{
    StateDefault,
    StateHovered,
    StatePressed,
    StateFocused
};

class Button : public Renderable{
    public:
    std::string id;
    bool status;
    bool Click();
    Button();
    Button(int x, int y, int width, int height, std::string name);
    ~Button();
    private:

};

}
#endif