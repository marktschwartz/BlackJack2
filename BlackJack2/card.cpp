#include "card.h"

Card::Card( Rank rank, Suit suit ) : rank_( rank ), suit_( suit )
{
    // nothing here
}

Rank Card::getRank() const
{
    return rank_;
}

Suit Card::getSuit() const
{
    return suit_;
}
