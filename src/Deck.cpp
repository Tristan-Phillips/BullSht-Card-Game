#include "Deck.h"

Deck::~Deck()
{
    //dtor
}

void Deck::shuffle()
{
    std::shuffle(m_cards.begin(), m_cards.end(), std::default_random_engine(static_cast<unsigned int>(time(0))));
}

Card Deck::draw()
{
    if (isEmpty()) {
        throw std::out_of_range("Deck is empty");
    }

    Card topCard = m_cards.back();
    m_cards.pop_back();
    return topCard;
}

void Deck::reset()
{
    m_cards.clear();
    for (int deck = 0; deck < m_numberOfDecks; ++deck) {
        for (int suit = static_cast<int>(Suit::HEARTS); suit <= static_cast<int>(Suit::SPADES); ++suit) {
            for (int rank = static_cast<int>(Rank::ACE); rank <= static_cast<int>(Rank::KING); ++rank) {
                m_cards.emplace_back(static_cast<Suit>(suit), static_cast<Rank>(rank));
            }
        }
    }
    shuffle();
}

bool Deck::isEmpty() const
{
    return m_cards.empty();
}

int Deck::size() const
{
    return static_cast<int>(m_cards.size());
}