#include <iostream>
#include "../../includes/console_gui/Gui.h"
#include <cctype>

bool validate_username(std::string username)
{
    if (username.length() < 3)
    {
        GUI::style_cout(GUI::RED, std::cout, "[ERROR] USERNAME CANNOT BE LESS THAN THREE CHARACTERS\n");
        return false;
    }
    for (int i = 0; i < username.length(); i++)
    {
        if (std::isspace((unsigned char)username[i]))
        {
            GUI::style_cout(GUI::RED, std::cout, "[ERROR] USERNAME CANNOT CONTAIN ANY SPACES\n");
            return false;
        }
    }
    return true;
}
