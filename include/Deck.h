/*
    Introduction of DiscardPile m_discardPile
*/

#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include "DiscardPile.h"
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <random>

class Deck
{
    public:
        explicit Deck(int numberOfDecks = 1) : m_numberOfDecks(numberOfDecks) {
            reset();
        }

        ~Deck() = default;

        void reset() {
            m_cards.clear();
            for (int deck = 0; deck < m_numberOfDecks; ++deck){
                for (int suit = static_cast<int>(Suit::HEARTS); suit <= static_cast<int>(Suit::SPADES); ++suit){
                    for (int rank = static_cast<int>(Rank::ACE); rank <= static_cast<int>(Rank::KING); ++rank){
                        m_cards.emplace_back(static_cast<Suit>(suit), static_cast<Rank>(rank));
                    }
                }
            }
            shuffle();
        }

        void shuffle() {
            std::random_device rd;
            std::mt19937 g(rd());
            std::shuffle(m_cards.begin(), m_cards.end(), g);
            std::cout << "Deck has been shuffled" << std::endl;
        }

        Card drawCard() {
            if (isEmpty()) {
                throw std::out_of_range("Deck is empty");
            }

            Card topCard = m_cards.back();
            m_cards.pop_back();
            return topCard;
        }

        bool isEmpty() const {
            return m_cards.empty();
        }

        int size() const {
            return static_cast<int>(m_cards.size());
        }

        void addToDiscardPile(const std::vector<Card>& cards) {
            m_discardPile.addToDiscardPile(cards);
        }

        std::vector<Card> getDiscardPile() {
            return m_discardPile.collectDiscardPile();
        }

        void print() const {
            cout << "Deck Contains: " << size() << " cards" << std::endl;
            for (const auto& card : m_cards) {
                std::cout << card.toString() << std::endl;
            }
            printDiscardPile();
        }

        void printDiscardPile() const {
            m_discardPile.print();
        }

    private:
        int m_numberOfDecks;
        std::vector<Card> m_cards;
        DiscardPile m_discardPile;
};

#endif // DECK_H
