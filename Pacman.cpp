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

#include "Character.hpp"
#include "Pacman.hpp"

Pacman::Pacman()
{
    x = N*X/2;
    y = (N + 14)*X/2;
    texture[0].loadFromFile(resourcePath() + "res/pacman1.png", sf::IntRect(0, 0, 225, 225));
    texture[1].loadFromFile(resourcePath() + "res/pacman2.png", sf::IntRect(0, 0, 225, 225));
    dir = 0;
    ds = (double)X/100;
}

void Pacman::draw(sf::RenderWindow* window)
{
    sf::CircleShape shape;
    shape.setRadius(X/2);
    //shape.setFillColor(sf::Color::Yellow);
    shape.setPosition(x, y);
    shape.setOrigin(X/2, X/2);
    shape.setTexture(&texture[(int)(0.03*x + 0.03*y)%2]);
    shape.scale(dir == 1 ? -1 : 1, 1);
    shape.rotate(-90*((dir - 3)%2));
    window -> draw(shape);
}
