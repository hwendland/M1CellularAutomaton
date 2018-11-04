#include "gameoflife.h"

int main()
{
    GameOfLife game = GameOfLife();
    game.start_game();
    game.evolve();

    return 0;
}
