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
    bool m_is_legendary;
    void m_set_shiny();

public:
    Pokemon(std::string name, std::string primary_type, std::experimental::optional<std::string> secondary_type, bool is_legendary);

    std::string get_name() const;
    std::string get_primary_type() const;
    std::experimental::optional<std::string> get_secondary_type() const;
    bool get_is_shiny() const;
};

#endif