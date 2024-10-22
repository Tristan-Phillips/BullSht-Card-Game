#ifndef GAME_H
#define GAME_H

#include "GameState.h"
#include <iostream>
#include <memory>

class Game
{
public:
    Game(int numberOfPlayers) : m_numberOfPlayers(numberOfPlayers) {
        int numberOfDecks = (m_numberOfPlayers <= 4) ? 1 : 2;
        m_gameState = std::make_unique<GameState>(m_numberOfPlayers, numberOfDecks);
    }
    virtual ~Game();

    void start();

private:
    int m_numberOfPlayers;
    unique_ptr<GameState> m_gameState;
};

#endif // GAME_H
