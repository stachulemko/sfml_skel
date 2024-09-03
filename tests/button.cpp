#include <../include/button.h>
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

Button::Button()
{
    poz_x = 50;  // Ustawienie pozycji X
    poz_y = 500; // Ustawienie pozycji Y
    width = 50;  // Ustawienie szerokości przycisku
    size = 50;
    std::cout << "Button position: (" << poz_x << ", " << poz_y << ") - size: (" << width << ", " << size << ")\n";
    button_make();
    //make_sprite_att();
    set_postion_button();
}

void Button::button_make()
{
    sf::Image image;
    cout << this->width << " " << this->size << endl;
    image.create(this->width, this->size, sf::Color::Green);
    texture.loadFromImage(image);
    sprite.setTexture(texture);
}
void Button::set_postion_button()
{
    sprite.setPosition(poz_x, poz_y);
}
void Button::make_sprite_att()
{
    //sprite_att = avatar_atacking.Avatar_atacking_sprite();
    sprite_att = Avatar_atacking();
}

void Button::mechanics(sf::RenderWindow &rt)
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition(rt);
    isMouseOverButton = (mousePosition.x >= poz_x && mousePosition.x <= poz_x + width &&
                         mousePosition.y >= poz_y && mousePosition.y <= poz_y + size);

    if (isMouseOverButton)
    {
        sprite.setColor(sf::Color::Red);

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            click_flaga = false;
        }
    }
    else
    {
        sprite.setColor(sf::Color::Green);
    }

    if (!click_flaga)
    {
        //cout << "Kliknięto przycisk!" << endl;
        sprite_att.setPosition(mousePosition.x, mousePosition.y);
        rt.draw(sprite_att);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
        {
            vec.push_back(sprite_att);
            bullet.add_element(mousePosition.x, mousePosition.y);
            click_flaga = true;
        }
    }
}

void Button::render(sf::RenderWindow &rt)
{
    mechanics(rt);
    rt.draw(sprite);
    for (int i = 0; i < vec.size(); i++)
    {
        ///cout << vec.size() << endl;
        rt.draw(vec[i]);
    }
}

void Button::mechanics_defender(sf::RenderWindow &window, sf::Sprite &sprite, bool &click_flaga2)
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    bool isMouseOverButton = (mousePosition.x >= poz_x && mousePosition.x <= poz_x + width &&
                              mousePosition.y >= poz_y && mousePosition.y <= poz_y + size);

    if (isMouseOverButton)
    {
        sprite.setColor(sf::Color::Red);

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            click_flaga2 = false;
        }
    }
    else
    {
        sprite.setColor(sf::Color::Green);
    }
    //cout << click_flaga2 << endl;
}

void Button::update()
{
}