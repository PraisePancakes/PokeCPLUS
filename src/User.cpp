#include "../includes/User.h"
#include <unistd.h>
#include "../includes/console_gui/Gui.h"

User::User(std::string username) : m_username(username)
{
    m_init_ball_inventory();
    m_showcase = nullptr;
    m_balls_thrown = 0;
};

std::string User::get_username() const
{
    return m_username;
}

void User::display_pokedex() const
{
    for (size_t i = 0; i < m_pokedex.size(); ++i)
    {
        std::cout << "{" << i + 1 << "} ";
        m_pokedex[i].display_pokemon();
        std::cout << "\n";
    };
}

void User::push_to_pokedex(Pokemon *new_pokemon)
{
    m_pokedex.push_back(*new_pokemon);
};

void User::push_to_ball_inventory(Ball *new_ball)
{
    m_balls_thrown++;
    m_ball_inventory.push_back(*new_ball);
    delete new_ball;
};

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

void User::display_ball_inventory() const
{
    for (int i = 0; i < m_ball_inventory.size(); i++)
    {
        if (m_ball_inventory[i].get_ball_type().compare("Pokeball") == 0)
        {
            GUI::style_cout(GUI::RED, std::cout, m_ball_inventory[i].get_ball_type() + "\n");
        }
        else if (m_ball_inventory[i].get_ball_type().compare("Greatball") == 0)
        {
            GUI::style_cout(GUI::LIGHTBLUE, std::cout, m_ball_inventory[i].get_ball_type() + "\n");
        }
        else if (m_ball_inventory[i].get_ball_type().compare("Ultraball") == 0)
        {
           GUI:: style_cout(GUI::YELLOW, std::cout, m_ball_inventory[i].get_ball_type() + "\n");
        }
        else if (m_ball_inventory[i].get_ball_type().compare("Masterball") == 0)
        {
            GUI::style_cout(GUI::MAGENTA, std::cout, m_ball_inventory[i].get_ball_type() + "\n");
        }
    }
}

void User::walk() const
{
    const unsigned short int MAX_WALK = 3;
    unsigned short int curr_walk = 0;
    const unsigned short int WALK_DURATION = 2;

    while (curr_walk != MAX_WALK)
    {
        std::cout << "WALKING ... \n";
        sleep(WALK_DURATION);
        curr_walk++;
    }
}

Pokemon *User::get_starter_pokemon(unsigned short int selection_choice) const
{
    Pokemon *starter_pokemon = nullptr;

    switch (selection_choice)
    {
    case 1:
        starter_pokemon = new Pokemon("Pikachu", "Lightning", std::experimental::nullopt, false);
        break;
    case 2:
        starter_pokemon = new Pokemon("Squirtle", "Water", std::experimental::nullopt, false);
        break;
    case 3:
        starter_pokemon = new Pokemon("Charmander", "Fire", std::experimental::nullopt, false);
        break;
    case 4:
        starter_pokemon = new Pokemon("Bulbasaur", "Grass", "Poison", false);
        break;
    default:
        std::cout << "[ERROR] INVALID STARTER OPTION\n";
    }

    return starter_pokemon;
}

void User::set_showcase_pokemon(Pokemon *pokemon)
{
    m_showcase = pokemon;
};

void User::display_showcase_pokemon() const
{
    if (m_showcase)
    {
        m_showcase->display_pokemon();
    }
    else
    {
        std::cout << "[ TBA ] \n";
    }
};

unsigned long int User::get_balls_thrown() const
{
    return m_balls_thrown;
}

void User::display_user_stats() const
{
    std::string username = get_username();
    unsigned long int balls_thrown = get_balls_thrown();

    std::cout << "YOUR STATS { \nUsername : " << username << " \nTotal pokeball throws : " << balls_thrown << " \nShowcase :: ";
    display_showcase_pokemon();
    std::cout << "}\n";
}