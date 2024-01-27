#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H
#include "Pokemon.h"
#include <iostream>
#include <vector>
#include "Ball.h"
#include <memory>
#include <optional>
#include "User.h"

namespace SERIALIZABLE
{

    typedef struct SerializablePlayer
    {
        std::string username;
        std::vector<Pokemon> pokedex;
        std::vector<BallItem> ball_inventory;
        std::vector<Achievement> achievements;
        Pokemon *showcase;
        unsigned long int balls_thrown;
        unsigned long int xp;
        unsigned short int level;

    } SerializablePlayer;

    SerializablePlayer *make_serializable(User *user);
}

#endif