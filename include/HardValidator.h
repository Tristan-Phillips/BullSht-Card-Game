#ifndef HARDVALIDATOR_H
#define HARDVALIDATOR_H
#include "Card.h"
#include <vector>
#include <unordered_set>

class HardValidator
{
    public:
        HardValidator() = default;
        bool allCardsUnique(const vector<Card>& cards) const;
};

#endif // HARDVALIDATOR_H
