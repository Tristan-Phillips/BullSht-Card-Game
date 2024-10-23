#include "CardMemory.h"

void CardMemory::updateBelief(const Card& card, CardLocation location, double confidence) {
    if (confidence < 0.0 || confidence > 1.0) {
        throw std::invalid_argument("Confidence must be between 0 and 1");
    }
    m_cardBeliefs[card] = {location, confidence};
}

std::pair<CardLocation, double> CardMemory::getBelief(Card& card) const {
    auto it = m_cardBeliefs.find(card);
    if (it != m_cardBeliefs.end()) {
        return it->second;
    }
    return {CardLocation::InOpponentHand, 0.0};
}

void CardMemory::forget(Card& card) {
    m_cardBeliefs.erase(card);
}

void CardMemory::forgetAll() {
    m_cardBeliefs.clear();
}

void CardMemory::decayBeliefs(double decayFactor) {
    if (decayFactor < 0.0 || decayFactor > 1.0) {
        throw std::invalid_argument("Decay factor must be between 0 and 1");
    }
    for (auto& entry : m_cardBeliefs) {
        entry.second.second *= (1.0 - decayFactor);
    }
}