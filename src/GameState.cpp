#include "GameState.h"

GameState::~GameState()
{
    //dtor
}

string GameState::allPlayersToString() const {
    string result;
    for (const auto& player : m_players) {
        result += (player->isHuman() ? "Human " : "AI ") + player->getName() + "\n";
    }
    return result;
}
