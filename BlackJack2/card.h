#pragma once

enum Rank
{
    ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING
};
enum Suit
{
    HEARTS, CLOVER, DIAMOND, SPADES
};

class Card
{
public:
    Card( Rank rank, Suit suit );
    Rank getRank() const;
    Suit getSuit() const;

private:
    Rank rank_;
    Suit suit_;
};
