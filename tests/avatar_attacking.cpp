#include <../include/avatar_attacking.h>

using namespace std;

Avatar_attacking::Avatar_attacking(float x, float y, bool isFollowing)
{
    cout << "create avatar" << endl;
    if (!texture.loadFromFile("C:/dev/gamedev/sfml_init3/textures/ship.png"))
    {
        cout << "Can't load texture" << endl;
    }
    sprite.setTexture(texture);
    sprite.scale(0.05f, 0.05f);
    sprite.setPosition(x, y);
}

void Avatar_attacking::update(const sf::Vector2i &mousePos, bool isFollowing, std::vector<Bullet> &bullets, sf::Time deltaTime)
{

    //int milliseconds = gameClock.getElapsedTime().asMilliseconds();
    if (isFollowing)
    {
        sprite.setPosition(mousePos.x, mousePos.y);
        //cout << "Set position " << mousePos.x << endl;
    }
    else
    {
        accumulatedTime += deltaTime;
        //if (milliseconds % 5000 == 0)
        //cout << accumulatedTime.asSeconds() << "::" << createBulletInterval.asSeconds() << endl;
        if (accumulatedTime >= createBulletInterval)
        {
            //cout << "dodanie Bulleta" << endl;
            sf::Vector2f position = sprite.getPosition();
            Bullet b = Bullet(position.x, position.y);
            bullets.push_back(b);
            accumulatedTime = sf::Time::Zero;
        }
    }
}

void Avatar_attacking::render(sf::RenderWindow &window)
{
    window.draw(sprite);
}
