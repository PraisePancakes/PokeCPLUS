# PokeCPLUS


## Version: 0.0.1-alpha

## Overview

Welcome to Pokemon CPLUS, a text-based Pokemon simulator written in C++. This project allows you to catch and showcase Pokemon using different types of Pokeballs. Explore the world of Pokemon, build your collection, and become a Pokemon master!

## WHATS NEW!?
- SHINIES, there will be a fully implemented shiny system in play!
- LEGENDARIES, there will be a fully implemented legendary system in play!
- COMBAT POWER, pokemons will now have a combat power (cp) system, the higher the cp the stronger your pokemon! [NOT YET IMPLEMENTED]
- HIT POINTS, pokemons will now have a hit point (hp) system [NOT YET IMPLEMENTED]
- SERIALIZATION (thank you cereal ;}), your account will now be seamlessly saved! 

## Features

- Catch Pokemon using various Pokeballs with different catch chances.
- Showcase your Pokemon collection.
- Simple text-based interface.
- User-friendly menu system.

## REQUIREMENTS TO PLAY
1. To play the current state of the game it is crucial to have a Windows machine (Windows OS). [ NOTE ] cross compatability has not yet been tested, may or may not work seamlessly
2. To play the current state of the game it is crucial to have a Mingw compiler (x64) installed in your machine -- check this link out for a decent guide on how to install a MingW64 compiler [mingw64 installation guide](https://code.visualstudio.com/docs/cpp/config-mingw)  [ NOTE ] backwards compatability has not yet been tested, may or may not work seamlessly
[ NOTE ] to ignore vscode, ignore the prequisites and stop after step 7.
[ NOTE ] typically the best way to know if you have it installed properly is to execute the following command in your terminal `g++ --version`


## How to Play

0. Download the zip file, and unzip the game into your preferred directory.
1. Run the program executable found in the root project directory.
2. Enter your username to start your Pokemon journey.
3. Receive daily Pokeballs.

**Explore the menu (not finalized)**

1. Catch Pokemon
2. View your pokedex
3. Showcase pokemon
4. View your pokeballs
5. View achievements *
6. Exit

\\* new menu addition


## BUILT WITH CMAKE

### HOW TO RUN EXECUTABLE :
## !! PROJECT USES CMAKE !! 
### FOLLOW STEPS TO BUILD PROJECT
- `cd "path_to_project_folder"`
- `mkdir build`
- `cd build`
- `cmake -G "preferred-generator" ..` e.g.. `cmake -G "MinGW Makefiles" ..`
- if preferred generator is MinGW use `mingw32-make` to build
- the executable target is in the root directory of the project, if you are in the build directory make sure you do `cd ..` befor you do `./poke`

Follow the on-screen instructions to navigate through the game.

# Contributors

- Arya Sharifai

# License

This project is licensed under the MIT License.