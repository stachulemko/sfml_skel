#include <../include/bullet.h>
Bullet::Bullet(float x, float y)
{

    sf::Image image;
    image.create(5, 5, sf::Color::Green); // Tworzy obraz wypełniony zielonym kolorem
    if (!texture.loadFromImage(image))    // Ładowanie tekstury bezpośrednio z obiektu sf::Image
    {
        cout << "Can't load texture" << endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
}
void Bullet::update(sf::Time deltaTime)
{
    //int milliseconds = clock.getElapsedTime().asMilliseconds();
    //if (milliseconds % 100 == 0)
    //accumulatedTime += deltaTime;
    float offset = deltaTime.asMicroseconds();
    //cout << offset << endl;
    sprite.move(0.0001f * offset, 0.0001f * offset);
    //accumulatedTime = sf::Time::Zero;
}
void Bullet::render(sf::RenderWindow &window)
{
    window.draw(sprite);
}