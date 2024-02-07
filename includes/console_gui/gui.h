#ifndef GUI_H
#define GUI_H
#include <iostream>
#include <windows.h>
#include <conio.h>
#define ANY_KEY() (GUI::style_cout(GUI::LIGHTMAGENTA, std::cout, "\npress any key to continue...\n"), getch())
namespace GUI
{

    enum Colors
    {
        BLACK = 0,
        BLUE = 1,
        GREEN = 2,
        CYAN = 3,
        RED = 4,
        MAGENTA = 5,
        BROWN = 6,
        LIGHTGRAY = 7,
        DARKGRAY = 8,
        LIGHTBLUE = 9,
        LIGHTGREEN = 10,
        LIGHTCYAN = 11,
        LIGHTRED = 12,
        LIGHTMAGENTA = 13,
        YELLOW = 14,
        WHITE = 15

    };

    enum MenuOptions
    {
        MENU_CATCH = 1,
        MENU_VIEW_POKEDEX = 2,
        MENU_SHOWCASE_POKEMON = 3,
        MENU_VIEW_POKEBALLS = 4,
        MENU_VIEW_ACHIEVEMENTS = 5,
        MENU_SHOP = 6,
        MENU_EXIT = 7,
    };

    enum CatchOptions
    {
        CATCH = 1,
        RUN = 2,
    };

    unsigned short int get_menu();
    void display_starters();
    void display_tutorial();
    void welcome_user(std::string username);
    void style_cout(Colors color, std::ostream &text_stream, const std::string &text);
    unsigned short int get_shop_menu();
    unsigned short int get_ball_menu();
    Colors intToColor(int colorCode);
    unsigned short int get_catch_option();

}

#endif