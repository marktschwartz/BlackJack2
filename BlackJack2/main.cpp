
#include "blackjack.h"
#include <iostream>
#include <string>
#include <conio.h>

enum MAIN_MENU_OPTIONS
{
    NEW_TABLE,
    CREATE_PLAYER,
    LIST_PLAYERS,
    EXIT_PROGRAM
};

enum GAME_MENU_OPTIONS
{
    PLAY_HAND,
    SHOW_WIN_LOSS,
    LEAVE_TABLE,
};

void GameMenu( BlackJack& bj )
{
    bool contGame = true;
    system( "cls" ); // clear the screen

    while ( contGame )
    {
        int option = -1;
        std::string buffer = "";
        std::cout << "TABLE MENU" << std::endl;
        std::cout << "\t0 ==> Play Hand" << std::endl;
        std::cout << "\t1 ==> Show Win/Loss" << std::endl;
        std::cout << std::endl;
        std::cout << "\t2 ==> Leave Table" << std::endl;
        std::cout << std::endl;
        std::cout << "\t?: ";
        std::getline( std::cin, buffer );
        option = atoi( buffer.c_str() );
        std::cout << std::endl;
        switch ( option )
        {
        case PLAY_HAND:
            bj.PlayHand();
            break;
        case SHOW_WIN_LOSS:
            bj.ShowWinLoss();
            break;
        case LEAVE_TABLE:
            contGame = false;
            break;
        default:
            break;
        }
    }
}

int main()
{
    std::cout << "Hello BlackJack!\n";

    BlackJack bj;
    bool contGame = true;
    while ( contGame )
    {
        int option = -1;
        std::cout << "Main Menu" << std::endl;
        std::cout << "\t0 ==> Sitdown at Table" << std::endl;
        std::cout << "\t1 ==> Create New Player" << std::endl;
        std::cout << "\t2 ==> List Players" << std::endl;
        std::cout << std::endl;
        std::cout << "\t3 ==> Exit Program" << std::endl;
        std::cout << "\t?:";
        std::string buffer = "";
        std::getline( std::cin, buffer );
        option = atoi( buffer.c_str() );
        std::cout << std::endl;
        switch ( option )
        {
        case NEW_TABLE:
            if ( bj.PlayerCount() > 1 )
            {
                GameMenu( bj );
            }
            break;
        case CREATE_PLAYER:
            std::cout << "\tCreate new player:" << std::endl;
            std::cout << "\t?: ";
            std::getline( std::cin, buffer );
            bj.CreatePlayer( buffer );
            break;
        case LIST_PLAYERS:
            bj.ListPlayers();
            break;
        case EXIT_PROGRAM:
            contGame = false;
            break;
        default:
            break;
        };
    }
}

