#include "../includes/Ball.h"

Ball::Ball(std::string ball_type) : m_ball_type(ball_type)
{
    m_set_ball_modifier(ball_type);
}

void Ball::m_set_ball_modifier(std::string ball_type) // convert to hashed string
{
    unsigned short int mod = 0;

    if (ball_type.compare("Pokeball") == 0)
    {
        mod = 1;
    }
    else if (ball_type.compare("Greatball") == 0)
    {
        mod = 5;
    }
    else if (ball_type.compare("Ultraball") == 0)
    {
        mod = 7;
    }
    else if (ball_type.compare("Masterball") == 0)
    {
        mod = 10;
    }

    m_ball_modifier = mod;
}

std::string Ball::get_ball_type() const
{
    return m_ball_type;
}

unsigned short int Ball::get_ball_mult() const
{
    return m_ball_modifier;
}