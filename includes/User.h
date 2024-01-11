
#ifndef USER_H
#define USER_H

#include "Pokemon.h"
#include <iostream>
#include <vector>

class User
{
private:
    std::string m_username;
    std::vector<Pokemon> m_pokedex;

public:
    User(std::string username); // arg list : username, pokedex, pokeballs

    void add_pokemon(Pokemon &new_pokemon);
    void display_pokedex() const;
    std::string get_username() const;
    // ~User(); future deconstructor
};

#endif