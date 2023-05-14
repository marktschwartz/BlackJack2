
#include "deck.h"

Deck::Deck()
{
    numDecks_ = 1;
    createCards();
}

Deck::Deck(int numDecks)
{
    numDecks_ = numDecks;
    createCards();
}

size_t Deck::deckSize()
{
    return cards_.size();
}

void Deck::shuffleDeck()
{
    returnCardsFromDiscardPile();

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

void Deck::returnCardsFromDiscardPile()
{
    if ( !discardPile_.empty())
    {
        cards_.push_back( move( discardPile_.back() ) );
        discardPile_.pop_back();
    }
}

void Deck::discardHand( std::vector<std::unique_ptr<Card> > retCards )
{
    while ( !retCards.empty() )
    {
        discardPile_.push_back( move( retCards.back() ) );
        retCards.pop_back();
    }
}

void Deck::clear()
{
    cards_.clear();
}

int Deck::numDecks()
{
    return numDecks_;
}

void Deck::setNumDecks(int numDecks)
{
    if (numDecks != numDecks_)
    {
        cards_.clear();
        discardPile_.clear();
        numDecks_ = numDecks;

        createCards();
    }
}

void Deck::createCards()
{
    cards_.clear();
    for (int i = 0; i < numDecks_; i++)
    {
        for (int suit = HEARTS; suit <= SPADES; ++suit)
        {
            for (int rank = ACE; rank <= KING; ++rank)
            {
                cards_.push_back(std::make_unique<Card>(static_cast<Rank>(rank), static_cast<Suit>(suit)));
            }
        }
    }
    shuffleDeck();
}

int Deck::discardPileSize()
{
    return discardPile_.size();
}

void Deck::clearDiscardPile()
{
    discardPile_.clear();
}