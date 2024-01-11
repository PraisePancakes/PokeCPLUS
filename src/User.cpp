#include "../includes/User.h"

User::User(std::string username) : m_username(username){};

std::string User::get_username() const
{
    return m_username;
}

void User::display_pokedex() const
{
    for (size_t i = 0; i < m_pokedex.size(); ++i)
    {
        std::cout << "POKEMON [" << i << "] " << m_pokedex[i].get_name()
                  << "\n";
    };
}