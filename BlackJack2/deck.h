#pragma once

#include <vector>
#include <memory>
#include <iostream>
#include <ctime>
#include <random>
#include <ctime>
#include <algorithm> // for "shuffle"
#include "card.h"

class Deck
{
public:
    Deck();
    Deck(int numDecks);
    size_t deckSize();
    void shuffleDeck();
    std::unique_ptr<Card> drawCard();
    void returnCardsFromDiscardPile();
    void returnCardsToDiscardPile( std::vector<std::unique_ptr<Card> > retCards );
    void clear();
    int numDecks();
    void setNumDecks(int numDecks);
    int discardPileSize();
    void clearDiscardPile();
    
protected:
    void createCards();

private:
    std::vector<std::unique_ptr<Card> > cards_;
    std::vector<std::unique_ptr<Card> > discardPile_;
    int numDecks_ = 0;
};
