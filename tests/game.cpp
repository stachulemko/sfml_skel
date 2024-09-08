#include <../include/game.h>

Game::Game()
{
    window.create(sf::VideoMode(1200, 1000), "SFML works!");
    button = Button(50, 50, 100, 50, sf::Color::Green);
}

void Game::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
    }
    //sf::Time timeSinceLastShot = gameClock.getElapsedTime();
}

void Game::update()
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Time deltaTime = gameClock.restart();
    button.update(mousePos, avatars);
    // Aktualizacja awatarów - ruch, zatrzymanie itp.
    for (auto &avatar : avatars)
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
        {
            //cout << "right Button clicked - put avatar" << endl;
            if (avatar.isFollowing)
                //cout << "change folowina to false" << endl;
                avatar.isFollowing = false;
        }
        avatar.update(mousePos, avatar.isFollowing, bullets, deltaTime);
    }
    for (auto &bullet : bullets)
    {
        bullet.update(deltaTime);
    }
}
void Game::render()
{
    window.clear();
    button.render(window);
    for (auto &avatar : avatars)
    {
        avatar.render(window);
    }
    for (auto &bullet : bullets)
    {
        bullet.render(window);
    }
    this->window.display();
}

const sf::RenderWindow &Game::getWindow() const
{
    // TODO: insert return statement here
    return this->window;
}
