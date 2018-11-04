#include "gameoflife.h"
#include <unistd.h>

int main()
{
    GameOfLife game = GameOfLife();
    game.start_game();
    int i = 0;
    while (i < 100) {
        game.evolve();
        usleep(80000);
        i++;
    }
    return 0;
}
