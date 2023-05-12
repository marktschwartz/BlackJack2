#pragma once


#include <vector>
#include <ctime>
#include <memory>
#include <iostream>

enum Rank
{
    ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING
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
    std::string getCardStr() const;

protected:
    std::string getRankStr() const;
    std::string getSuitStr() const;

private:
    Rank rank_;
    Suit suit_;

    std::vector<std::string> rankStrs_;
    std::vector<std::string> suitStrs_;
};
