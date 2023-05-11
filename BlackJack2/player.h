#pragma once

#include <vector>
#include <memory>
#include <iostream>
#include <ctime>
#include <random>
#include <ctime>
#include <algorithm> // for "shuffle"
#include "card.h"
#include <combaseapi.h>


class Player
{
public:
    Player( std::string Name );
    std::vector<std::unique_ptr<Card> > giveBackHand();
    bool bustedHand();
    void addCard( std::unique_ptr<Card> card );
    int aces();
    int handValue();
    std::string const name();
    GUID ID();
    void win();
    void loss();
    std::string getWinLoss();

protected:
    int getHandValue();

private:
    std::string name_;
    std::vector < std::unique_ptr<Card> > hand_;
    int handValue_;
    int aces_;
    GUID guid_;
    int win_;
    int loss_;
};
