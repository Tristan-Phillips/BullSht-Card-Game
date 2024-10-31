/*
    Lots to change
*/

#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "Deck.h"
#include "Player.h"
#include "HardValidator.h"
#include <vector>
#include <memory>
#include <string>
#include <iostream>

class GameState
{
    public:
        GameState(int numberOfPlayers) : m_numberOfPlayers(numberOfPlayers) {
            for (int i = 0; i < numberOfPlayers; ++i) {
                m_players.emplace_back(std::make_shared<Player>("Player " + std::to_string(i + 1), (i == 0) ? true : false)); // TEMP: First player is only human
            }
        }
        ~GameState() = default;

        shared_ptr<Player> getPlayer(int playerIndex) const {
            return m_players[playerIndex];
        }

        void startGame() {
            cout << "Deck size: " << m_deck.size() << endl;
            cout << "Starting game with " << m_numberOfPlayers << " players" << endl;

            while (!m_deck.isEmpty()) {
                for (int player = 0; player < m_numberOfPlayers; ++player) {
                    m_players[player]->addCardToHand(m_deck.drawCard());
                }
            }

            HardValidator validator;
            for (int player = 0; player < m_numberOfPlayers; ++player) {
                cout << m_players[player]->getName() << " : " << m_players[player]->getHandSize() << " cards" << endl;
                cout << m_players[player]->handToString() << endl;
                if (!validator.allCardsUnique(m_players[player]->getHand())) {
                    cout << "Player " << m_players[player]->getName() << " has duplicate cards" << endl;
                }
            }

            cout << "Game started" << endl;
        }

        int getPlayerCount() const {
            return m_numberOfPlayers;
        }

        vector<Card> getDiscardPile() {
            return m_deck.getDiscardPile();
        }

        void addToDiscardPile(vector<Card> cards) {
            m_deck.addToDiscardPile(cards);
        }

        void printDiscardPile() {
            m_deck.printDiscardPile();
        }

    private:
        vector<shared_ptr<Player>> m_players;
        int m_numberOfPlayers;
        Deck m_deck;
};

#endif // GAMESTATE_H
