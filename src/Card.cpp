#include "Card.h"

Card::~Card()
{
    //dtor
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

int Card::rankToValue() const
{
    switch (m_rank)
    {
        case Rank::ACE:
            return 1;
        case Rank::TWO:
            return 2;
        case Rank::THREE:
            return 3;
        case Rank::FOUR:
            return 4;
        case Rank::FIVE:
            return 5;
        case Rank::SIX:
            return 6;
        case Rank::SEVEN:
            return 7;
        case Rank::EIGHT:
            return 8;
        case Rank::NINE:
            return 9;
        case Rank::TEN:
            return 10;
        case Rank::JACK:
            return 10;
        case Rank::QUEEN:
            return 10;
        case Rank::KING:
            return 10;
        default:
            return 0;
    }
}