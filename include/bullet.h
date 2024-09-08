#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
class Bullet
{
private:
    float poz_x;
    float poz_y;
    float width = 10;
    float size = 10;
    static sf::Sprite sprite;
    static sf::Texture texture;
    sf::Clock clock;
    const float shotInterval = 0.5f;
    float speed_x = 20.0f;
    float speed_y = 0.0f;

public:
    Bullet(float x, float y);
    void update(sf::Time deltaTime);
    void render(sf::RenderWindow &window);
};