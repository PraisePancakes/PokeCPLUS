#include <iostream>
#include "../includes/User.h"
#include "../includes/console_gui/gui.h"
#include "../utils/validators/validateUsername.cpp"
#include "../includes/Ball.h"
#include "../includes/data/Data.h"

int main(int argc, char *argv[])
{

    // welcome
    display_tutorial();

    // get user
    // first save only
    std::cout << "Enter your username : \n";
    std::string username;
    getline(std::cin, username);

    while (!validate_username(username))
    {
        std::cout << "Enter a different username : \n";
        getline(std::cin, username);
    }

    User user(username); // first save only

    welcome_user(user.get_username()); // first || > saves

    unsigned short int starter_option = get_starter_pokemon();
    Pokemon *starter_pokemon = nullptr;
    switch (starter_option)
    {
    case 1:
        starter_pokemon = new Pokemon("Pikachu", "Lightning", std::experimental::nullopt, false);
        break;
    case 2:
        starter_pokemon = new Pokemon("Squirtle", "Water", std::experimental::nullopt, false);
        break;
    case 3:
        starter_pokemon = new Pokemon("Charmander", "Fire", std::experimental::nullopt, false);
        break;
    case 4:
        starter_pokemon = new Pokemon("Bulbasaur", "Grass", "Poison", false);
        break;
    default:
        std::cout << "[ERROR] INVALID STARTER OPTION\n";
    }
    starter_pokemon->set_shiny();
    user.push_to_pokedex(starter_pokemon);
    delete starter_pokemon;

    user.display_ball_inventory();

    // game flow
    unsigned short int menu_option = 0;
    const unsigned short int MENU_EXIT = 3;

    Data data;

    while (menu_option != MENU_EXIT)
    {
        menu_option = get_menu();
        system("cls");
        switch (menu_option)
        {
        case MENU_CATCH:
            // handle catching
            // get random pokemon from poke data
            // CATCH FLOW , 2s Walk -> pokemon appears -> catch | run
            {
                user.walk();
                /*
                    @test
                    -random pokemon success
                    -push to pokedex success
                */
                Pokemon *random_pokemon = data.get_random_pokemon(); // << you encountered
                random_pokemon->set_shiny();

                // if(catch)
                // -- catch --
                // handle set shiny here?
                random_pokemon->display_pokemon();
                user.push_to_pokedex(random_pokemon);
                // else
                // run
            }

            break;
        case MENU_VIEW_POKEDEX:
            std::cout << "=-=-= YOUR POKEDEX =-=-=\n";
            user.display_pokedex();
            break;
        case MENU_EXIT:
            std::cout << "PROCESS TERMINATED\n";
            break;
        default:
            std::cout << "[ERROR] INVALID MENU OPTION\n";
        }
    }
    return 0;
}