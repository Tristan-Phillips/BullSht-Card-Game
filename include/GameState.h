#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "Deck.h"
#include "Player.h"
#include "HardValidator.h"
#include <vector>
#include <memory>
#include <string>

class GameState
{
    public:
        GameState(int numberOfPlayers) : m_numberOfPlayers(numberOfPlayers) {
            for (int i = 0; i < numberOfPlayers; ++i) {
                m_players.emplace_back(std::make_shared<Player>("Player " + std::to_string(i + 1), (i == 0) ? true : false)); // TEMP: First player is only human
            }
        }
        virtual ~GameState();
        shared_ptr<Player> getPlayer(int playerIndex) const { return m_players[playerIndex]; }
        void startGame();
        int getPlayerCount() const { return m_numberOfPlayers; }

        // Discard Pile
        void addToDiscardPile(Card card) { 
            m_discardPile.push_back(card); 
        }

    private:
        vector<shared_ptr<Player>> m_players;
        int m_numberOfPlayers;
        Deck m_deck;
        vector<Card> m_discardPile;
};

#endif // GAMESTATE_H
