#include <iostream>
#include "../../includes/data/Data.h"
#include <experimental/optional>
#include <math.h>
#include <time.h>

Data::Data()
{
    m_init_pokemon_list();
    m_ptr_to_pokemon_list = m_pokemon_list.data();
};

void Data::m_init_pokemon_list()
{
    m_pokemon_list.push_back(Pokemon("Charizard", "Fire", "Flying", false));
    m_pokemon_list.push_back(Pokemon("Bulbasaur", "Grass", "Poison", false));
    m_pokemon_list.push_back(Pokemon("Squirtle", "Water", std::experimental::nullopt, false));
    m_pokemon_list.push_back(Pokemon("Mewtwo", "Psychic", std::experimental::nullopt, true));
    m_pokemon_list.push_back(Pokemon("Pikachu", "Electric", std::experimental::nullopt, false));
    m_pokemon_list.push_back(Pokemon("Jigglypuff", "Normal", "Fairy", false));
    m_pokemon_list.push_back(Pokemon("Gyarados", "Water", "Flying", false));
    m_pokemon_list.push_back(Pokemon("Alakazam", "Psychic", std::experimental::nullopt, false));
    m_pokemon_list.push_back(Pokemon("Snorlax", "Normal", std::experimental::nullopt, false));
    m_pokemon_list.push_back(Pokemon("Articuno", "Ice", "Flying", true));
};

Pokemon *Data::get_random_pokemon() const
{
    srand(time(NULL));

    size_t random_index = ceil(rand() % m_pokemon_list.size());

    return m_ptr_to_pokemon_list + random_index;
}
