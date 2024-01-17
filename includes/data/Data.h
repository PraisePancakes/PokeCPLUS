#ifndef DATA_H
#define DATA_H
#include <vector>
#include "../Pokemon.h"

class Data
{
private:
    std::vector<Pokemon> *m_pokemon_list;
    void m_init_pokemon_list();

public:
    Data();
    Pokemon *get_random_pokemon() const;
};

#endif