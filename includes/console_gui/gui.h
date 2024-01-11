#ifndef GUI_H
#define GUI_H
#include <iostream>

enum MenuOptions
{
    MENU_CATCH = 1,
    MENU_VIEW_POKEDEX = 2,
};

unsigned short int get_menu();
void display_tutorial();
void welcome_user(std::string username);

#endif