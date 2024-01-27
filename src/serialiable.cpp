#include "../includes/serializable.h"

namespace SERIALIZABLE
{
    SerializablePlayer *make_serializable(User *user)
    {
        SerializablePlayer *serialiable = (SerializablePlayer *)malloc(sizeof(SerializablePlayer));
        // make serializable player and return the struct of current state;
        // serialize the state
    }
}