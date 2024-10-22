#ifndef STRATEGY_H
#define STRATEGY_H

#include <vector>
#include "Card.h"

class Strategy
{
public:
    virtual ~Strategy() = default;
    virtual std::vector<Card> decideCardsToPlay(const vector<Card> &hand, int currentRank) = 0;
    virtual bool shouldCallBs(const vector<Card>& visibleCards, int claimedRank) = 0;
};

#endif // STRATEGY_H
