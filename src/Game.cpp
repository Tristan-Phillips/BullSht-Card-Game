#include "Game.h"

Game::~Game()
{
    //dtor
}

void Game::start()
{
    cout << "Starting a new game of Bullshit with " << m_numberOfPlayers << " players!" << std::endl;
    m_gameState->startGame();
}