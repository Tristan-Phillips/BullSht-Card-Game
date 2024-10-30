#include "Player.h"

Player::~Player()
{
    //dtor
}

void Player::addCardToHand(Card card)
{
    m_hand.push_back(card);
    m_memory.updateBelief(card, CardLocation::InOwnHand, 1.0);
}

void Player::clearHand()
{
    m_hand.clear();
    m_memory.forgetAll();
}

string Player::handToString() const
{
    string handString = "";
    for (const Card& card : m_hand) {
        handString += card.toString();
        if (card == m_hand.back()) {
            break;
        }
        handString += " : ";
    }
    return handString;
}

vector<Card> Player::decideCardsToPlay()
{
    // TEMP: Player plays first card in hand
    vector<Card> card;
    if (!m_hand.empty()) {
        card.push_back(m_hand.front());
        m_hand.erase(m_hand.begin());
    }
    return card;
}

bool Player::decideCallBullshit() const
{
    // TEMP: Player never calls bullshit
    return false;
}