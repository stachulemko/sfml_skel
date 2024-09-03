#include <../include/avatar_atacking.h>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <SFML/Graphics.hpp>
using namespace std;

Avatar_atacking::Avatar_atacking()
{
    //Avatar_atacking::sprite = Avatar_atacking_sprite();
}
Avatar_atacking::Avatar_atacking(float x, float y)
{
    Avatar_atacking::sprite = Avatar_atacking_sprite();
    this->x = x;
    this->y = y;
}

void Avatar_atacking::enter_elelemnts(float hp_, float reload_, float attack_value_, float cost_, float range_, float x_, float y_)
{
    if (hp_ != 0 and reload_ != 0 and attack_value_ != 0 and cost_ != 0 and range_ != 0 and x_ != 0 and y_ != 0)
    {
        hp = hp_;
        reload = reload_;
        attack_value = attack_value_;
        cost = cost_;
        range = range_;
        x = x_;
        y = y_;
    }
    else
    {
        cout << "ERROR WHILE ENTERING ELEMENTS TO (AvatarAttacking)" << endl;
    }
}
sf::Sprite Avatar_atacking::Avatar_atacking_sprite()
{
    if (!texture.loadFromFile("./textures/ship.png"))
    {
        cout << "Can't load texture" << endl;
    }
    //sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.scale(0.1f, 0.1f);
    return sprite;
}

bool Avatar_atacking::check_sprite(float xd, float yd)
{
    float distance = sqrt((xd - x) * (xd - x) + (yd - y) * (yd - y)); // Użyj + zamiast -
    if (distance <= range)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Avatar_atacking::sprite_destroy()
{
    hp = hp - attack_value;
    if (hp <= 0)
    {
        return true;
    }
}
void Avatar_atacking::sprite_destroy_check(float hp2)
{
    hp2 = hp2 - attack_value;
    cout << hp2 << endl;
}
void Avatar_atacking::shoting_machanics(float xd, float yd, float bullet_speed)
{
    float x_r = abs((xd - x));
    float y_r = abs((yd - y));
    float suma = x_r + y_r;
    float speed_x = (x_r / suma) * bullet_speed;
    float speed_y = (y_r / suma) * bullet_speed;
    speed_bullet_x = speed_x;
    speed_bullet_y = speed_y;
}
sf::Sprite Avatar_atacking::sprite_bullet()
{
    int radius = 1; // Promień kuli
    int diameter = radius * 2;

    // Tworzymy obraz o wymiarach średnicy kuli
    sf::Image image;
    image.create(diameter, diameter, sf::Color::Transparent);

    // Rysowanie kuli na obrazie
    for (int y = 0; y < diameter; ++y)
    {
        for (int x = 0; x < diameter; ++x)
        {
            int dx = x - radius;
            int dy = y - radius;
            if (dx * dx + dy * dy <= radius * radius)
            {
                image.setPixel(x, y, sf::Color::Red);
            }
        }
    }

    // Tworzymy teksturę i przypisujemy do niej obraz
    sf::Texture texture;
    texture.loadFromImage(image);

    // Tworzymy sprite i przypisujemy do niej teksturę
    sf::Sprite sprite;
    sprite.setTexture(texture);

    return sprite;
}

void Avatar_atacking::bullet_movment(sf::Sprite &sprite, float delta)
{
    sprite.move(speed_bullet_x * delta, speed_bullet_y * delta);
}
void Avatar_atacking::render(sf::RenderWindow &rt)
{
    //cout << "asdasddasdadsadad" << endl;
    sf::CircleShape shape(50);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(500, 500);
    //rt.draw(shape);

    sprite.setColor(sf::Color::Red);
    sprite.setPosition(500, 500);
    rt.draw(sprite);
}
void Avatar_atacking::update()
{
}

void Avatar_atacking::render()
{
    sprite.setPosition(this.x, this.y);
    this.sprite.draw();
}

void set_position(float x, float y)
{
    this->x = x;
    this->y = y;
}
