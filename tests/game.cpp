#include <../include/game.h>
Game::Game()
{
    this->window.create(sf::VideoMode(1200, 1000), "SFML works!");
    //this->testsprite.setTextureRect(sf::IntRect(100, 100, 320, 320));
    //this->testsprite.setColor(sf::Color(0, 255, 0));
    /*this->testsprite.setPosition(100, 100);
    if (!texture.loadFromFile("./textures/ship.png"))
    {
        cout << "Can't load texture" << endl;
    }
    this->testsprite.setTexture(texture);
    this->testsprite.scale(0.1f, 0.1f);*/
    //sf::RenderWindow window(sf::VideoMode(1200, 1000), "SFML works!");
}

void Game::update()
{
    while (this->window.pollEvent(this->ev))
    {
        if (this->ev.type == sf::Event::Closed)
            this->window.close();
        else if (this->ev.type == sf::Event::KeyPressed && this->ev.key.code == sf::Keyboard::Escape)
            this->window.close();
    }
    //avatar_atacking.update();
    control_panel.update();
    button.update();
    //bullet.update();
}

const sf::RenderWindow &Game::getWindow() const
{
    // TODO: insert return statement here
    return this->window;
}

void Game::render()
{
    this->window.clear();
    this->avatar_atacking.render(this->window);
    this->control_panel.render(this->window);
    this->button.render(this->window);
    //this->bullet.render(this->window);
    //cout << "draw" << endl;
    //this->renderTileMap();
    //this->renderPlayer();
    //this->window.draw(testsprite);
    this->window.display();
}
