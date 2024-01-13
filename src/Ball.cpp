#include "../includes/Ball.h"

Ball::Ball(std::string ball_type) : m_ball_type(ball_type)
{
    m_set_ball_multiplier(ball_type);
}

void Ball::m_set_ball_multiplier(std::string ball_type) // convert to hashed string
{
    unsigned short int mult = 0;

    if (ball_type.compare("Pokeball") == 0)
    {
        mult = 1;
    }
    else if (ball_type.compare("Greatball") == 0)
    {
        mult = 5;
    }
    else if (ball_type.compare("Ultraball") == 0)
    {
        mult = 7;
    }
    else if (ball_type.compare("Masterball") == 0)
    {
        mult = 10;
    }

    m_ball_multiplier = mult;
}

std::string Ball::get_ball_type() const
{
    return m_ball_type;
}

unsigned short int Ball::get_ball_mult() const
{
    return m_ball_multiplier;
}