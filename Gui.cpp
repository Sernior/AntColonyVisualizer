#include "Gui.h"
#include "Globals.h"
Gui::Button::Button(){

}

Gui::Button::Button(int x, int y, int width, int height, std::string name, int center) {
    id = name;
    status = false;

    auto SpecificTarget = std::make_shared<sf::RectangleShape>();
    DrawTarget.push_back(SpecificTarget);
    SpecificTarget->setSize(sf::Vector2f(width, height));
    SpecificTarget->setPosition(x,y);
    SpecificTarget->setFillColor(sf::Color::White);
    SpecificTarget->setOutlineColor(sf::Color::Black);
    SpecificTarget->setOutlineThickness(1);

    auto Text = std::make_shared<sf::Text>(name ,*font);
    Text->setCharacterSize(19);
    Text->setFillColor(sf::Color::Black);
    Text->setStyle(sf::Text::Bold);
    Text->setPosition(x+center,y-2);
    DrawTarget.push_back(Text);
}

Gui::Button::~Button() {
    
}
bool Gui::Button::Click() {
    auto SpecificTarget = std::dynamic_pointer_cast<sf::RectangleShape>(DrawTarget.front());
    if(!status){
        status = true;
        SpecificTarget->setFillColor(sf::Color::Yellow);
    }
    else{
        status = false;
        SpecificTarget->setFillColor(sf::Color::White);
    }
    return status;
}
int relXconsole(int x){
    return x;
}
int relYconsole(int y){
    return y+800;
}
Gui::Console::Console(){

}
Gui::Console::~Console(){

}
void Gui::Console::pushMessage(std::string message){
    messages.push_front(message);
    while(messages.size()>10){
        messages.pop_back();
    }
}
void Gui::Console::render(){
    int i = 0;
    DrawTarget.clear();
    for (auto& m : messages){
        auto Text = std::make_shared<sf::Text>(m ,*font);
        Text->setCharacterSize(18);
        Text->setFillColor(sf::Color::White);
        Text->setStyle(sf::Text::Italic);
        Text->setPosition(relXconsole(10),relYconsole(i));
        DrawTarget.push_back(Text);
        i+=20;
    }
    Renderable::render();
}