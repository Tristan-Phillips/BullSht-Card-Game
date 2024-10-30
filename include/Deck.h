#ifndef DECK_H
#define DECK_H
#include "Card.h"
#include <vector>
#include <algorithm>
#include <stdexcept>

class Deck
{
    public:
        Deck(int numberOfDecks = 1) : m_numberOfDecks(numberOfDecks) {
            reset();
        }
        virtual ~Deck();

        void reset();
        void shuffle();
        Card drawCard();
        bool isEmpty() const { return m_cards.empty(); }
        int size() const { return m_cards.size(); }

    private:
        int m_numberOfDecks;
        vector<Card> m_cards;
};

#endif // DECK_H
