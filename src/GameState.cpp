#include "GameState.h"
#include <iostream>
GameState::~GameState()
{
    //dtor
}

void GameState::startGame() {
    cout << "Deck size: " << m_deck.size() << endl;
    cout << "Starting game with " << m_numberOfPlayers << " players" << endl;

    while (!m_deck.isEmpty()) {
        for (int player = 0; player < m_numberOfPlayers; ++player) {
            m_players[player]->addCardToHand(m_deck.drawCard());
        }
    }

    for (int player = 0; player < m_numberOfPlayers; ++player) {
        cout << m_players[player]->getName() << " : " << m_players[player]->getHandSize() << " cards" << endl;
        cout << m_players[player]->handToString() << endl;
    }

    cout << "Game started" << endl;
}
