#ifndef POKEMON_H
#define POKEMON_H
#include <iostream>
#include <optional>
#include "../includes/console_gui/Gui.h"

typedef struct PokeType
{
    std::string pokemon_primary_type_name;
    std::optional<std::string> pokemon_secondary_type_name;
    int primary_type_color;
    std::optional<int> secondary_type_color;
} PokeType;

class Pokemon
{
private:
    std::string m_pokemon_name;
    PokeType *m_type;
    bool m_is_shiny;
    bool m_is_legendary;
    void m_set_pokemon_type(std::string primary_type, std::optional<std::string> secondary_type);
    GUI::Colors m_get_primary_type_color(std::string primary_type) const;
    GUI::Colors m_get_secondary_type_color(std::optional<std::string> secondary_type) const;

public:
    Pokemon(std::string name, std::string primary_type, std::optional<std::string> secondary_type, bool is_legendary);

    std::string get_name() const;
    PokeType *get_pokemon_type() const;
    void display_pokemon() const;
    void set_shiny();
    bool get_is_shiny() const;
    bool get_is_legendary() const;
    void display_pokemon_type() const;
    void display_fled() const;
};

#endif