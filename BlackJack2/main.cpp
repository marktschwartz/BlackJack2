
#include "blackjack.h"

int main()
{
    std::cout << "Hello BlackJack!\n";

    BlackJack bj;
    bj.StartNewTable();

    bj.CreatePlayer( "Mark" );
    bj.CreatePlayer( "Dave" );
    bj.CreatePlayer( "Michele" );

    for( int i = 0; i < 1000; i++ )
    {
        bj.PlayHand();
    }

    bj.ShowWinLoss();

}
