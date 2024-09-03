#include <../include/Game.h>
int main()
{
    std::cout << "Hello" << std::endl;

    Game game;

    while (game.getWindow().isOpen())
    {
        game.update();
        game.render();
    }

    //End of application
    return 0;
}