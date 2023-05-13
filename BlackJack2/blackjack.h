#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <random>
#include <ctime>
#include <algorithm> // for "shuffle"
#include "deck.h"
#include "player.h"
#include <combaseapi.h>
#include <iostream>
#include <string>
#include <conio.h>

class BlackJack
{
public:
    BlackJack();
    void StartNewTable();
    void CreatePlayer( std::string name );
    void RemoveAllPLayers();
    void PlayHand();
    void ShowWinLoss();
    int PlayerCount();
    void ListPlayers();
    void RemovePlayer();

private:
    std::vector<std::unique_ptr<Player> > players_;
    Deck deck_;
    int draw_;
    int ties_;
};