/*
    Class is inactive atm
*/

#ifndef CARDMEMORY_H
#define CARDMEMORY_H
#include "Card.h"
#include <string>
#include <unordered_map>
#include <utility>
#include <stdexcept> 

class Card; // Forward declaration

enum class CardLocation {
    InOwnHand,
    InOpponentHand,
    InDiscardPile,
    Unknown
};

class CardMemory
{
    public:
        CardMemory() = default;

        void updateBelief(const Card& card, CardLocation location, double confidence) {
            if (confidence < 0.0 || confidence > 1.0) {
                throw std::invalid_argument("Confidence must be between 0 and 1");
            }
            m_cardBeliefs[card] = {location, confidence};   
        }

        std::pair<CardLocation, double> getBelief(const Card& card) const {
            auto it = m_cardBeliefs.find(card);
            if (it != m_cardBeliefs.end()) {
                return it->second;
            }
            return {CardLocation::Unknown, 0.0}; // Default belief
        }

        void forget(const Card& card) {
            m_cardBeliefs.erase(card);
        }

        void forgetAll() {
            m_cardBeliefs.clear();
        }

        void decayBeliefs(double decayFactor) {
            if (decayFactor < 0.0 || decayFactor > 1.0) {
                throw std::invalid_argument("Decay factor must be between 0 and 1");
            }
            for (auto& entry : m_cardBeliefs) {
                entry.second.second *= (1.0 - decayFactor);
            }
        }

    private:
        std::unordered_map<Card, std::pair<CardLocation, double>, Card::Hash> m_cardBeliefs;
};

#endif // CARDMEMORY_H
