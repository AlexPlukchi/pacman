//
//  Map.cpp
//  Pacman 2.1
//
//  Created by Александр Плукчи on 13/05/2019.
//  Copyright © 2019 Александр Плукчи. All rights reserved.
//
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "ResourcePath.hpp"

#define N 19 //numbers os quads
#define X 40 //lenght of side

#include "Map.hpp"

int MAP_PRE[N][N] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 3, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 3, 1},
    {1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
    {1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 1, 1, 0, 1, 0, 1, 1, 9, 1, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 9, 9, 9, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 3, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 3, 1},
    {1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

int MAP[N][N];

Map::Map()
{
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++) {
            MAP[i][j] = MAP_PRE[j][i];
            map[i][j] = MAP[i][j];
        }
}

void Map::draw_rect(sf::RenderWindow* window, int i, int j, int k)
{
    float thick = 0.2;
    sf::RectangleShape shape;
    shape.setFillColor(sf::Color::Blue);
    shape.setSize(sf::Vector2f(X*((k + 1)%2) + X*(k%2)*thick, X*(k%2) + X*((k + 1)%2)*thick));
    shape.setPosition(X*i + (k == 1 ? 1 : 0)*X*(1 - thick), X*j + (k == 2 ? 1 : 0)*X*(1 - thick));
    //shape.setOutlineThickness(0); //??
    window -> draw(shape);
}

void Map::draw(sf::RenderWindow* window)
{
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
        {
            if(map[i][j] == 1)
            {
                if (j - 1 >= 0)
                    if (map[i][j - 1] != 1)
                        draw_rect(window, i, j, 0);
                if (i + 1 < N)
                    if (map[i + 1][j] != 1)
                        draw_rect(window, i, j, 1);
                if (j + 1 < N)
                    if (map[i][j + 1] != 1)
                        draw_rect(window, i, j, 2);
                if (i - 1 >= 0)
                    if (map[i - 1][j] != 1)
                        draw_rect(window, i, j, 3);
            }
        }
}
