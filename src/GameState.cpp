#include "GameState.h"

GameState::~GameState()
{
    //dtor
}

void GameState::startGame()
{
    m_deck.shuffle();
    dealInitialCards();

    while (!m_gameOver) {
        playTurn();
        checkGameOver();
        nextPlayer();
    }

    announceWinner();
}

void GameState::dealInitialCards()
{
    const int initialHandSize = (m_deck.size() / m_players.size());
    for (int i = 0; i < initialHandSize; ++i) {
        for (auto &player : m_players) {
            player->addCard(m_deck.draw());
        }
    }
}

void GameState::playTurn()
{
    auto& currentPlayer = m_players[m_currentPlayerIndex];
    cout << currentPlayer->getName() << "'s turn. Current rank: " << m_currentRank << std::endl;

    vector<Card> playedCards = currentPlayer->playCards();
    for (const auto &card : playedCards) {
        m_discardPile.push_back(card);
    }

    if (m_players[(m_currentPlayerIndex + 1) % m_players.size()]->shouldCallBs(m_visibleCards, m_currentRank)) {
        callBullshit();
    }

    m_currentRank = (m_currentRank % static_cast<int>(Rank::ACE)) + 1;
}

void GameState::nextPlayer()
{
    m_currentPlayerIndex = (m_currentPlayerIndex + 1) % m_players.size();
}

void GameState::callBullshit()
{
    auto& currentPlayer = m_players[m_currentPlayerIndex];
    auto& nextPlayer = m_players[(m_currentPlayerIndex + 1) % m_players.size()];

    cout << nextPlayer->getName() << " called bullshit on " << currentPlayer->getName() << "!" << std::endl;

    bool bluffDetected = std::any_of(m_discardPile.begin(), m_discardPile.end(), [this](const Card &card) {
        return card.getRank() != static_cast<Rank>(m_currentRank);
    });

    if (bluffDetected) {
        for (const auto& card : m_discardPile) {
            currentPlayer->addCard(card);
        }
        cout << currentPlayer->getName() << " was lying! " << currentPlayer->getName() << " takes the discard pile." << std::endl;
    } else {
        for (const auto& card : m_discardPile) {
            nextPlayer->addCard(card);
        }
        cout << currentPlayer->getName() << " was telling the truth! " << nextPlayer->getName() << " takes the discard pile." << std::endl;
    }

    m_discardPile.clear();
}

void GameState::checkGameOver()
{
    for (const auto &player : m_players) {
        if (player->isHandEmpty()) {
            m_gameOver = true;
            break;
        }
    }
}

void GameState::announceWinner()
{
    auto winner = std::min_element(m_players.begin(), m_players.end(), [](const shared_ptr<Player> &a, const shared_ptr<Player> &b) {
        return a->getHandSize() < b->getHandSize();
    });

    cout << "Game over! " << (*winner)->getName() << " wins!" << std::endl;
}
