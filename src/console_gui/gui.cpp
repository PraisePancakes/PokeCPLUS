#include "../../includes/console_gui/Gui.h"
#include <iostream>

void display_tutorial() // update in the future
{
    style_cout(LIGHTBLUE, std::cout, "::\tWELCOME TO POKEMON CPLUS::\n\n|\tCATCH POKEMON\t\t |\n|\tVIEW POKDEX\t\t |\n|\tSHOWCASE POKEMON\t |\n|\tIMPROVE YOUR STATS\t |\n");
    style_cout(LIGHTBLUE, std::cout, "------------------------------\n");
    style_cout(LIGHTMAGENTA, std::cout, "press any key to continue...\n");
}

unsigned short int get_menu()
{
    unsigned short int option = 0;

    style_cout(YELLOW, std::cout, "=-=-= POKEMON CPLUS =-=-=\n");
    style_cout(WHITE, std::cout, "1 : Catch\n2 : Pokedex\n3 : Quit\n");
    std::cin >> option;

    return option;
}

void welcome_user(std::string username)
{
    style_cout(CYAN, std::cout, ":: WELCOME ");
    style_cout(GREEN, std::cout, username);
    style_cout(CYAN, std::cout, " ::\n");
};

void style_cout(Colors color, std::ostream &text_stream, const std::string &text)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), static_cast<WORD>(color));
    text_stream << text;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // Assuming 7 is the default color
}