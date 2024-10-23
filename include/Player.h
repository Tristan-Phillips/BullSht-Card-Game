#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"
#include "CardMemory.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

class Player
{
    public:
        Player(string name, bool isHuman = false) : m_name(name), m_isHuman(isHuman), m_memory() {};
        virtual ~Player();

        // Player Details
        string getName() const { return m_name; }
        bool isHuman() const { return m_isHuman; }

        // Player Cards
        bool isHandEmpty() const { return m_hand.empty(); }
        int getHandSize() const { return m_hand.size(); }
        void addCardToHand(Card card);
        void clearHand();
        vector<Card> getHand() const { return m_hand; }

        // Player Memory
        void updateMemory(const Card& card, CardLocation location, double confidence) { m_memory.updateBelief(card, location, confidence); }
        std::pair<CardLocation, double> getMemory(Card& card) const { 
            return m_memory.getBelief(card); 
        }
        void forgetMemory(Card& card) { m_memory.forget(card); }
        void forgetAllMemory() { m_memory.forgetAll(); }
        void decayMemory(double decayFactor) { m_memory.decayBeliefs(decayFactor); }

    private:
        string m_name;
        vector<Card> m_hand;
        bool m_isHuman;
        CardMemory m_memory;
};

#endif // PLAYER_H
