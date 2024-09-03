#include <iostream>
#include <SFML/Window.hpp>
#include <control_panel.h>
#include <button.h>
class Game
{
private:
    sf::RenderWindow window;
    sf::Event ev;
    Avatar_atacking avatar_atacking;
    Button button;
    //Bullet bullet;
    Panel control_panel;
    //sf::Sprite testsprite;
    //sf::Texture texture;

public:
    void update();
    const sf::RenderWindow &getWindow() const;
    void render();
    Game();
};