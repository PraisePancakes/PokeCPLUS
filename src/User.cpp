#include "../includes/User.h"

User::User(std::string username) : m_username(username){};

std::string User::get_username()
{
    return m_username;
}