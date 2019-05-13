//
//  Character.cpp
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

extern int MAP_PRE[N][N];
extern int MAP[N][N];

#include "Character.hpp"

void Character::go(int _dir)
{
    if(_dir != 0)
    {
        if(MAP[(int)floor((x + ((_dir - 2)%2)*(ds + X/2))/X)][(int)floor((y + ((3 - _dir)%2)*(ds + X/2))/X)] != 1 && ((_dir%2 == 0 && abs(x/X - trunc(x/X) - 0.5) < ds/X) || (_dir%2 == 1 && abs(y/X - trunc(y/X) - 0.5) < ds/X)))
        {
            dir = _dir;
            x += ((dir - 2)%2)*ds;
            y += ((3 - dir)%2)*ds;
        }
        else if(dir != 0)
        {
            if(MAP[(int)floor((x + ((dir - 2)%2)*(ds + X/2))/X)][(int)floor((y + ((3 - dir)%2)*(ds + X/2))/X)] != 1)
            {
                x += ((dir - 2)%2)*ds;
                y += ((3 - dir)%2)*ds;
            }
        }
    }
}
