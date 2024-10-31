#include <iostream>
#include "Game.h"
#include "UserInput.h"

using namespace std;

int main()
{
    UserInput input;
    Game game(input.getNumberOfPlayers());
    game.startGame();
    return 0;
}
