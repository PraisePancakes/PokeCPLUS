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
    GUI::display_tutorial();
    getch();
    // get user
    // first save only
    GUI::style_cout(GUI::GREEN, std::cout, "Enter your username : \n");
    std::string username;
    getline(std::cin, username);

    while (!validate_username(username))
    {
        GUI::style_cout(GUI::RED, std::cout, "Enter a different username : \n");
        getline(std::cin, username);
    }

    User user(username); // first save only

    system("cls");
    GUI::welcome_user(user.get_username()); // first || > saves

    unsigned short int starter_option = 0; // @SPAGHETTI clean this mess up, maybe abstract the entire process into the get_starter_pokemon method? who knows its just ugly
    do
    {
        GUI::style_cout(GUI::YELLOW, std::cout, "-=-=- Select your starting pokemon -=-=-\n");
        GUI::style_cout(GUI::YELLOW, std::cout, "1 : Pikachu\n");
        GUI::style_cout(GUI::LIGHTBLUE, std::cout, "2 : Squirtle\n");
        GUI::style_cout(GUI::RED, std::cout, "3 : Charmander\n");
        GUI::style_cout(GUI::GREEN, std::cout, "4 : Bulbasaur\n");

        std::cin >> starter_option;

        if (starter_option < 1 || starter_option > 4)
        {
            GUI::style_cout(GUI::RED, std::cout, "[ERROR] Invalid selection. Please choose a number between 1 and 4.\n");
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
                GUI::style_cout(GUI::RED, std::cout, "[ERROR] Invalid selection. Please choose a number between 1 and 4.\n");
            }
        }
    } while (starter_option < 1 || starter_option > 4);

    GUI::style_cout(GUI::LIGHTMAGENTA, std::cout, "press any key to continue...\n");
    getch();
    system("cls");
    GUI::style_cout(GUI::CYAN, std::cout, ":: HERE ARE YOUR STARTING BALLS ::\n");
    user.display_ball_inventory();
    GUI::style_cout(GUI::LIGHTMAGENTA, std::cout, "press any key to continue...\n");
    getch();
    system("cls");

    // game flow
    unsigned short int menu_option = 0;
    Data *data = new Data();

    while (menu_option != GUI::MENU_EXIT)
    {
        system("cls");
        user.display_user_stats();
        menu_option = GUI::get_menu();

        switch (menu_option)
        {
        case GUI::MENU_CATCH:
            // CATCH FLOW , 2s Walk -> pokemon appears -> catch | run
            {
                system("cls");
                user.walk();
                Pokemon *random_pokemon = data->get_random_pokemon();
                std::cout << "here " << random_pokemon->get_name();
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
            delete data;

            break;
        case GUI::MENU_VIEW_POKEDEX:
            system("cls");
            std::cout << "=-=-= YOUR POKEDEX =-=-=\n";
            user.display_pokedex();
            GUI::style_cout(GUI::LIGHTMAGENTA, std::cout, "press any key to go back...\n");
            getch();
            break;
        case GUI::MENU_SHOWCASE_POKEMON:
            break;
        case GUI::MENU_EXIT:
            GUI::style_cout(GUI::RED, std::cout, "PROCESS TERMINATED\n");

            break;
        default:
            GUI::style_cout(GUI::RED, std::cout, "[ERROR] INVALID MENU OPTION\n");
        }
    }
    return 0;
}