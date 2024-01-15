#include "../includes/User.h"
#include <unistd.h>

User::User(std::string username) : m_username(username)
{
    m_init_ball_inventory();
};

std::string User::get_username() const
{
    return m_username;
}

void User::display_pokedex() const
{
    for (size_t i = 0; i < m_pokedex.size(); ++i)
    {
        std::cout << "{" << i + 1 << "} ";
        m_pokedex[i].display_pokemon();
    };
}

void User::push_to_pokedex(Pokemon *new_pokemon)
{
    m_pokedex.push_back(*new_pokemon);
};

void User::push_to_ball_inventory(Ball *new_ball)
{
    m_ball_inventory.push_back(*new_ball);
    delete new_ball;
};

void User::m_init_ball_inventory()
{

    Ball *new_ball = nullptr;

    new_ball = new Ball("Pokeball");
    push_to_ball_inventory(new_ball);

    new_ball = new Ball("Greatball");
    push_to_ball_inventory(new_ball);

    new_ball = new Ball("Ultraball");
    push_to_ball_inventory(new_ball);

    new_ball = new Ball("Masterball");
    push_to_ball_inventory(new_ball);
}

void User::display_ball_inventory() const
{
    for (int i = 0; i < m_ball_inventory.size(); i++)
    {
        std::cout << " " << m_ball_inventory[i].get_ball_type() << " " << m_ball_inventory[i].get_ball_mult() << "\n";
    }
}

void User::walk() const
{
    const unsigned short int MAX_WALK = 3;
    unsigned short int curr_walk = 0;
    const unsigned short int WALK_DURATION = 2;

    while (curr_walk != MAX_WALK)
    {
        std::cout << "WALKING ... \n";
        sleep(WALK_DURATION);
        curr_walk++;
    }
}