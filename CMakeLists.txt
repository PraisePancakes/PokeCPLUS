
cmake_minimum_required(VERSION 3.28.0)

project(PokeCPLUS, VERSION 0.0.0 LANGUAGES CXX)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/exe)



add_executable("poke" src/main.cpp src/User.cpp src/console_gui/Gui.cpp src/Pokemon.cpp src/Ball.cpp src/pokeData/Data.cpp src/Environment.cpp)

