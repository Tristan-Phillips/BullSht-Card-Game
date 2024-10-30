#ifndef PLAYERSTRATEGY_H
#define PLAYERSTRATEGY_H
#include "Card.h"
#include <vector>
#include <memory>

class GameState; // Forward decleration

class PlayerStrategy
{
    public:
        virtual ~PlayerStrategy() = default;
        virtual vector<Card> decideCardsToPlay(const vector<Card>& hand, const GameState& gameState) = 0;
        virtual bool decideCallBullshit(const GameState& gameState) = 0;
};

#endif // PLAYERSTRATEGY_H
