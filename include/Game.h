/*
    Lots to change
*/

#ifndef GAME_H
#define GAME_H
#include "GameState.h"
#include <memory>
#include <iostream>

class Game
{
    public:
        Game(int numberOfPlayers) {
            m_gameState = make_unique<GameState>(numberOfPlayers);
        }
        ~Game() = default;

        void startGame() {
            m_gameState->startGame();
            activeGame();
            gameStats();
        }

    private:
        unique_ptr<GameState> m_gameState;
        void activeGame() {
            // Game loop
            bool gameRunning = true;
            while (gameRunning) {
                // Player turn
                for (int i = 0; i < m_gameState->getPlayerCount(); ++i) {
                    // Player plays cards
                    vector<Card> cardsToPlay = m_gameState->getPlayer(i)->decideCardsToPlay();
                    std::cout << m_gameState->getPlayer(i)->getName() << " plays: " << cardsToPlay[0].toString() << std::endl;
                    m_gameState->getPlayer(i)->removeCardFromHand(cardsToPlay[0]);
                    m_gameState->addToDiscardPile(cardsToPlay);
                    // Player calls bullshit
                    bool callBullshit = m_gameState->getPlayer(i)->decideCallBullshit();
                    // Check if player is out of cards
                    if (m_gameState->getPlayer(i)->isHandEmpty()) {
                        // Player has won
                        std::cout << m_gameState->getPlayer(i)->getName() << " has won!" << std::endl;
                        gameRunning = false;
                        break;
                    }
                }
            }
        }

        void gameStats() {
            std::cout << "Game over" << std::endl;
            for (int i = 0; i < m_gameState->getPlayerCount(); ++i) {
                std::cout << m_gameState->getPlayer(i)->getName() << " has " << m_gameState->getPlayer(i)->getHandSize() << " cards" << std::endl;
                std::cout << m_gameState->getPlayer(i)->handToString() << std::endl;
            }
            // std::cout << "Discard Pile: " << m_gameState->discardPileToString() << std::endl;
            m_gameState->printDiscardPile();
        }
};

#endif // GAME_H
