#include <iostream>
#include <SFML/Graphics.hpp>
#include <../include/button.h>
class Game
{

private:
    sf::RenderWindow window;
    sf::Event ev;
    sf::Vector2i mousePosition;
    Button button;
    std::vector<Avatar_attacking> avatars;
    std::vector<Bullet> bullets;
    sf::Clock gameClock;
    sf::Time timeSinceLastShot;
    sf::Time time;
    sf::Time deltaTime = gameClock.restart();

public:
    Game();
    void processEvents();
    void update();
    void render();
    const sf::RenderWindow &getWindow() const;
};