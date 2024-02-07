#include <iostream>
#include "../includes/User.h"
#include "../includes/console_gui/gui.h"
#include "../utils/validators/validateUsername.cpp"
#include "../includes/Ball.h"
#include "../includes/data/Data.h"
#include "../includes/Envionment.h"
#include <fstream>
#include <cereal/archives/json.hpp>

/*
   __TO DO__
    what to do today?
    refactor src/main,
    convert dumb pointers to smart pointers
    remove executable from VCS, users will have to build and run the project themselves
    (BONUS POINTS find out how to make a release executable so that users dont have to build themselves)
*/

int main(int argc, char *argv[])
{
    HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);

    ENVIRONMENT::play_music(); // future addition
    system("cls");
    GUI::display_tutorial();
    ANY_KEY();

    // first save only
    const std::string save_path = "save/user_data.json";
    std::ifstream file(save_path.c_str());
    User user(0, 0, 0); // first save only

    if (file.is_open())
    {
        user.loadFromFile(save_path);
        file.close();
    }
    else
    {
        GUI::style_cout(GUI::GREEN, std::cout, "Enter your username : \n");
        std::string username;
        getline(std::cin, username);

        // load user? first check if a save_file exists, if fopen() != NULL then de serialize the user object and use that as the load

        while (!validate_username(username))
        {
            GUI::style_cout(GUI::RED, std::cout, "Enter a different username : \n");
            getline(std::cin, username);
        }

        user.set_username(username);

        unsigned short int starter_option = 0;
        do
        {

            GUI::display_starters();
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
            }
        } while (starter_option < 1 || starter_option > 4);

        ANY_KEY();
    }

    system("cls");
    GUI::welcome_user(user.get_username()); // first || > saves
    ANY_KEY();

    system("cls");
    GUI::style_cout(GUI::CYAN, std::cout, ":: HERE ARE YOUR STARTING BALLS ::\n");
    user.display_ball_inventory();
    ANY_KEY();
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
                    std::optional<Ball> new_ball = user.choose_ball();
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
                        ANY_KEY();
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

                        std::optional<Ball> new_ball = user.choose_ball();

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

                    ANY_KEY();
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
            break;
        case GUI::MENU_SHOWCASE_POKEMON:
            GUI::style_cout(GUI::YELLOW, std::cout, "=-=-= CHOOSE A SHOWCASE =-=-=\n");
            user.set_showcase_pokemon();
            ANY_KEY();
            break;
        case GUI::MENU_VIEW_POKEBALLS:
            user.display_ball_inventory();
            ANY_KEY();
            break;
        case GUI::MENU_VIEW_ACHIEVEMENTS:
            GUI::style_cout(GUI::YELLOW, std::cout, "=-=-= YOUR ACHIEVEMENTS =-=-=\n");
            user.display_achievements();
            ANY_KEY();
            break;
        case GUI::MENU_SHOP:
            GUI::style_cout(GUI::YELLOW, std::cout, "=-=-= SHOP =-=-=\n");
            if (user.get_coins() < 500)
            {
                GUI::style_cout(GUI::RED, std::cout, ":: NOT ENOUGH COINS, COME BACK WHEN YOU HAVE MORE COINS ::\n");
            }
            else
            {
                unsigned short int shop_option = 0;
                const unsigned short int SHOP_EXIT = 2;
                while (shop_option != SHOP_EXIT)
                {
                    shop_option = GUI::get_shop_menu();
                    switch (shop_option)
                    {
                    case 1:
                        // display pokeball shop
                        {
                            unsigned short int pokeball_option = 0;
                            const unsigned short int BALL_MENU_EXIT = 5;
                            while (pokeball_option != BALL_MENU_EXIT)
                            {
                                pokeball_option = GUI::get_ball_menu();
                                switch (pokeball_option)
                                {
                                case 1:
                                    user.buy_ball("Pokeball", 5);
                                    user.subtract_coins(500);
                                    break;
                                case 2:
                                    user.buy_ball("Greatball", 5);
                                    user.subtract_coins(1000);
                                    break;
                                case 3:
                                    user.buy_ball("Ultraball", 5);
                                    user.subtract_coins(10000);
                                    break;
                                case 4:
                                    user.buy_ball("Masterball", 1);
                                    user.subtract_coins(100000);
                                    break;
                                case BALL_MENU_EXIT:
                                    break;
                                default:
                                    GUI::style_cout(GUI::RED, std::cout, ":: INVALID SELECTION TRY AGAIN ::\n");
                                }
                            }
                        }
                        break;
                    case SHOP_EXIT:
                        break;
                    default:
                        GUI::style_cout(GUI::RED, std::cout, ":: INVALID SHOP SELECTION TRY AGAIN ::");
                    }
                }
            }
            ANY_KEY();
        case GUI::MENU_EXIT:
            GUI::style_cout(GUI::RED, std::cout, "PROCESS TERMINATED\n");
            user.saveToFile(save_path);
            break;
        default:
            GUI::style_cout(GUI::RED, std::cout, "[ERROR] INVALID MENU OPTION\n");
        }
    }

    return 0;
}