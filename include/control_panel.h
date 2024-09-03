#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
class Panel
{
private:
    float size_x;
    float size_y;
    sf::Sprite sprite;
    sf::Texture texture;

public:
    void enter_elements(float size_x_, float size_y_);
    sf::Sprite control_panel();
    void set_postion_control_panel(sf::Sprite sprite);
    Panel();
    void render(sf::RenderWindow  &rtwindow);
    void update();
};