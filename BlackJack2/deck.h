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
    size_t deckSize();
    void shuffleDeck();
    std::unique_ptr<Card> drawCard();
    void returnCard( std::unique_ptr<Card> card );
    void returnCards( std::vector<std::unique_ptr<Card> > retCards );

private:
    std::vector<std::unique_ptr<Card> > cards_;
};
