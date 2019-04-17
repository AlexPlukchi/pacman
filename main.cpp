#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <sstream>

#include <SFML/Graphics.hpp>

#define N 19 //numbers os quads
#define X 40 //lenght of side

#include "Map.h"
#include "Character.h"
#include "Pacman.h"
#include "Dots.h"
#include "Enemy.h"
#include "Game.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(X*N, X*N + 100), "Packman");
    while(window.isOpen())
    {
        Game game;
        while(window.isOpen() && game.menu(&window))
        { }
        while(window.isOpen() && game.play(&window))
        { }
        while(window.isOpen() && game.menu(&window))
        { }
    }
    return EXIT_SUCCESS;
}
