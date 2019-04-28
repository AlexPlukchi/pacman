#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "ResourcePath.hpp"

#define N 19 //numbers os quads
#define X 40 //lenght of side

#include "Map.h"
#include "Character.h"
#include "Pacman.h"
#include "Dots.h"
#include "Enemy.h"
#include "Game.h"
#include "Menu.h"

int main()
{
    Game* game = new Game;
    if(menu())
        game -> play();
    while(game -> end())
    {
        delete game;
        game = new Game;
        game -> play();
    }
    return 0;
}
