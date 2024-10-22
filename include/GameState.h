#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

#include "Player.h"
#include "Deck.h"

class GameState
{
public:
    GameState(int numberOfPlayers, int numberOfDecks) : m_deck(numberOfDecks), m_currentPlayerIndex(0), m_currentRank(static_cast<int>(Rank::TWO)), m_gameOver(false) {
        for (int i = 0; i < numberOfPlayers; ++i) {
            m_players.emplace_back(std::make_shared<Player>("Player " + std::to_string(i + 1)));
        }
    }

    virtual ~GameState();

    void startGame();

private:
    vector<shared_ptr<Player>> m_players;
    Deck m_deck;
    vector<Card> m_visibleCards;
    vector<Card> m_discardPile;
    int m_currentPlayerIndex;
    int m_currentRank;
    bool m_gameOver;

    void dealInitialCards();
    void playTurn();
    void nextPlayer();
    void callBullshit();
    void checkGameOver();
    void announceWinner();
};

#endif // GAMESTATE_H
