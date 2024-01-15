#include "../../includes/console_gui/Gui.h"
#include <iostream>

void display_tutorial() // update in the future
{
    std::cout << "::\tWELCOME TO POKEMON CPLUS::\n\n|\tCATCH POKEMON\t\t |\n|\tVIEW POKDEX\t\t |\n|\tSHOWCASE POKEMON\t |\n|\tIMPROVE YOUR STATS\t |\n";
    std::cout << "------------------------------\n";
    std::cout << "press any key to continue...\n";
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
