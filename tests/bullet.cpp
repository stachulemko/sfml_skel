#include <../include/bullet.h>
void Bullet::bullet_movment(float time)
{
    bullet.move(speed_x * time, speed_y * time);
}
void Bullet::render(sf::RenderWindow &rt)
{
    sf::Time time_m = clock.getElapsedTime();
    for (int i = 0; i < bullets.size(); i++)
    {
        bullets[i].move(speed_x * time_m.asSeconds(), speed_y * time_m.asSeconds());
        rt.draw(bullets[i]);
    }
}
void Bullet::bullet_texture()
{
    int radius = 1;
    int diameter = radius * 2;
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

    if (!texture.loadFromImage(image))
    {
        cout << "Can't load texture" << endl;
    }
    else
    {
        texture.loadFromImage(image);
    }
    bullet.setTexture(texture);
    // Tworzymy teksturę i przypisujemy do niej obraz
}

void Bullet::update()
{
    sf::Time timeSinceLastDamage = clock.getElapsedTime();

    if (timeSinceLastDamage.asSeconds() >= shotInterval)
    {
        // Upewnij się, że licznik nie przekroczy zakresu wektora
        cout << timeSinceLastDamage.asSeconds() << endl;
        cout << vecp_att.size() << endl;
        if (licznik < vecp_att.size())
        {
            cout << "sdasdasdasd" << endl;
            bullet.setPosition(vecp_att[licznik].x, vecp_att[licznik].y);
            bullets.push_back(bullet);
            licznik += 1;
        }
        clock.restart();
    }
}

void Bullet::add_element(float x, float y)
{
    sf::Vector2f point(x, y);
    vecp_att.push_back(point);
}
Bullet::Bullet()
{
    bullet_texture();
}
Bullet::Bullet(float x, float y, int deleay)
{
    poz_x = x;
    poz_y = y;
}