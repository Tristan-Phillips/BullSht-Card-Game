/*
    Class should not be changed currently
*/

#ifndef CARD_H
#define CARD_H
#include <string>
using namespace std;

enum class Suit
{
    HEARTS,
    DIAMONDS,
    CLUBS,
    SPADES
};

enum class Rank
{
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
        ~Card() = default;

        Suit getSuit() const {
            return m_suit;
        }
        Rank getRank() const {
            return m_rank;
        }

        int rankToValue() const {
            return static_cast<int>(m_rank);
        }
        string suitToString() const {
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
        string rankToString() const {
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

        string toString() const {
            return rankToString() + " of " + suitToString();
        }

        bool operator==(const Card& other) const {
            return m_suit == other.m_suit && m_rank == other.m_rank;
        }

        struct Hash {
            size_t operator()(const Card& card) const {
                return hash<int>()(static_cast<int>(card.getSuit())) ^ hash<int>()(static_cast<int>(card.getRank()));
            }
        };

    private:
        Suit m_suit;
        Rank m_rank;
};

#endif // CARD_H
