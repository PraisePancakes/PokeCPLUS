#include <iostream>
#include "../includes/User.h"
#include "../includes/console_gui/gui.h"
#include "../utils/validators/validateUsername.cpp"
#include "../includes/Ball.h"
#include "../includes/data/Data.h"
#include <conio.h>

// what to do today? create style prints, enum pokemon types
int main(int argc, char *argv[])
{
    HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
    // welcome
    display_tutorial();
    getch();
    // get user
    // first save only
    style_cout(GREEN, std::cout, "Enter your username : \n");
    std::string username;
    getline(std::cin, username);

    while (!validate_username(username))
    {
        style_cout(RED, std::cout, "Enter a different username : \n");
        getline(std::cin, username);
    }

    User user(username); // first save only

    system("cls");
    welcome_user(user.get_username()); // first || > saves

    unsigned short int starter_option = 0; // @SPAGHETTI clean this mess up, maybe abstract the entire process into the get_starter_pokemon method? who knows its just ugly
    do
    {
        style_cout(YELLOW, std::cout, "-=-=- Select your starting pokemon -=-=-\n");
        style_cout(YELLOW, std::cout, "1 : Pikachu\n");
        style_cout(LIGHTBLUE, std::cout, "2 : Squirtle\n");
        style_cout(RED, std::cout, "3 : Charmander\n");
        style_cout(GREEN, std::cout, "4 : Bulbasaur\n");

        std::cin >> starter_option;

        if (starter_option < 1 || starter_option > 4)
        {
            style_cout(RED, std::cout, "[ERROR] Invalid selection. Please choose a number between 1 and 4.\n");
        }
        else
        {
            Pokemon *starter_pokemon = user.get_starter_pokemon(starter_option);

            if (starter_pokemon)
            {
                starter_pokemon->set_shiny();
                std::cout << ":: YOU CHOSE " << starter_pokemon->get_name() << " ::\n";
                user.push_to_pokedex(starter_pokemon);
                delete starter_pokemon;
            }
            else
            {
                style_cout(RED, std::cout, "[ERROR] Invalid selection. Please choose a number between 1 and 4.\n");
            }
        }
    } while (starter_option < 1 || starter_option > 4);

    style_cout(LIGHTMAGENTA, std::cout, "press any key to continue...\n");
    getch();
    system("cls");
    style_cout(CYAN, std::cout, ":: HERE ARE YOUR STARTING BALLS ::\n");
    user.display_ball_inventory();
    style_cout(LIGHTMAGENTA, std::cout, "press any key to continue...\n");
    getch();
    system("cls");

    // game flow
    unsigned short int menu_option = 0;
    const unsigned short int MENU_EXIT = 3;

    Data data;

    while (menu_option != MENU_EXIT)
    {
        system("cls");
        user.display_user_stats();
        menu_option = get_menu();

        switch (menu_option)
        {
        case MENU_CATCH:
            // CATCH FLOW , 2s Walk -> pokemon appears -> catch | run
            {
                system("cls");
                user.walk();
                Pokemon *random_pokemon = data.get_random_pokemon();
                random_pokemon->set_shiny();

                std::cout << "-=-=- YOU ENCOUNTERED ";
                random_pokemon->display_pokemon();
                std::cout << " -=-=-\n";

                // if(catch)
                // -- catch --
                user.push_to_pokedex(random_pokemon);

                // else
                // run
            }

            break;
        case MENU_VIEW_POKEDEX:
            system("cls");
            std::cout << "=-=-= YOUR POKEDEX =-=-=\n";
            user.display_pokedex();
            style_cout(LIGHTMAGENTA, std::cout, "press any key to go back...\n");
            getch();
            break;
        case MENU_EXIT:
            style_cout(RED, std::cout, "PROCESS TERMINATED\n");
            break;
        default:
            style_cout(RED, std::cout, "[ERROR] INVALID MENU OPTION\n");
        }
    }
    return 0;
}