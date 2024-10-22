#ifndef CARD_H
#define CARD_H

#include <string>

using namespace std;

enum class Suit {
    HEARTS,
    DIAMONDS,
    CLUBS,
    SPADES
};

enum class Rank {
    ACE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING
};

class Card
{
public:
    Card(Suit suit, Rank rank) : m_suit(suit), m_rank(rank) {}
    virtual ~Card();

    // Accessors
    Suit getSuit() const { return m_suit; }
    Rank getRank() const { return m_rank; }

    // Utility
    string toString() const;

private:
    // Methods
    string suitToString() const;
    string rankToString() const;
    int rankToValue() const;

    // Attributes
    Suit m_suit;
    Rank m_rank;
};

#endif // CARD_H
