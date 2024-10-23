#include <iostream>
#include "GameState.h"

using namespace std;

int main()
{
    GameState game(4);
    cout << game.allPlayersToString() << endl;
    return 0;
}
