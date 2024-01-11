#ifndef POKEMON_H
#define POKEMON_H
#include <iostream>
#include <experimental/optional>

class Pokemon
{
private:
    std::string m_pokemon_name;
    std::string m_pokemon_primary_type;
    std::experimental::optional<std::string> m_pokemon_secondary_type; // value or NULL
    bool m_is_shiny;

public:
    Pokemon(std::string name, std::string primary_type, std::string secondary_type);

    bool set_is_shiny();
    ~Pokemon();
};

#endif