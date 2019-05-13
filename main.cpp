#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "ResourcePath.hpp"

#define N 19 //numbers os quads
#define X 40 //lenght of side

extern int MAP_PRE[N][N];
extern int MAP[N][N];

#include "Map.hpp"
#include "Character.hpp"
#include "Pacman.hpp"
#include "Enemy.hpp"
#include "Dots.hpp"
#include "Game.hpp"
#include "Menu.h"

int main()
{
    Game* game = new Game;
    if(menu())
        while(game -> play() && game -> end())
        {
            delete game;
            game = new Game;
        }
    delete game;
    return 0;
}
