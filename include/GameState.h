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
        explicit GameState(int numberOfPlayers) : m_numberOfPlayers(numberOfPlayers) {
            for (int i = 0; i < numberOfPlayers; ++i) {
                m_players.emplace_back(std::make_shared<Player>("Player " + std::to_string(i + 1), (i == 0))); // TEMP: First player is only human
            }
        }

        ~GameState() = default;

        std::shared_ptr<Player> getPlayer(int playerIndex) const {
            if (playerIndex < 0 || playerIndex >= m_numberOfPlayers) {
                throw std::out_of_range("Player index out of range");
            }
            return m_players[playerIndex];
        }

        void startGame() {
            std::cout << "Deck size: " << m_deck.size() << std::endl;
            std::cout << "Starting game with " << m_numberOfPlayers << " players" << std::endl;

            dealCardsToPlayers();

            HardValidator validator;
            for (const auto& player : m_players) {
                std::cout << player->getName() << " : " << player->getHandSize() << " cards" << std::endl;
                std::cout << player->handToString() << std::endl;
                if (!validator.allCardsUnique(player->getHand())) {
                    std::cout << "Player " << player->getName() << " has duplicate cards" << std::endl;
                }
            }
            cout << "Game started" << endl;
        }

        int getPlayerCount() const {
            return m_numberOfPlayers;
        }

        std::vector<Card> getDiscardPile() {
            return m_deck.getDiscardPile();
        }

        void addToDiscardPile(const std::vector<Card>& cards) {
            m_deck.addToDiscardPile(cards);
        }

        void printDiscardPile() const {
            m_deck.printDiscardPile();
        }

    private:
        void dealCardsToPlayers() {
            while (!m_deck.isEmpty()) {
                for (auto& player : m_players) {
                    player->addCardToHand(m_deck.drawCard());
                }
            }
        }

        std::vector<std::shared_ptr<Player>> m_players;
        int m_numberOfPlayers;
        Deck m_deck;
};

#endif // GAMESTATE_H
