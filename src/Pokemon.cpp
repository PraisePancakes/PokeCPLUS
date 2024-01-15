#include "../includes/Pokemon.h"
#include <time.h>

Pokemon::Pokemon(std::string name, std::string primary_type, std::experimental::optional<std::string> secondary_type, bool is_legendary)
    : m_pokemon_name(name), m_pokemon_primary_type(primary_type), m_pokemon_secondary_type(secondary_type), m_is_legendary(is_legendary){};

std::string Pokemon::get_name() const
{
    return m_pokemon_name;
}

std::string Pokemon::get_primary_type() const
{
    return m_pokemon_primary_type;
}

std::experimental::optional<std::string> Pokemon::get_secondary_type() const
{
    return m_pokemon_secondary_type;
}

void Pokemon::set_shiny()
{
    srand(time(NULL));

    const unsigned short int SHINY_MAX_RATE = 200;
    const unsigned short int SHINY_MIN_RATE = 1;

    unsigned short int SHINY_HIT = (rand() % SHINY_MAX_RATE - SHINY_MIN_RATE) + SHINY_MIN_RATE;

    SHINY_HIT >= 180 ? m_is_shiny = true : m_is_shiny = false;
}

bool Pokemon::get_is_shiny() const
{

    return m_is_shiny;
}

void Pokemon::display_pokemon() const
{
    auto secondary_type = get_secondary_type();

    if (get_is_shiny())
    {
        std::cout << "** SHINY **";
    }
    std::cout << " [ Pokemon :: " << get_name() << " || Type :: " << get_primary_type();
    if (secondary_type)
    {
        std::cout << " / " << secondary_type.value();
    }

    std::cout << "]\n";
};