#include "../includes/Pokemon.h"
#include <time.h>

Pokemon::Pokemon(std::string name, std::string primary_type, std::string secondary_type)
    : m_pokemon_name(name), m_pokemon_primary_type(primary_type), m_pokemon_secondary_type(secondary_type){};

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

    unsigned short int SHINY_HIT = (rand() % SHINY_MAX_RATE - SHINY_MIN_RATE) + SHINY_MAX_RATE;

    SHINY_HIT >= 180 ? m_is_shiny = true : m_is_shiny = false;

    return;
}