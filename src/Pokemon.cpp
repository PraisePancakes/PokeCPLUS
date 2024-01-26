#include "../includes/Pokemon.h"
#include <time.h>

Pokemon::Pokemon(std::string name, std::string primary_type, std::optional<std::string> secondary_type, bool is_legendary)
    : m_pokemon_name(name), m_is_legendary(is_legendary), m_type(new PokeType)
{
    m_set_pokemon_type(primary_type, secondary_type);
};

GUI::Colors Pokemon::m_get_primary_type_color(std::string primary_type) const
{
    if (primary_type.compare("Fire") == 0)
    {
        return GUI::RED;
    }
    else if (primary_type.compare("Water") == 0)
    {
        return GUI::LIGHTBLUE;
    }
    else if (primary_type.compare("Grass") == 0)
    {
        return GUI::GREEN;
    }
    else if (primary_type.compare("Flying") == 0)
    {
        return GUI::YELLOW;
    }
    if (primary_type.compare("Poison") == 0)
    {
        return GUI::MAGENTA;
    }
    else if (primary_type.compare("Psychic") == 0)
    {
        return GUI::LIGHTMAGENTA;
    }
    else if (primary_type.compare("Electric") == 0)
    {
        return GUI::YELLOW;
    }
    else if (primary_type.compare("ICE") == 0)
    {
        return GUI::CYAN;
    }
    else
    {
        return GUI::LIGHTGRAY;
    }
}

GUI::Colors Pokemon::m_get_secondary_type_color(std::optional<std::string> secondary_type) const
{
    if (secondary_type.value().compare("Fire") == 0)
    {
        return GUI::RED;
    }
    else if (secondary_type.value().compare("Water") == 0)
    {
        return GUI::LIGHTBLUE;
    }
    else if (secondary_type.value().compare("Grass") == 0)
    {
        return GUI::GREEN;
    }
    else if (secondary_type.value().compare("Flying") == 0)
    {
        return GUI::YELLOW;
    }
    if (secondary_type.value().compare("Poison") == 0)
    {
        return GUI::MAGENTA;
    }
    else if (secondary_type.value().compare("Psychic") == 0)
    {
        return GUI::LIGHTMAGENTA;
    }
    else if (secondary_type.value().compare("Electric") == 0)
    {
        return GUI::YELLOW;
    }
    else if (secondary_type.value().compare("Ice") == 0)
    {
        return GUI::CYAN;
    }
    else
    {
        return GUI::LIGHTGRAY;
    }
}

void Pokemon::m_set_pokemon_type(std::string primary_type, std::optional<std::string> secondary_type)
{

    if (secondary_type)
    {
        m_type->pokemon_secondary_type_name = secondary_type;
        m_type->secondary_type_color = m_get_secondary_type_color(secondary_type);
    }
    else
    {
        m_type->pokemon_secondary_type_name = std::nullopt;
    }

    m_type->pokemon_primary_type_name = primary_type;
    GUI::Colors primary_type_color = m_get_primary_type_color(primary_type);
    m_type->primary_type_color = primary_type_color;
}

PokeType *Pokemon::get_pokemon_type() const
{
    return m_type;
};

std::string Pokemon::get_name() const
{
    return m_pokemon_name;
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

bool Pokemon::get_is_legendary() const
{
    return m_is_legendary;
}

void Pokemon::display_pokemon_type() const
{
    PokeType *type = get_pokemon_type();
    auto secondary_type_name = type->pokemon_secondary_type_name;
    GUI::style_cout(GUI::CYAN, std::cout, " | Type :: ");
    GUI::style_cout(GUI::intToColor(type->primary_type_color), std::cout, type->pokemon_primary_type_name);
    if (secondary_type_name)
    {
        GUI::style_cout(GUI::DARKGRAY, std::cout, "/ ");
        GUI::style_cout(GUI::intToColor(type->secondary_type_color.value()), std::cout, "" + secondary_type_name.value());
    }

    GUI::style_cout(GUI::LIGHTCYAN, std::cout, " ]");
}

void Pokemon::display_pokemon() const
{

    if (get_is_shiny() && get_is_legendary())
    {
        GUI::style_cout(GUI::YELLOW, std::cout, "** SHINY LEGENDARY **");
    }
    else if (get_is_shiny() && !get_is_legendary())
    {
        GUI::style_cout(GUI::YELLOW, std::cout, "** SHINY **");
    }
    else if (get_is_legendary() && !get_is_shiny())
    {
        GUI::style_cout(GUI::YELLOW, std::cout, "** LEGENDARY **");
    }
    GUI::style_cout(GUI::LIGHTCYAN, std::cout, " [ " + get_name());
    display_pokemon_type();
};

void Pokemon::display_fled() const
{
    GUI::style_cout(GUI::RED, std::cout, ":: " + get_name());
    GUI::style_cout(GUI::RED, std::cout, " fled ::");
}