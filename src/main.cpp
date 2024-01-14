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
    Pokemon *new_pokemon = nullptr;
    switch (starter_option)
    {
    case 1:
        new_pokemon = new Pokemon("Pikachu", "Lightning", std::experimental::nullopt, false);
        break;
    case 2:
        new_pokemon = new Pokemon("Squirtle", "Water", std::experimental::nullopt, false);
        break;
    case 3:
        new_pokemon = new Pokemon("Charmander", "Fire", std::experimental::nullopt, false);
        break;
    case 4:
        new_pokemon = new Pokemon("Bulbasaur", "Grass", "Poison", false);
        break;
    default:
        std::cout << "[ERROR] INVALID STARTER OPTION\n";
    }

    user.push_to_pokedex(new_pokemon);
    delete new_pokemon;

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
        {
            user.walk();
            /*
                @test random pokemon success, push to pokedex success
            */
            Pokemon *random_pokemon = data.get_random_pokemon();
            user.push_to_pokedex(random_pokemon);
        }
        // handle catching
        // CATCH FLOW , 2s Walk -> pokemon appears -> catch | run

        // get random pokemon from poke data

        break;
        case MENU_VIEW_POKEDEX:
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