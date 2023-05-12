
#include "player.h"
#include <format>

Player::Player( std::string name ) : name_( name )
{
    CoCreateGuid( &guid_ );
};

std::vector<std::unique_ptr<Card> > Player::giveBackHand()
{
    std::vector<std::unique_ptr<Card> > cards;
    while ( !hand_.empty() )
    {
        cards.push_back( std::move( hand_.back() ) );
        hand_.pop_back();
    }
    handValue_ = 0;
    aces_ = 0;

    return cards;
}

bool Player::bustedHand()
{
    return ( handValue_ > 21 );
}

void Player::addCard( std::unique_ptr<Card> card )
{
    hand_.push_back( std::move( card ) );
    handValue_ = getHandValue();
    if ( hand_.size() > 2 )
    {
        std::cout << "\t\t" << name_ << " gets a new card: " << hand_.at(hand_.size()-1)->getCardStr();
        if ( bustedHand() )
        {
            std::cout << "  !! BUSTED";
        }
        std::cout << std::endl;
    }
}

int Player::aces()
{
    return aces_;
}

int Player::handValue()
{
    return handValue_;
}
void Player::win()
{
    win_++;
}

void Player::loss()
{
    loss_++;
}

std::string Player::getWinLoss()
{
    char buffer[ 1024 ];
    sprintf_s( buffer, 1024, "win: %d loss: %d", win_, loss_ );
    return std::string( buffer );
}

std::string const Player::name()
{
    return name_;
}

int Player::getHandValue()
{
    int value = 0;
    for ( const auto& card : hand_ )
    {
        int cardValue = card->getRank();
        if ( cardValue >= 10 )
        {
            cardValue = 10;
        }
        else if ( cardValue == ACE )
        {
            aces_++;
            cardValue = 11;
        }
        value += cardValue;
    }

    while ( value > 21 && aces_ > 0 )
    {
        value -= 10;
        aces_--;
    }
    return value;
}

GUID Player::ID()
{
    return guid_;
}

int Player::numCards()
{
    return (int)hand_.size();
}

std::string Player::handStr()
{
    std::string retVal;
    for (auto& card : hand_)
    {
        retVal += card->getCardStr();
    }
    return retVal;
}