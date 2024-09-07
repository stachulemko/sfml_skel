#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <../include/avatar_attacking.h>
using namespace std;
class Button
{
private:
    sf::RectangleShape buttonShape;
    bool mouseHeld = true;
    //--------------------------------

public:
    Button();
    Button(float x, float y, float width, float height, const sf::Color color);
    bool isClicked(const sf::Vector2i &mousePos, sf::Mouse::Button button);
    void render(sf::RenderWindow &rtwindow);
    void update(sf::Vector2i mousePos, std::vector<Avatar_attacking> &avatars);
};
