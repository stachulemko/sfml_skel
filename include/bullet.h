#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
using namespace std;
class Bullet
{
private:
        vector<float> vecp;
    sf::Texture texture;
    float speed_x = 20.0f;
    float speed_y = 0.0f;
    float shotInterval = 0.5f;
    int licznik = 0;
    vector<sf::Sprite> bullets;
    sf::Sprite bullet;
    sf::Clock clock;
    float width;
    float poz_x;
    float poz_y;
    float size;
    int deleay;

public:
    void bullet_movment(float time);
    void render(sf::RenderWindow &rt);
    void update();
    void bullet_texture();
    Bullet();
    Bullet(float x, float y, int delay);
    void add_element(float x, float y);
};