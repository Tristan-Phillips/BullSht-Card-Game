#include "Card.h"

Card::~Card()
{
    //dtor
}

int Card::rankToValue() const
{
    return static_cast<int>(m_rank);
}

string Card::suitToString() const
{
    switch (m_suit)
    {
        case Suit::HEARTS:
            return "Hearts";
        case Suit::DIAMONDS:
            return "Diamonds";
        case Suit::CLUBS:
            return "Clubs";
        case Suit::SPADES:
            return "Spades";
        default:
            return "Unknown";
    }
}

string Card::rankToString() const
{
    switch (m_rank)
    {
        case Rank::ACE:
            return "Ace";
        case Rank::TWO:
            return "Two";
        case Rank::THREE:
            return "Three";
        case Rank::FOUR:
            return "Four";
        case Rank::FIVE:
            return "Five";
        case Rank::SIX:
            return "Six";
        case Rank::SEVEN:
            return "Seven";
        case Rank::EIGHT:
            return "Eight";
        case Rank::NINE:
            return "Nine";
        case Rank::TEN:
            return "Ten";
        case Rank::JACK:
            return "Jack";
        case Rank::QUEEN:
            return "Queen";
        case Rank::KING:
            return "King";
        default:
            return "Unknown";
    }
}

string Card::toString() const
{
    return rankToString() + " of " + suitToString();
}