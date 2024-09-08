#include <../include/button.h>

using namespace std;

Button::Button()
{
    buttonShape.setPosition(50, 500);
    buttonShape.setSize(sf::Vector2f(50, 50));
    buttonShape.setFillColor(sf::Color::Green);
}

Button::Button(float x, float y, float width, float height, const sf::Color color)
{
    buttonShape.setPosition(x, y);
    buttonShape.setSize(sf::Vector2f(width, height));
    buttonShape.setFillColor(color);
}

bool Button::isClicked(const sf::Vector2i &mousePosition, sf::Mouse::Button button)
{
    if (sf::Mouse::isButtonPressed(button))
    {
        if (buttonShape.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
        {
            return true;
        }
    }
    return false;
}

void Button::render(sf::RenderWindow &window)
{
    window.draw(buttonShape);
}

// Nowa metoda update, która zarządza logiką kliknięcia przycisku
void Button::update(sf::Vector2i mousePos, std::vector<Avatar_attacking> &avatars)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (!mouseHeld)
        {
            mouseHeld = true;

            // Jeśli przycisk został kliknięty, tworzymy nowy awatar
            if (isClicked(mousePos, sf::Mouse::Left))
            {
                //avatars.emplace_back(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y), true);
                Avatar_attacking a = Avatar_attacking(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y), true);
                avatars.push_back(a);
                avatars.back().isFollowing = true;
            }
        }
    }
    else
    {
        mouseHeld = false;
    }
}