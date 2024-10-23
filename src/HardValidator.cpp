#include "HardValidator.h"

bool HardValidator::allCardsUnique(const vector<Card>& cards) const {
    unordered_set<Card, Card::Hash> uniqueCards(cards.begin(), cards.end());
    return uniqueCards.size() == cards.size();
}