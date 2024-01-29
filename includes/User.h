
#ifndef USER_H
#define USER_H

#include "Pokemon.h"
#include <iostream>
#include <vector>
#include "Ball.h"
#include <memory>
#include <optional>
#include <cereal/archives/json.hpp>

typedef struct BallItem
{
    std::unique_ptr<Ball> ball;
    int count;
} BallItem;

typedef struct Achievement
{
    std::string title;
    std::string desc;

} Achievement;

class User
{
private:
    std::string m_username;
    std::vector<Pokemon> m_pokedex;

    std::vector<BallItem> m_ball_inventory;
    std::vector<Achievement> m_achievements;
    std::unique_ptr<Pokemon> m_showcase;
    unsigned long int m_balls_thrown;
    unsigned long int m_xp;     // 100 xp for level 1, 200 xp for level 2 -> double each time
    unsigned short int m_level; // max level 50

private:
    void m_init_ball_inventory();
    void m_remove_ball(const Ball *ball);
    void m_filter_pokeballs();
    void m_filter_level();
    Achievement *m_create_achievement(std::string title, std::string desc);
    void m_push_achievement(Achievement *achievement);

public:
    User(std::string username, unsigned long int balls_thrown, unsigned long int xp, unsigned long int level); // arg list : username, pokedex, pokeballs
    template <class Archive>
    void serialize(Archive &ar)
    {
        ar(cereal::make_nvp("username", m_username),
           cereal::make_nvp("balls_thrown", m_balls_thrown),
           cereal::make_nvp("xp", m_xp),
           cereal::make_nvp("level", m_level));
    }
    bool throw_ball(const Ball *ball, Pokemon *pokemon);
    void push_to_pokedex(Pokemon *new_pokemon);
    void push_to_ball_inventory(Ball *new_ball);
    void display_achievements() const;
    void display_pokedex() const;
    void display_ball_inventory();
    Pokemon *get_starter_pokemon(unsigned short int selection_choice) const;
    void set_showcase_pokemon();
    void display_showcase_pokemon() const;
    void display_user_stats() const;
    unsigned long int get_balls_thrown() const;
    int get_ball_inventory_size() const;
    void walk() const;
    std::optional<Ball> choose_ball();
    std::string get_username() const;
    // ~User(); future deconstructor
};

#endif