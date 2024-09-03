#include <../include/control_panel.h>
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
Panel::Panel()
{
    sf::Image image;
    image.create(200, 1000, sf::Color::Blue);

    if (!texture.loadFromImage(image))
    {
        std::cout << "Can't load texture" << std::endl;
    }

    sprite.setTexture(texture);
    set_postion_control_panel(sprite);
}
void Panel::enter_elements(float size_x_, float size_y_)
{
    if (size_x_ != 0 and size_y_ != 0)
    {
        cout << "Error in control panel class eter elelemnts" << endl;
        size_x = size_x_;
        size_y = size_y_;
    }
}
/*
sf::Sprite Panel::control_panel()
{
    sf::Image image;
    image.create(size_x, size_y, sf::Color::Blue);
    texture.loadFromImage(image);
    return sprite;
}
*/
void Panel::set_postion_control_panel(sf::Sprite sprite)
{
    sprite.setPosition(1100, 500);
}
void Panel::render(sf::RenderWindow  &rt)
{
    rt.draw(sprite);
}
void Panel::update()
{
}
