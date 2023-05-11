
#include "deck.h"

Deck::Deck()
{
    for ( int suit = HEARTS; suit <= SPADES; ++suit )
    {
        for ( int rank = ACE; rank <= KING; ++rank )
        {
            cards_.push_back( std::make_unique<Card>( static_cast<Rank>( rank ), static_cast<Suit>( suit ) ) );
        }
    }
}

size_t Deck::deckSize()
{
    return cards_.size();
}

void Deck::shuffleDeck()
{
    std::random_device rd;
    std::mt19937 g( rd() );
    std::shuffle( cards_.begin(), cards_.end(), g );
}

std::unique_ptr<Card> Deck::drawCard()
{
    if ( cards_.empty() )
    {
        return nullptr;
    }

    std::unique_ptr<Card> card = move( cards_.back() );
    cards_.pop_back();

    return card;
}

void Deck::returnCard( std::unique_ptr<Card> card )
{
    if ( card != nullptr )
    {
        cards_.push_back( move( card ) );
        card = nullptr;
    }
}

void Deck::returnCards( std::vector<std::unique_ptr<Card> > retCards )
{
    while ( !retCards.empty() )
    {
        cards_.push_back( move( retCards.back() ) );
        retCards.pop_back();
    }
}