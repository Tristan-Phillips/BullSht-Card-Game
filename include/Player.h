/*
    Proper play logic and strategy to be implemented
*/

#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"
#include "CardMemory.h"
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

using std::string;
using std::vector;

class Player
{
    public:
        Player(string name, bool isHuman = false) 
            : m_name(name), m_isHuman(isHuman), m_memory() {};

        ~Player() = default;

        // Player Details
        string getName() const { 
            return m_name; 
        }

        bool isHuman() const { 
            return m_isHuman; 
        }

        // Player Cards
        bool isHandEmpty() const { 
            return m_hand.empty(); 
        }

        int getHandSize() const { 
            return static_cast<int>(m_hand.size());
        }

        void addCardToHand(Card card) {
            m_hand.push_back(card);
            m_memory.updateBelief(card, CardLocation::InOwnHand, 1.0);
        }

        void clearHand() {
            m_hand.clear();
            m_memory.forgetAll();
        }

        const vector<Card>& getHand() const { 
            return m_hand; 
        }

        void removeCardFromHand(const Card& card) { 
            std::cout << "Removing card from hand: " << card.toString() << std::endl;
        
            auto it = std::find(m_hand.begin(), m_hand.end(), card);
            if (it != m_hand.end()) {
                m_hand.erase(it);
            } else {
                throw std::runtime_error("Card not found in hand");
            }
            std::cout << "Remaining Hand: " << handToString() << std::endl;
        }

        // Decision Making
        vector<Card> decideCardsToPlay() {
            // TEMP: Player plays first card in hand
            vector<Card> card;
            if (!m_hand.empty()) {
                card.push_back(m_hand.front());
            }
            return card;
        }

        bool decideCallBullshit() const {
            // TEMP: Player never calls bullshit
            return false;
        }

        // Player Memory
        void updateMemory(const Card& card, CardLocation location, double confidence) { 
            m_memory.updateBelief(card, location, confidence); 
        }

        std::pair<CardLocation, double> getMemory(const Card& card) const { 
            return m_memory.getBelief(card); 
        }

        void forgetMemory(const Card& card) { 
            m_memory.forget(card); 
        }

        void forgetAllMemory() { 
            m_memory.forgetAll(); 
        }

        void decayMemory(double decayFactor) { 
            m_memory.decayBeliefs(decayFactor); 
        }

        string handToString() const {
            string handString = "";
            for (const Card& card : m_hand) {
                handString += card.toString();
                if (card == m_hand.back()) {
                    break;
                }
                handString += "\n";
            }
            return handString;
        }

    private:
        string m_name;
        vector<Card> m_hand;
        bool m_isHuman;
        CardMemory m_memory;
};

#endif // PLAYER_H
