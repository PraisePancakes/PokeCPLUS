#include "../../includes/console_gui/Gui.h"
#include <iostream>

namespace GUI
{

    void display_tutorial() // update in the future
    {
        style_cout(LIGHTBLUE, std::cout, "::\tWELCOME TO POKEMON CPLUS v0.0.1-alpha\t::\n\n|\t\tCATCH POKEMON\t\t\t |\n|\t\tVIEW POKDEX\t\t\t |\n|\t\tSHOWCASE POKEMON\t\t |\n|\t\tIMPROVE YOUR STATS\t\t |\n");
        style_cout(LIGHTBLUE, std::cout, "--------------------------------------------------\n");
    }

    unsigned short int get_menu()
    {
        unsigned short int option = 0;

        style_cout(YELLOW, std::cout, "=-=-= POKEMON CPLUS =-=-=\n");
        style_cout(WHITE, std::cout, "1 : Catch\n2 : Pokedex\n3 : Showcase Pokemon\n4 : View Pokeballs\n5 : View Achievements\n6 : Quit\n");
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

    Colors intToColor(int colorCode)
    {
        switch (colorCode)
        {
        case 0:
            return BLACK;
        case 1:
            return BLUE;
        case 2:
            return GREEN;
        case 3:
            return CYAN;
        case 4:
            return RED;
        case 5:
            return MAGENTA;
        case 6:
            return BROWN;
        case 7:
            return LIGHTGRAY;
        case 8:
            return DARKGRAY;
        case 9:
            return LIGHTBLUE;
        case 10:
            return LIGHTGREEN;
        case 11:
            return LIGHTCYAN;
        case 12:
            return LIGHTRED;
        case 13:
            return LIGHTMAGENTA;
        case 14:
            return YELLOW;
        case 15:
            return WHITE;
        default:
            return LIGHTGRAY; // Default color
        }
    }

    unsigned short int get_catch_option()
    {
        unsigned short int option = 0;
        style_cout(GREEN, std::cout, "\t[1] catch\t");
        style_cout(RED, std::cout, "[2] run\n");
        std::cin >> option;
        return option;
    }

}
