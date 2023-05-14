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
    BlackJack(int numDecks);
    void StartNewTable();
    void CreatePlayer( std::string name );
    void RemoveAllPLayers();
    void PlayHand();
    void ShowWinLoss();
    void ListPlayers();
    void RemovePlayer();
    void SetNumDecks(int numDecks);
    int GetNumDecks();
    int GetNumPlayers();

private:
    std::vector<std::unique_ptr<Player> > players_;
    Deck deck_;
    int draw_;
    int ties_;
    int button_;
};