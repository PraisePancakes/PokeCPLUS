#include <iostream>
#include "../../includes/console_gui/Gui.h"

bool validate_username(std::string username)
{
    if (username.length() < 3)
    {
        style_cout(RED, std::cout, "[ERROR] USERNAME CANNOT BE LESS THAN THREE CHARACTERS\n");
        return false;
    }
    for (int i = 0; i < username.length(); i++)
    {
        if (isspace(username[i]))
        {
            style_cout(RED, std::cout, "[ERROR] USERNAME CANNOT CONTAIN ANY SPACES\n");
            return false;
        }
    }
    return true;
}
