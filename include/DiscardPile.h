/*
    New but shouldnt change for now
*/

#ifndef DISCARDPILE_H
#define DISCARDPILE_H
#include <vector>
#include <iostream>
#include <stdexcept>
#include "Card.h"
#include <algorithm>

class DiscardPile
{
    public:
        DiscardPile() = default;
        ~DiscardPile() = default;

        void addToDiscardPile(const std::vector<Card> cards) {
            m_discardPile.insert(m_discardPile.end(), cards.begin(), cards.end());
        }

        vector<Card> getDiscardPile() {
            vector<Card> collectedCards = m_discardPile;
            clear();
            return collectedCards;
        }

        std::size_t size() const {
            return m_discardPile.size();
        }

        const Card& topCard() const {
            if (!m_discardPile.empty()) {
                return m_discardPile.back();
            }
            throw std::runtime_error("Discard pile is empty");
        }

        void print() const {
            std::cout << "Discard Pile Contains: " << size() << " cards:\n";
            for (const auto& card : m_discardPile) {
                std::cout << card.toString() << "\n";
            }
        }

        bool contains (const Card& card) const {
            return std::find(m_discardPile.begin(), m_discardPile.end(), card) != m_discardPile.end();
        }

    private:
        std::vector<Card> m_discardPile;

        void clear() {
            m_discardPile.clear();
        }

        const std::vector<Card> getCards() const {
            return m_discardPile;
        }
};

#endif // DISCARDPILE_H
