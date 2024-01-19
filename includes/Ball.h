#ifndef BALL_H
#define BALL_H
#include <iostream>


class Ball
{

private:
    std::string m_ball_type;
    unsigned short int m_ball_modifier; // type == "pokeball" mod : 1 , type == "greatball" mod : 5, type == "ultraball" mod : 7, type == "masterball" mod : 10
    void m_set_ball_modifier(std::string ball_type);

public:
    Ball(std::string ball_type);
    std::string get_ball_type() const;
    unsigned short int get_ball_mult() const;
};

#endif