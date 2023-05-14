#include "blackjack.h"

BlackJack::BlackJack(int numDecks)
{
    deck_.setNumDecks(numDecks);
    draw_ = 0;
    ties_ = 0;
}
void BlackJack::CreatePlayer(std::string name)
{
    if (!name.empty())
    {
        players_.push_back(std::make_unique<Player>(name));

        std::cout << std::endl;
        std::cout << "\tNew Player Added: " << name << std::endl;
        std::cout << std::endl;
    }
}
void BlackJack::PlayHand()
{
    if (deck_.deckSize() < 13)
    {
        std::cout << "getting new deck..." << std::endl;
        deck_.clear();
        deck_.setNumDecks(deck_.numDecks());
        deck_.clearDiscardPile();
    }
    deck_.shuffleDeck();

    if (players_.size() < 2)
    {
        std::cout << "Must have at least two players." << std::endl;
        return;
    }
    std::cout << "Deal two cards to each player" << std::endl;
    for (int i = 0; i < 2; i++)
    {
        for (auto& player : players_)
        {
            player->addCard(deck_.drawCard());
        }
    }

    for (auto& player : players_)
    {
        while (true)
        {
            std::cout << "\t" << player->name() << " HandValue: " << player->handValue() << std::endl;
            std::cout << "\t\t" << "NumCards: " << player->numCards() << std::endl;
            std::cout << "\t\t" << "Cards: " << player->handStr() << std::endl;
            std::cout << std::endl;
            std::cout << "\t\tDo you wish another card? (y/n)" << std::endl;
            std::cout << "\t\t?: ";
            std::string buffer = "";
            std::getline(std::cin, buffer);
            if (buffer == "y")
            {
                player->addCard(deck_.drawCard());
                if (player->bustedHand())
                {
                    std::cout << "\tHand Busted" << std::endl;
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }

    int highScore = 0;
    for (auto& player : players_)
    {
        if (!player->bustedHand())
        {
            if (player->handValue() > highScore)
            {
                highScore = player->handValue();
            }
        }
    }

    int playersWon = 0;
    if (0 == highScore)
    {
        std::cout << "\tEveryone busted, Draw!!" << std::endl;
        draw_++;
    }
    else
    {
        for (auto& player : players_)
        {
            if (player->handValue() == highScore)
            {
                std::cout << "Winner: " << player->name() << " hand: " << highScore << std::endl;
                player->win();
                playersWon++;
            }
            else
            {
                player->loss();
            }
        }
    }
    if (playersWon > 1)
    {
        ties_++;
        std::cout << "\tTie game" << std::endl;
    }

    for (auto& player : players_)
    {
        deck_.returnCardsToDiscardPile(player->giveBackHand());
    }
    std::cout << "\tCard remaining in shoe: " << deck_.deckSize() << std::endl;
    std::cout << "\tDiscard Pile: " << deck_.discardPileSize() << std::endl << std::endl << std::endl;
}

void BlackJack::ShowWinLoss()
{
    for (auto& player : players_)
    {
        std::cout << "\t" << player->name() << " -- " << player->getWinLoss() << std::endl;
    }
    std::cout << "\tDraw -- " << draw_ << std::endl;
    std::cout << "\tTies -- " << ties_ << std::endl;
}

void BlackJack::RemoveAllPLayers()
{
    while (!players_.empty())
    {
        players_.clear();
    }
    draw_ = 0;
    ties_ = 0;
    deck_.shuffleDeck();
    deck_.clearDiscardPile();
}

void BlackJack::StartNewTable()
{
    RemoveAllPLayers();
    deck_.shuffleDeck();
}

int BlackJack::PlayerCount()
{
    return players_.size();
}

void BlackJack::ListPlayers()
{
    std::cout << std::endl;
    std::cout << "\tList of Players" << std::endl;
    if (players_.empty())
    {
        std::cout << "\tNo players in List" << std::endl;
    }
    else
    {
        for (auto& player : players_)
        {
            std::cout << "\t" << player->name() << std::endl;
        }
    }
    std::cout << std::endl;
}

void BlackJack::RemovePlayer()
{
    std::cout << std::endl;
    std::cout << "\t\tRemove Player:" << std::endl;
    for (int i = 0; i < players_.size(); i++)
    {
        std::cout << "\t\t\t" << i << " ==> " << players_.at(i)->name() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "\t\t\t?# ";
    std::string buffer;
    std::getline(std::cin, buffer);

    int idx = atoi(buffer.c_str());
    if (errno == ERANGE)
    {
        return;
    }
    if (idx >= players_.size() || idx < 0)
    {
        return;
    }
    std::cout << "\t\tRemoving Player: " << players_.at(idx)->name() << std::endl;
    players_.erase(players_.begin() + idx);
    
    ListPlayers();
}

void BlackJack::SetNumDecks(int numDecks)
{
    deck_.setNumDecks(numDecks);
}

int BlackJack::GetNumDecks()
{
    return deck_.numDecks();
}
