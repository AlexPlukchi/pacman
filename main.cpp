#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "ResourcePath.hpp"

const int N = 19; //numbers os quads
const int X = 40; //lenght of side

#include "Map.h"
#include "Character.h"
#include "Pacman.h"
#include "Enemy.h"
#include "Dots.h"
#include "Game.h"
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
