#include <iostream>
#include "../includes/User.h"
#include "../includes/console_gui/gui.h"
#include "../utils/validators/validateUsername.cpp"
#include "../includes/Ball.h"
#include "../includes/data/Data.h"
#include <conio.h>
#define ANY_KEY() (GUI::style_cout(GUI::LIGHTMAGENTA, std::cout, "press any key to continue...\n"), getch())

// what to do today? create an xp and points system
int main(int argc, char *argv[])
{
    HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");
    GUI::display_tutorial();
    ANY_KEY();
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

    User user(username, 0, 0, 0); // first save only

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

    ANY_KEY();
    getch();
    system("cls");
    GUI::style_cout(GUI::CYAN, std::cout, ":: HERE ARE YOUR STARTING BALLS ::\n");
    user.display_ball_inventory();
    ANY_KEY();
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

                unsigned short int catch_option = GUI::get_catch_option();
                if (catch_option == GUI::CATCH)
                {
                    // chose ball
                    GUI::style_cout(GUI::MAGENTA, std::cout, "--- CHOOSE A BALL ---\n");
                    std::experimental::optional<Ball> new_ball = user.choose_ball();
                    if (!new_ball)
                    {
                        ANY_KEY();
                        break;
                    }

                    bool successful_catch = user.throw_ball(&(*new_ball), random_pokemon);

                    if (successful_catch)
                    {
                        GUI::style_cout(GUI::GREEN, std::cout, " :: CATCH SUCCESSFUL ::\n");
                        random_pokemon->display_pokemon();
                        user.push_to_pokedex(random_pokemon);
                        getch();
                        break;
                    }

                    unsigned short int MAX_THROWS = 5;

                    if (random_pokemon->get_is_legendary())
                    {
                        MAX_THROWS = 2;
                    }

                    unsigned short int current_throws = 0;
                    while (!successful_catch)
                    {
                        if (current_throws == MAX_THROWS)
                        {
                            GUI::style_cout(GUI::RED, std::cout, " :: POKEMON GOT IMPATIENT :: \n");
                            random_pokemon->display_fled();
                            break;
                        }
                        GUI::style_cout(GUI::RED, std::cout, " :: BALL MISSED, WOULD YOU LIKE TO THROW AGAIN? :: \n");
                        catch_option = GUI::get_catch_option();
                        if (catch_option == GUI::RUN)
                        {
                            random_pokemon->display_fled();
                            ANY_KEY();
                            break;
                        }

                        std::experimental::optional<Ball> new_ball = user.choose_ball();

                        if (!new_ball)
                        {
                            ANY_KEY();
                            break;
                        }

                        bool successful_catch = user.throw_ball(&(*new_ball), random_pokemon);

                        if (successful_catch)
                        {
                            GUI::style_cout(GUI::GREEN, std::cout, " :: CATCH SUCCESSFUL ::\n");
                            random_pokemon->display_pokemon();
                            user.push_to_pokedex(random_pokemon);
                            break;
                        }
                        current_throws++;
                    }

                    getch();
                }
                else if (catch_option == GUI::RUN)
                {
                    random_pokemon->display_fled();
                }
                delete data;
            }

            break;
        case GUI::MENU_VIEW_POKEDEX:
            system("cls");
            GUI::style_cout(GUI::YELLOW, std::cout, "=-=-= YOUR POKEDEX =-=-=\n");
            user.display_pokedex();
            ANY_KEY();
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