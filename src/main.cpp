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
                Data *data = new Data();
                system("cls");
                user.walk();
                Pokemon *random_pokemon = data->get_random_pokemon();
                random_pokemon->set_shiny();

                GUI::style_cout(GUI::YELLOW, std::cout, "-=-=- YOU ENCOUNTERED ");
                random_pokemon->display_pokemon();
                GUI::style_cout(GUI::YELLOW, std::cout, " -=-=-");
                std::cout << "\n";

                int max_throws;
                int throw_count = 0;

                if (random_pokemon->get_is_legendary())
                {
                    max_throws = 3;
                }
                else
                {
                    max_throws = 7;
                }

                unsigned short int catch_option = 0;
                do
                {
                    catch_option = GUI::get_catch_option();
                    if (catch_option == GUI::RUN)
                    {
                        random_pokemon->display_fled();
                        break;
                    }
                    else
                    {
                        GUI::style_cout(GUI::MAGENTA, std::cout, "--- CHOOSE A BALL ---\n");
                        Ball new_ball = user.choose_ball();
                        bool successful_catch = user.throw_ball(&new_ball, random_pokemon);
                        throw_count++;

                        if (successful_catch)
                        {
                            GUI::style_cout(GUI::GREEN, std::cout, " :: CATCH SUCCESSFUL ::\n");
                            random_pokemon->display_pokemon();
                            user.push_to_pokedex(random_pokemon);
                            getch();
                            break;
                        }
                        else
                        {
                            GUI::style_cout(GUI::RED, std::cout, " :: THROW MISSED ::\n");
                        }
                    }

                } while (throw_count != max_throws);
                delete data;
            }

            break;
        case GUI::MENU_VIEW_POKEDEX:
            system("cls");
            GUI::style_cout(GUI::YELLOW, std::cout, "=-=-= YOUR POKEDEX =-=-=\n");
            user.display_pokedex();
            GUI::style_cout(GUI::LIGHTMAGENTA, std::cout, "press any key to go back...\n");
            getch();
            break;
        case GUI::MENU_SHOWCASE_POKEMON:
            GUI::style_cout(GUI::YELLOW, std::cout, "=-=-= CHOOSE A SHOWCASE =-=-=\n");
            user.set_showcase_pokemon();
            getch();
            break;
        case GUI::MENU_VIEW_POKEBALLS:
            user.display_ball_inventory();
            getch();
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