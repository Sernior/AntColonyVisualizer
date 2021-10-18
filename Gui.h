#ifndef GUI
#define GUI
#include <SFML/Graphics.hpp>
#include "Renderable.h"
//#include "Globals.h"
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
    Button();
    Button(int x, int y, int width, int height);
    ~Button();
    private:

};

}
#endif