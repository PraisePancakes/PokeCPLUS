
cmake_minimum_required(VERSION 3.28.0)

project(PokeCPLUS, VERSION 0.0.0 LANGUAGES CXX)

add_executable("poke" src/main.cpp src/User.cpp src/console_gui/gui.cpp src/Pokemon.cpp)