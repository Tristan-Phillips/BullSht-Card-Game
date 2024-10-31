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

class Deck
{
    public:
        Deck(int numberOfDecks = 1) : m_numberOfDecks(numberOfDecks) {
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
            random_shuffle(m_cards.begin(), m_cards.end());
            cout << "Deck shuffled" << endl;
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
            return m_cards.size();
        }

        void addToDiscardPile(vector<Card> cards) {
            m_discardPile.addToDiscardPile(cards);
        }

        vector<Card> getDiscardPile() {
            return m_discardPile.getDiscardPile();
        }

        void print() const {
            cout << "Deck Contains: " << size() << " cards:\n";
            for (const auto& card : m_cards) {
                cout << card.toString() << "\n";
            }
            m_discardPile.print();
        }

        void printDiscardPile() const {
            m_discardPile.print();
        }

    private:
        int m_numberOfDecks;
        vector<Card> m_cards;
        DiscardPile m_discardPile;
};

#endif // DECK_H
