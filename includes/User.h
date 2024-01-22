
#ifndef USER_H
#define USER_H

#include "Pokemon.h"
#include <iostream>
#include <vector>
#include "Ball.h"
#include <memory>

typedef struct BallItem
{
    std::unique_ptr<Ball> ball;
    int count;
} BallItem;

class User
{
private:
    std::string m_username;
    std::vector<Pokemon> m_pokedex;
    std::vector<BallItem> m_ball_inventory;
    Pokemon *m_showcase;
    unsigned long int m_balls_thrown;
    unsigned long int m_xp;     // 100 xp for level 1, 200 xp for level 2 -> double each time
    unsigned short int m_level; // max level 50

private:
    void m_init_ball_inventory();
    void m_remove_ball(const Ball *ball);
    void m_filter_pokeballs();
    void m_filter_level();

public:
    User(std::string username, unsigned long int balls_thrown, unsigned long int xp, unsigned long int level); // arg list : username, pokedex, pokeballs

    bool throw_ball(const Ball *ball, Pokemon *pokemon);
    void push_to_pokedex(Pokemon *new_pokemon);
    void push_to_ball_inventory(Ball *new_ball);
    void display_pokedex() const;
    void display_ball_inventory();
    Pokemon *get_starter_pokemon(unsigned short int selection_choice) const;
    void set_showcase_pokemon();
    void display_showcase_pokemon() const;
    void display_user_stats() const;
    unsigned long int get_balls_thrown() const;
    int get_ball_inventory_size() const;
    void walk() const;
    std::experimental::optional<Ball> choose_ball();
    std::string get_username() const;
    // ~User(); future deconstructor
};

#endif