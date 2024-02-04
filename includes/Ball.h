#ifndef BALL_H
#define BALL_H
#include <iostream>
#include <cereal/archives/json.hpp>
#include <cereal/types/vector.hpp>
class Ball
{

private:
    std::string m_ball_type;
    unsigned short int m_ball_modifier; // type == "pokeball" mod : 1 , type == "greatball" mod : 5, type == "ultraball" mod : 7, type == "masterball" mod : 10
    void m_set_ball_modifier(std::string ball_type);

public:
    Ball() = default;
    Ball(std::string ball_type);
    template <class Archive>
    void serialize(Archive &ar)
    {
        ar(cereal::make_nvp("ball_type", m_ball_type));
        ar(cereal::make_nvp("ball_modifier", m_ball_modifier));
    }
    std::string get_ball_type() const;
    unsigned short int get_ball_mult() const;
};

#endif