#ifndef GAME_H
#define GAME_H
#include "GameState.h"
#include <memory>

class Game
{
    public:
        Game(int numberOfPlayers) {
            m_gameState = make_unique<GameState>(numberOfPlayers);
        }
        virtual ~Game();

        void startGame();

    private:
        unique_ptr<GameState> m_gameState;
};

#endif // GAME_H
