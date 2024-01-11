
#ifndef USER_H
#define USER_H

#include <iostream>

class User
{
private:
    std::string m_username;

public:
    User(std::string username); // arg list : username, pokedex, pokeballs

    std::string get_username();
    // ~User(); future deconstructor
};

#endif