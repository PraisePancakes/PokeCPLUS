
cmake_minimum_required(VERSION 3.28.0)

project(PokeCPLUS, VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../exe)
set(BOOST_ROOT "C:/boost-build")
set(Boost_INCLUDE_DIRS "C:/boost-build/include/boost-1_84")

find_package(Boost 1.84.0)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  add_executable("poke" src/main.cpp src/User.cpp src/console_gui/Gui.cpp src/Pokemon.cpp src/Ball.cpp src/pokeData/Data.cpp src/Environment.cpp)
  message(STATUS "FOUND BOOST ${Boost_VERSION}")
  else()
  message(STATUS "WEBSOCKET BOOST NOT FOUND")
endif()










