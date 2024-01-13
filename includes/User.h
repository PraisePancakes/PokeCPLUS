
#ifndef USER_H
#define USER_H

#include "Pokemon.h"
#include <iostream>
#include <vector>
#include "Ball.h"

class User
{
private:
    std::string m_username;
    std::vector<Pokemon> m_pokedex;
    std::vector<Ball> m_ball_inventory;
    void m_init_ball_inventory();

public:
    User(std::string username); // arg list : username, pokedex, pokeballs

    void push_to_pokedex(Pokemon *new_pokemon);
    void push_to_ball_inventory(Ball *new_ball);
    void display_pokedex() const;
    void display_ball_inventory() const;
    std::string get_username() const;
    // ~User(); future deconstructor
};

#endif