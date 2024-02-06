# PokeCPLUS


## Version: 0.0.1-alpha

## Overview

Welcome to Pokemon CPLUS, a text-based Pokemon simulator written in C++. This project allows you to catch and showcase Pokemon using different types of Pokeballs. Explore the world of Pokemon, build your collection, and become a Pokemon master!

## WHATS NEW!?
- SHINIES, there will be a fully implemented shiny system in play!
- COMBAT POWER, pokemons will now have a combat power (cp) system, the higher the cp the stronger your pokemon!
- HIT POINTS, pokemons will now have a hit point (hp) system

## Features

- Catch Pokemon using various Pokeballs with different catch chances.
- Showcase your Pokemon collection.
- Simple text-based interface.
- User-friendly menu system.

## REQUIREMENTS TO PLAY
1. To play the current state of the game it is crucial to have a Windows machine (Windows OS).
2. To play the current state of the game it is crucial to have a Mingw compiler (x64) installed in your machine -- check this link out for a decent guide on how to install a MingW64 compiler [mingw64 installation guide](https://code.visualstudio.com/docs/cpp/config-mingw)
[ NOTE ] to ignore vscode, ignore the prequisites and stop after step 7.
[ NOTE ] typically the best way to know if you have it installed properly is to execute the following command in your terminal `g++ --version`


## How to Play

1. Run the program.
2. Enter your username to start your Pokemon journey.
3. Receive daily Pokeballs.

**Explore the menu (not finalized)**

1. Catch Pokemon
2. Showcase Pokemon
3. Exit

## BUILT WITH CMAKE

### HOW TO RUN EXECUTABLE :
## !! PROJECT USES CMAKE !! 
### FOLLOW STEPS TO BUILD PROJECT
- `cd "path_to_project_folder"`
- `mkdir build`
- `cd build`
- `cmake -G "preferred-generator" ..` e.g.. `cmake -G "MinGW Makefiles" ..`
- if preferred generator is MinGW use `mingw32-make` to build
- `./poke`

Follow the on-screen instructions to navigate through the game.

# Contributors

- Arya Sharifai

# License

This project is licensed under the MIT License.