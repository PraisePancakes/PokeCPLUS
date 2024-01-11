#include "../../includes/console_gui/gui.h"
#include <iostream>

void display_tutorial() // update in the future
{
    std::cout << ":: WELCOME TO POKEMON CPLUS ::\n|\tCATCH POKEMON\t|\n|\tVIEW POKDEX\t|\n";
}

unsigned short int get_menu()
{
    unsigned short int option = 0;

    std::cout << "=-=-= POKEMON CPLUS =-=-=\n"
              << "1 : Catch\n2 : Pokedex\n3 : Quit\n";
    std::cin >> option;

    return option;
}

void welcome_user(std::string username)
{
    std::cout << ":: WELCOME " << username << "::\n";
};

unsigned short int get_starter_pokemon()
{
    unsigned short int option = 0;
    std::cout << "-=-=- Select your starting pokemon -=-=-\n1 : Pikachu\n2 : Squirtle\n3 : Charmander\n4 : Bulbasaur\n";
    std::cin >> option;

    return option;
}