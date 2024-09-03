#include <iostream>
#include <./SFML/Graphics.hpp>
using namespace std;

class Avatar_atacking
{

private:
    vector<sf::Vector2f> vecp_att;
    float hp;
    float reload;
    float attack_value;
    float cost;
    float range;
    float x;
    float y;
    float speed_bullet_x;
    float speed_bullet_y;
    sf::Texture texture;
    sf::Sprite sprite;

public:
    Avatar_atacking();
    Avatar_atacking(float x, float y);
    void update();
    void enter_elelemnts(float hp, float reload, float attack_value, float cost, float range, float x, float y);
    sf::Sprite Avatar_atacking_sprite();
    void render(sf::RenderWindow &rtwindow);
    void shoting_machanics(float xd, float yd, float bullet_speed);
    bool check_sprite(float x, float y);
    bool sprite_destroy();
    void sprite_destroy_check(float hp2);
    sf::Sprite sprite_bullet();
    void bullet_movment(sf::Sprite &sprite, float delta);
    void set_position(float x, float y);
    sf::Sprite get_sprite();
};