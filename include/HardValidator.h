/*
    Currently shouldnt be changed
*/

#ifndef HARDVALIDATOR_H
#define HARDVALIDATOR_H
#include "Card.h"
#include <vector>
#include <unordered_set>

class HardValidator
{
    public:
        HardValidator() = default;
        bool allCardsUnique(const vector<Card>& cards) const {
            unordered_set<Card, Card::Hash> uniqueCards(cards.begin(), cards.end());
            return uniqueCards.size() == cards.size();
        }
};

#endif // HARDVALIDATOR_H
