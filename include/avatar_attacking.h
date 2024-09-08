#include <iostream>
#include <cmath>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <../include/bullet.h>
using namespace std;

class Avatar_attacking
{

private:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Time accumulatedTime = sf::Time::Zero;
    const sf::Time createBulletInterval = sf::milliseconds(2000);

public:
    bool isFollowing;
    Avatar_attacking(float x, float y, bool isFollowing);
    void update(const sf::Vector2i &mousePos, bool isFollowing, std::vector<Bullet> &bullets, sf::Time deltaTime);
    void render(sf::RenderWindow &window);
    void update();
};