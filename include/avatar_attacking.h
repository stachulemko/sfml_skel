#include <iostream>
#include <./SFML/Graphics.hpp>
using namespace std;

class Avatar_attacking
{

private:
    sf::Sprite sprite;
    sf::Texture texture;

public:
    bool isFollowing;
    Avatar_attacking(float x, float y, bool isFollowing);
    void update(const sf::Vector2i &mousePos, bool isFollowing);
    void render(sf::RenderWindow &window);
    void update();
};