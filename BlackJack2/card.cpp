#include "card.h"

Card::Card( Rank rank, Suit suit ) : rank_( rank ), suit_( suit )
{
    rankStrs_.push_back("Ace");
    rankStrs_.push_back("Two");
    rankStrs_.push_back("Three");
    rankStrs_.push_back("Four");
    rankStrs_.push_back("Five");
    rankStrs_.push_back("Six");
    rankStrs_.push_back("Seven");
    rankStrs_.push_back("Eight");
    rankStrs_.push_back("Nine");
    rankStrs_.push_back("Ten");
    rankStrs_.push_back("Jack");
    rankStrs_.push_back("Queen");
    rankStrs_.push_back("King");

    suitStrs_.push_back("Hearts");
    suitStrs_.push_back("Club");
    suitStrs_.push_back("Diamond");
    suitStrs_.push_back("Spades");

}

Rank Card::getRank() const
{
    return rank_;
}

Suit Card::getSuit() const
{
    return suit_;
}

std::string Card::getRankStr() const
{
    return rankStrs_.at((int)rank_-1);
}

std::string Card::getSuitStr() const
{
    return suitStrs_.at((int)suit_);
}

std::string Card::getCardStr() const
{
    return "[" + getRankStr() + "_" + getSuitStr() + "] ";
}
