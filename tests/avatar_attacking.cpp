#include <../include/avatar_attacking.h>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

using namespace std;

Avatar_attacking::Avatar_attacking(float x, float y, bool isFollowing)
{

    if (!texture.loadFromFile("./ship.png"))
    {
        cout << "Can't load texture" << endl;
    }
    sprite.setTexture(texture);
    sprite.scale(0.1f, 0.1f);
    sprite.setPosition(x, y);
}

void Avatar_attacking::update(const sf::Vector2i &mousePos, bool isFollowing)
{
    if (isFollowing)
    {
        sprite.setPosition(mousePos.x, mousePos.y);
        //cout << "Set position " << mousePos.x << endl;
    }
}

void Avatar_attacking::render(sf::RenderWindow &window)
{
    window.draw(sprite);
}
