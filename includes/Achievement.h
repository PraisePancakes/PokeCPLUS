#ifndef ACHIEVEMENT_H
#define ACHIEVEMENT_H
#include <iostream>
#include <cereal/archives/json.hpp>
#include <cereal/types/vector.hpp>

enum ACHIEVEMENT_ID
{
    THE_BEGINNING = 0,
    LEVELED_UP,
    LEGEND,
    SHINY_SHOES,
    POKEDEX_BEGINNER,
    POKEDEX_INTERMEDIATE,
    POKEDEX_MASTER,
    POKEDEX_GRANDMASTER,
    BABY_STEPS,
    ROAD_RUNNER,
    IRON_MAN,
    THE_END,
    ERROR_MATCH = 404
};
// create an intialized array of achievements with all their properties
typedef struct Achievement
{
    std::string title;
    std::string desc;
    ACHIEVEMENT_ID id;
    bool has_completed = false;
    template <class Archive>
    void serialize(Archive &ar)
    {
        ar(cereal::make_nvp("title", title));
        ar(cereal::make_nvp("id", id));
        ar(cereal::make_nvp("desc", desc));
        ar(cereal::make_nvp("completed", has_completed));
    }

} Achievement;

#endif