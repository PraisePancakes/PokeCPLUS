#include <iostream>
#include "../includes/User.h"
#include "../includes/console_gui/gui.h"

bool check_username(std::string username)
{
    for (int i = 0; i < username.length(); i++)
    {
        if (isspace(username[i]))
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[])
{
    unsigned short int menu_option = 0;
    const unsigned short int MENU_EXIT = 3;

    // welcome
    display_tutorial();

    // get user
    std::cout << "Enter your username : \n";
    std::string username;
    getline(std::cin, username);

    while (!check_username(username))
    {
        std::cout << "[ERROR] USERNAME CANNOT CONTAIN ANY SPACES\n";
        std::cout << "Enter a different username : \n";
        getline(std::cin, username);
    }

    User user(username);

    welcome_user(user.get_username());

    // game flow
    while (menu_option != MENU_EXIT)
    {
        switch (menu_option)
        {
        case 1:
            break;
        }
    }
    return 0;
}