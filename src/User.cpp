#include "../includes/User.h"

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
        std::cout << "POKEMON [" << i << "] " << m_pokedex[i].get_name() << " " << m_pokedex[i].get_primary_type() << "\n";
    };
}
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
void User::push_to_pokedex(Pokemon *new_pokemon)
{
    m_pokedex.push_back(*new_pokemon);
};

void User::push_to_ball_inventory(Ball *new_ball)
{
    m_ball_inventory.push_back(*new_ball);
};

void User::display_ball_inventory() const
{
    for (int i = 0; i < m_ball_inventory.size(); i++)
    {
        std::cout << " " << m_ball_inventory[i].get_ball_type() << " " << m_ball_inventory[i].get_ball_mult();
    }
}