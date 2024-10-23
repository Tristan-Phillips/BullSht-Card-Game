#include "Game.h"

Game::~Game()
{
    //dtor
}

void Game::startGame() {
    m_gameState->startGame();
}