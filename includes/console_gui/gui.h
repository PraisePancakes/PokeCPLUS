#ifndef GUI_H
#define GUI_H
#include <iostream>
#include <windows.h>
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
        MENU_EXIT = 5,
    };

    enum CatchOptions
    {
        CATCH = 1,
        RUN = 2,
    };

    unsigned short int
    get_menu();
    void display_tutorial();
    void welcome_user(std::string username);
    void style_cout(Colors color, std::ostream &text_stream, const std::string &text);
    Colors intToColor(int colorCode);
    unsigned short int get_catch_option();

}

#endif