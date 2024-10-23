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
        handString += card.toString() + " : ";
    }
    return handString;
}