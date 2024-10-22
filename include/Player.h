#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <algorithm>
#include "Card.h"

class Player
{
public:
    Player(const string &name, bool isAI = false) : m_name(name), m_isAI(isAI) {};
    virtual ~Player();

    void addCard(const Card &card);
    bool removeCard(const Card &card);
    vector<Card> playCards();
    void showHand() const;
    int getHandSize() const;
    bool isHandEmpty() const;
    string getName() const { return m_name; }
    bool isAI() const { return m_isAI; }
    bool shouldCallBs(const vector<Card> &visibleCards, int claimedRank);

private:
    // Attributes
    string m_name;
    vector<Card> m_hand;
    bool m_isAI;
};

#endif // PLAYER_H
