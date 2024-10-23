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
    InDiscardPile
};

class CardMemory
{
    public:
        CardMemory() = default;

        void updateBelief(const Card& card, CardLocation location, double confidence);
        std::pair<CardLocation, double> getBelief(Card& card) const;
        void forget(Card& card);
        void forgetAll();
        void decayBeliefs(double decayFactor);

    private:
        std::unordered_map<Card, std::pair<CardLocation, double>, Card::Hash> m_cardBeliefs;
};

#endif // CARDMEMORY_H
