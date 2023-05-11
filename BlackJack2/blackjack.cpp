#include "blackjack.h"

BlackJack::BlackJack()
{
    draw_ = 0;
}
void BlackJack::CreatePlayer( std::string name )
{
    if ( !name.empty() )
    {
        players_.push_back( std::make_unique<Player>( name ) );
    }
}
void BlackJack::PlayHand()
{
    if ( deck_.deckSize() != 52 )
    {
        std::cout << "Something is wrong with the deck:  (getting new deck)" << std::endl;
        deck_ = Deck();
    }

    deck_.shuffleDeck();

    if ( players_.size() < 2 )
    {
        std::cout << "Must have at least two players." << std::endl;
        return;
    }
    std::cout << "Deal two cards to each player" << std::endl;
    for ( int i = 0; i < 2; i++ )
    {
        for ( auto& player : players_ )
        {
            player->addCard( deck_.drawCard() );
        }
    }

    for ( auto& player : players_ )
    {
        if ( !player->bustedHand() )
        {
            if ( player->handValue() < 16 )
            {
                player->addCard( deck_.drawCard() );
            }
        }
    }


    int highScore = 0;
    std::string winner;
    GUID winnerGuid;
    for ( auto& player : players_ )
    {
        if ( !player->bustedHand() )
        {
            if ( player->handValue() > highScore )
            {
                highScore = player->handValue();
                winner = player->name();
                winnerGuid = player->ID();
            }
        }
    }

    for ( auto& player : players_ )
    {
        if ( player->ID() == winnerGuid )
        {
            player->win();
        }
        else
        {
            player->loss();
        }
    }
    if ( 0 == highScore )
    {
        std::cout << "\tEveryone busted, Draw!!" << std::endl;
        draw_++;
    }
    else
    {
        std::cout << "Winner: " << winner << " hand: " << highScore << std::endl;
    }

    std::cout << "returning cards to deck: ";
    for ( auto& player : players_ )
    {
        deck_.returnCards( player->giveBackHand() );
    }
    std::cout << deck_.deckSize() << std::endl;
}

void BlackJack::ShowWinLoss()
{
    for ( auto& player : players_ )
    {
        std::cout << "\t" << player->name() << " -- " << player->getWinLoss() << std::endl;
    }
    std::cout << "\tDraw -- " << draw_ << std::endl;
}

void BlackJack::RemoveAllPLayers()
{
    while( !players_.empty() )
    {
        players_.pop_back();
    }
    draw_ = 0;
}

void BlackJack::StartNewTable()
{
    deck_ = Deck();
    RemoveAllPLayers();
}