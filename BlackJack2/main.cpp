
#include "blackjack.h"
#include <iostream>
#include <string>
#include <conio.h>

enum MAIN_MENU_OPTIONS
{
    EXIT_PROGRAM,
    NEW_TABLE,
    CREATE_PLAYER,
    DELETE_PLAYER,
    DELETE_ALL_PLAYERS,
    LIST_PLAYERS,
};

enum GAME_MENU_OPTIONS
{
    LEAVE_TABLE,
    PLAY_HAND,
    SHOW_WIN_LOSS,
};

void GameMenu(BlackJack& bj)
{
    bool contGame = true;
    system("cls"); // clear the screen

    while (contGame)
    {
        int option = -1;
        std::string buffer = "";
        std::cout << "TABLE MENU" << std::endl;
        std::cout << "\t" << GAME_MENU_OPTIONS::PLAY_HAND << " ==> Play Hand" << std::endl;
        std::cout << "\t" << GAME_MENU_OPTIONS::SHOW_WIN_LOSS << " ==> Show Win/Loss" << std::endl;
        std::cout << std::endl;
        std::cout << "\t" << GAME_MENU_OPTIONS::LEAVE_TABLE << " ==> Leave Table" << std::endl;
        std::cout << std::endl;
        std::cout << "\t?: ";
        std::getline(std::cin, buffer);
        option = atoi(buffer.c_str());
        std::cout << std::endl;
        switch (option)
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
    BlackJack bj( 7 );
    
    bool contGame = true;
    while (contGame)
    {
        int option = -1;
        std::cout << "Main Menu" << std::endl;
        std::cout << "\t" << MAIN_MENU_OPTIONS::NEW_TABLE << " ==> Sitdown at Table" << std::endl;
        std::cout << "\t" << MAIN_MENU_OPTIONS::CREATE_PLAYER << " ==> Create New Player" << std::endl;
        std::cout << "\t" << MAIN_MENU_OPTIONS::DELETE_PLAYER << " ==> Delete Player" << std::endl;
        std::cout << "\t" << MAIN_MENU_OPTIONS::DELETE_ALL_PLAYERS << " ==> Delete All Players" << std::endl;
        std::cout << "\t" << MAIN_MENU_OPTIONS::LIST_PLAYERS << " ==> List Players" << std::endl;
        std::cout << std::endl;
        std::cout << "\t" << MAIN_MENU_OPTIONS::EXIT_PROGRAM << " ==> Exit Program" << std::endl;
        std::cout << "\t?:";
        std::string buffer = "";
        std::getline(std::cin, buffer);
        option = atoi(buffer.c_str());
        if (errno == ERANGE)
        {
            option = -1;
        }
        std::cout << std::endl;
        switch (option)
        {
        case MAIN_MENU_OPTIONS::NEW_TABLE:
            if (bj.PlayerCount() > 1)
            {
                GameMenu(bj);
            }
            break;
        case MAIN_MENU_OPTIONS::CREATE_PLAYER:
            std::cout << "\tCreate new player:" << std::endl;
            std::cout << "\t?: ";
            std::getline(std::cin, buffer);
            bj.CreatePlayer(buffer);
            break;
        case MAIN_MENU_OPTIONS::LIST_PLAYERS:
            bj.ListPlayers();
            break;
        case MAIN_MENU_OPTIONS::EXIT_PROGRAM:
            contGame = false;
            break;
        case MAIN_MENU_OPTIONS::DELETE_PLAYER:
            bj.RemovePlayer();
            break;
        case MAIN_MENU_OPTIONS::DELETE_ALL_PLAYERS:
            bj.RemoveAllPLayers();
            break;
        default:
            break;
        };
    }
}

