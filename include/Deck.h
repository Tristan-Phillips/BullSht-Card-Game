#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <stdexcept>

class Deck
{
public:
    Deck(int numberOfDecks = 1) : m_numberOfDecks(numberOfDecks) {
        reset();
    }
    virtual ~Deck();

    void shuffle();
    Card draw();
    void reset();
    bool isEmpty() const;
    int size() const;

private:
    // Attributes
    int m_numberOfDecks;
    std::vector<Card> m_cards;
};

#endif // DECK_H
