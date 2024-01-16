#ifndef POKEMON_H
#define POKEMON_H
#include <iostream>
#include <experimental/optional>

typedef struct PokeType
{
    std::string pokemon_primary_type_name;
    std::experimental::optional<std::string> pokemon_secondary_type_name;
    int primary_type_color;
    std::experimental::optional<int> secondary_type_color;
} PokeType;

class Pokemon
{
private:
    std::string m_pokemon_name;
    /*
        pass type struct pointer here , PokeType* type :: access its attributes, type->primary_type_color etc...
    */
    PokeType *m_type;
    std::string m_pokemon_primary_type;
    std::experimental::optional<std::string> m_pokemon_secondary_type; // value or NULL
    bool m_is_shiny;
    bool m_is_legendary;
    void m_set_pokemon_type();

public:
    Pokemon(std::string name, std::string primary_type, std::experimental::optional<std::string> secondary_type, bool is_legendary);

    std::string get_name() const;
    std::string get_primary_type() const;
    std::experimental::optional<std::string> get_secondary_type() const;
    void display_pokemon() const;
    void set_shiny();
    bool get_is_shiny() const;
    bool get_is_legendary() const;
};

#endif