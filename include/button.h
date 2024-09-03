#include <iostream>
#include <SFML/Graphics.hpp>
#include "avatar_atacking.h"
#include "bullet.h"
#include <vector>
using namespace std;
class Button
{
private:
    float poz_x;
    float poz_y;
    float width;
    float size;
    bool isMouseOverButton;
    sf::Sprite sprite;
    //sf::Sprite sprite_att;
    Avatar_atacking sprite_att;
    sf::Texture texture;
    bool click_flaga = true;
    vector<Avatar_atacking> vec;
    Avatar_atacking avatar_atacking; // Wskaźnik do Avatar_atacking
    Bullet bullet;

public:
    //bool zostawiony_att = false;
    Button();
    void enter_elements(float poz_x_, float poz_y_, float width, float size);
    void button_make();
    void set_postion_button();
    void update();
    void render(sf::RenderWindow &rtwindow);
    void mechanics(sf::RenderWindow &rtwindow);
    Avatar_atacking make_sprite_att();
    void mechanics_defender(sf::RenderWindow &window, sf::Sprite &sprite, bool &click_flaga);
};