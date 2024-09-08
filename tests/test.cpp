#include <../include/game.h>
int main()
{
    std::cout << "Hello" << std::endl;

    Game game;

    //while (isRunning)
    while (game.getWindow().isOpen())
    {
        game.processEvents();
        game.update();
        game.render();
    }

    //End of application
    return 0;
}