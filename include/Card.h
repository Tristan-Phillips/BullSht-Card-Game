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
        virtual ~Card();

        Suit getSuit() const { return m_suit; }
        Rank getRank() const { return m_rank; }

        int rankToValue() const;
        string suitToString() const;
        string rankToString() const;
        string toString() const;

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
