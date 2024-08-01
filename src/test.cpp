#include <SFML/Graphics.hpp>
using namespace std;
int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 400), "SFML works!");
    sf::Image image;
    image.create(50, 50, sf::Color::Red);
    sf::Texture texture;
    texture.loadFromImage(image);
    sf::Sprite sprite;
    sprite.setTexture(texture);
    int x = 275;
    int y = 175;
    sprite.setPosition(x, y);

    //std::vector<sf::Vertex> pixels;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    // Przesuwanie sprite'a
                    x -= 10;
                    y -= 10;
                    sprite.setPosition(x, y);
                }
            }
        }
        window.clear();
        //window.draw(shape);
        window.draw(sprite);
        // window.draw(&pixels[0], pixels.size(), sf::Points);
        window.display();
    }
    return 0;
}