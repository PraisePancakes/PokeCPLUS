#include "../includes/User.h"
#include <unistd.h>
#include "../includes/console_gui/Gui.h"
#include <time.h>
#include <conio.h>

User::User(std::string username, unsigned long int balls_thrown, unsigned long int xp, unsigned long int level)
    : m_balls_thrown(balls_thrown), m_username(username), m_xp(xp), m_level(level)
{
    m_init_ball_inventory();
    Achievement *new_achievement = m_create_achievement("THE BEGINNING", "start your pokemon journey");
    m_push_achievement(new_achievement);
    m_showcase = nullptr;
};

std::string User::get_username() const
{
    return m_username;
}

void User::m_filter_level()
{
    const unsigned short int level = m_level;

    switch (m_xp)
    {
    case 1 ... 1000:
        m_level = 1;
        break;
    case 1001 ... 2000:
        m_level = 2;
        break;
    case 2001 ... 4000:
        m_level = 3;
        break;
    case 4001 ... 8000:
        m_level = 4;
        break;
    case 8001 ... 16000:
    {
        m_level = 5;
        Achievement *new_achievement = m_create_achievement("GLASS HALF FULL", "reach level 5");
        m_push_achievement(new_achievement);
    }

    break;
    case 16001 ... 32000:
        m_level = 6;
        break;
    case 32001 ... 64000:
        m_level = 7;
        break;
    case 64001 ... 128000:
        m_level = 8;
        break;
    case 128001 ... 256000:
        m_level = 9;
        break;
    case 256001 ... 512000:
        m_level = 10;
        break;
    }

    unsigned short int new_level = m_level;

    if (new_level > level)
    {
        GUI::style_cout(GUI::GREEN, std::cout, ":: YOU LEVELED UP! == LEVEL " + std::to_string(new_level) + " ::\n");
    }
}

void User::m_filter_pokeballs()
{
    for (int i = 0; i < m_ball_inventory.size(); i++)
    {
        if (m_ball_inventory[i].count == 0)
        {
            m_ball_inventory.erase(m_ball_inventory.begin() + i);
        }
    }
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

int User::get_ball_inventory_size() const
{
    return m_ball_inventory.size();
}

void User::push_to_pokedex(Pokemon *new_pokemon)
{
    m_pokedex.push_back(*new_pokemon);
};

void User::push_to_ball_inventory(Ball *new_ball)
{
    BallItem new_item;
    new_item.ball = std::make_unique<Ball>(*new_ball);
    new_item.count = 1;

    m_ball_inventory.push_back(std::move(new_item));
};
void User::display_achievements() const
{
    for (int i = 0; i < m_achievements.size(); i++)
    {
        GUI::style_cout(GUI::MAGENTA, std::cout, std::to_string(i) + " " + m_achievements[i].title + "\n");
    }
};
Achievement *User::m_create_achievement(std::string title, std::string desc)
{
    Achievement *new_achievement = new Achievement{title, desc};
    return new_achievement;
}

void User::m_push_achievement(Achievement *achievement)
{
    m_achievements.push_back(*achievement);
}

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

    delete new_ball;
}

void User::display_ball_inventory()
{
    if (get_ball_inventory_size() == 0)
    {
        GUI::style_cout(GUI::RED, std::cout, ":: OUT OF POKEBALLS ::\n");
        return;
    }
    m_filter_pokeballs();
    for (int i = 0; i < m_ball_inventory.size(); i++)
    {
        if (m_ball_inventory[i].ball->get_ball_type().compare("Pokeball") == 0)
        {
            GUI::style_cout(GUI::RED, std::cout, std::to_string(i) + " | " + std::to_string(m_ball_inventory[i].count) + " x Pokeballs\n");
        }
        else if (m_ball_inventory[i].ball->get_ball_type().compare("Greatball") == 0)
        {
            GUI::style_cout(GUI::BLUE, std::cout, std::to_string(i) + " | " + std::to_string(m_ball_inventory[i].count) + " x Greatballs\n");
        }
        else if (m_ball_inventory[i].ball->get_ball_type().compare("Ultraball") == 0)
        {
            GUI::style_cout(GUI::YELLOW, std::cout, std::to_string(i) + " | " + std::to_string(m_ball_inventory[i].count) + " x Ultraballs\n");
        }
        else if (m_ball_inventory[i].ball->get_ball_type().compare("Masterball") == 0)
        {
            GUI::style_cout(GUI::MAGENTA, std::cout, std::to_string(i) + " | " + std::to_string(m_ball_inventory[i].count) + " x Masterballs\n");
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
    GUI::style_cout(GUI::GREEN, std::cout, "\tXp : ");
    GUI::style_cout(GUI::MAGENTA, std::cout, std::to_string(m_xp));
    GUI::style_cout(GUI::GREEN, std::cout, "\tLevel : ");
    GUI::style_cout(GUI::MAGENTA, std::cout, std::to_string(m_level));
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
        if (m_ball_inventory[i].count > 0 && m_ball_inventory[i].ball->get_ball_type() == ball->get_ball_type())
        {
            m_ball_inventory[i].count--;
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
    m_xp += 50;

    if (ball->get_ball_type() == "Masterball")
    {
        m_xp += 300;
        m_filter_level();
        return true;
    }

    if (pokemon->get_is_legendary())
    {
        catch_chance_modifiable_ciel = 200;
        success = (rand() % catch_chance_modifiable_ciel - CATCH_CHANCE_MIN) + CATCH_CHANCE_MIN;
        success += ball->get_ball_mult();

        if (success == 69)
        {
            m_xp += 1000;
            m_filter_level();
            return true;
        }
        return false;
    }
    else
    {
        success = (rand() % catch_chance_modifiable_ciel - CATCH_CHANCE_MIN) + CATCH_CHANCE_MIN;

        if (success >= 2)
        {
            m_xp += 500;
            m_filter_level();
            return true;
        }

        return false;
    }
};

std::experimental::optional<Ball> User::choose_ball()
{
    if (get_ball_inventory_size() - 1 == 0)
    {
        GUI::style_cout(GUI::RED, std::cout, " :: YOU RAN OUT OF POKEBALLS :: \n");

        return std::experimental::nullopt;
    }
    int option = 0;
    display_ball_inventory();
    std::cin >> option;

    return *(m_ball_inventory[option].ball);
}