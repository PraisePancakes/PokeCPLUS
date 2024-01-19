#include "../includes/User.h"
#include <unistd.h>
#include "../includes/console_gui/Gui.h"
#include <time.h>

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
        std::cout << "{" << i << "} ";
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

            GUI::style_cout(GUI::RED, std::cout, std::to_string(i) + " " + m_ball_inventory[i].get_ball_type() + "\n");
        }
        else if (m_ball_inventory[i].get_ball_type().compare("Greatball") == 0)
        {
            GUI::style_cout(GUI::LIGHTBLUE, std::cout, std::to_string(i) + " " + m_ball_inventory[i].get_ball_type() + "\n");
        }
        else if (m_ball_inventory[i].get_ball_type().compare("Ultraball") == 0)
        {
            GUI::style_cout(GUI::YELLOW, std::cout, std::to_string(i) + " " + m_ball_inventory[i].get_ball_type() + "\n");
        }
        else if (m_ball_inventory[i].get_ball_type().compare("Masterball") == 0)
        {
            GUI::style_cout(GUI::MAGENTA, std::cout, std::to_string(i) + " " + m_ball_inventory[i].get_ball_type() + "\n");
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
        starter_pokemon = new Pokemon("Pikachu", "Electric", std::experimental::nullopt, false);
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

void User::set_showcase_pokemon()
{
    int option = 0;
    display_pokedex();
    std::cin >> option;
    while (option >= m_pokedex.size())
    {
        GUI::style_cout(GUI::RED, std::cout, "[ERROR] NO SUCH POKEMON EXISTS TRY AGAIN \n");
        std::cin >> option;
    }

    m_showcase = &(m_pokedex[option]);
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
    std::string string_balls_thrown = std::to_string(balls_thrown);

    GUI::style_cout(GUI::CYAN, std::cout, "YOUR STATS { \n");
    GUI::style_cout(GUI::GREEN, std::cout, "\tUsername : ");
    GUI::style_cout(GUI::MAGENTA, std::cout, username);
    GUI::style_cout(GUI::GREEN, std::cout, "\n\tTotal pokeball throws : ");
    GUI::style_cout(GUI::MAGENTA, std::cout, string_balls_thrown);
    GUI::style_cout(GUI::GREEN, std::cout, "\n\tShowcase :: ");
    display_showcase_pokemon();
    GUI::style_cout(GUI::CYAN, std::cout, "} \n");
}
void User::m_remove_ball(const Ball *ball)
{
    for (size_t i = 0; i < m_ball_inventory.size(); i++)
    {
        if (m_ball_inventory[i].get_ball_type().compare(ball->get_ball_type()) == 0)
        {
            m_ball_inventory.erase(m_ball_inventory.begin() + i);
            return;
        }
    }
}

bool User::throw_ball(const Ball *ball, Pokemon *pokemon)
{
    srand(time(NULL));
    int catch_chance_modifiable_ciel = 5;
    const int CATCH_CHANCE_MIN = 1;
    int success = 0;

    m_balls_thrown += 1;
    m_remove_ball(ball);
    if (pokemon->get_is_legendary())
    {
        catch_chance_modifiable_ciel = 200;

        success = (rand() % catch_chance_modifiable_ciel - CATCH_CHANCE_MIN) + CATCH_CHANCE_MIN;
        success += ball->get_ball_mult();
        if (success >= 188 && success <= 195 || ball->get_ball_type().compare("Masterball") == 0)
        {
            return true;
        }
        return false;
    }
    else
    {
        success = (rand() % catch_chance_modifiable_ciel - CATCH_CHANCE_MIN) + CATCH_CHANCE_MIN;
        if (success == 3 || success == 2)
        {
            return true;
        }

        return false;
    }
};

Ball User::choose_ball()
{
    int option = 0;
    display_ball_inventory();
    std::cin >> option;

    return m_ball_inventory[option];
}