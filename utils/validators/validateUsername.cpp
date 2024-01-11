#include <iostream>

bool validate_username(std::string username)
{
    if (username.length() < 3)
    {
        std::cout << "[ERROR] USERNAME CANNOT BE LESS THAN THREE CHARACTERS\n";
        return false;
    }
    for (int i = 0; i < username.length(); i++)
    {
        if (isspace(username[i]))
        {
            std::cout << "[ERROR] USERNAME CANNOT CONTAIN ANY SPACES\n";
            return false;
        }
    }
    return true;
}
