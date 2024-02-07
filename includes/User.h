
#ifndef USER_H
#define USER_H

#include "Pokemon.h"
#include <iostream>
#include <vector>
#include "Ball.h"
#include "Achievement.h"
#include <memory>
#include <optional>
#include <cereal/archives/json.hpp>
#include <cereal/types/vector.hpp>
#include <fstream>

typedef struct BallItem
{
    std::unique_ptr<Ball> ball;

    int count;
    template <class Archive>
    void serialize(Archive &ar)
    {

        ar(cereal::make_nvp("ball", ball));
        ar(cereal::make_nvp("count", count));
    }

} BallItem;

class User
{
private:
    std::string m_username;
    std::vector<Pokemon> m_pokedex;
    std::vector<BallItem> m_ball_inventory;
    std::vector<std::unique_ptr<Achievement>> m_achievements;
    std::unique_ptr<Pokemon> m_showcase;
    unsigned long int m_balls_thrown;
    unsigned long int m_xp;     // 100 xp for level 1, 200 xp for level 2 -> double each time
    unsigned short int m_level; // max level 50
    long long int m_steps;
    bool m_has_legendary_pokemon;
    long long int m_coins;

private:
    void m_init_ball_inventory();
    void m_remove_ball(const Ball *ball);
    void m_filter_pokeballs();
    void m_filter_level();
    void filter_achievements();
    std::unique_ptr<Achievement>
    m_create_achievement(std::string title, std::string desc, ACHIEVEMENT_ID id);
    void m_push_achievement(std::unique_ptr<Achievement> achievement);
    void init_achievements();

public:
    User(unsigned long int balls_thrown, unsigned long int xp, unsigned long int level); // init_achievements();
    template <class Archive>
    void serialize(Archive &ar)
    {
        ar(cereal::make_nvp("username", m_username),
           cereal::make_nvp("pokedex", m_pokedex),
           cereal::make_nvp("ball_inventory", m_ball_inventory),
           cereal::make_nvp("achievements", m_achievements),
           cereal::make_nvp("showcase", m_showcase),
           cereal::make_nvp("balls_thrown", m_balls_thrown),
           cereal::make_nvp("xp", m_xp),
           cereal::make_nvp("level", m_level),
           cereal::make_nvp("steps", m_steps),
           cereal::make_nvp("has_legendary_pokemon", m_has_legendary_pokemon),
           cereal::make_nvp("coins", m_coins));
    };

    void saveToFile(const std::string &filename) const
    {
        std::ofstream file(filename);
        cereal::JSONOutputArchive archive(file);
        archive(*this);
    }

    void loadFromFile(const std::string &filename)
    {
        std::ifstream file(filename);
        if (file.is_open())
        {
            cereal::JSONInputArchive archive(file);
            archive(*this);
            file.close();
        }
        else
        {
            // Handle file opening error
            std::cerr << "Error opening file: " << filename << std::endl;
        }
    }

    void subtract_coins(int amount);
    bool throw_ball(const Ball *ball, Pokemon *pokemon);
    void push_to_pokedex(Pokemon *new_pokemon);
    void push_to_ball_inventory(Ball *new_ball);
    void display_achievements();
    void display_pokedex() const;
    void set_username(std::string username);
    void display_ball_inventory();
    void buy_ball(std::string type, int amount);
    Pokemon *get_starter_pokemon(unsigned short int selection_choice) const;
    void set_showcase_pokemon();
    void display_showcase_pokemon() const;
    void display_user_stats() const;
    unsigned long int get_balls_thrown() const;
    int get_ball_inventory_size() const;
    int get_coins() const;
    void walk();
    std::optional<Ball> choose_ball();
    std::string get_username() const;
    // ~User(); future deconstructor
};

#endif