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
#include "Enemy.hpp"
#include "Dots.hpp"

int Dots::score = 0;

Dots::Dots()
{
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            map[i][j] = MAP[i][j];
    win = 0;
    
    buffer_chomp.loadFromFile(resourcePath() + "res/chomp.wav");
    chomp.setBuffer(buffer_chomp);
    
    buffer_eatfruit.loadFromFile(resourcePath() + "res/eatfruit.wav");
    eatfruit.setBuffer(buffer_eatfruit);
}

bool Dots::draw(sf::RenderWindow* window)
{
    win = 1;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
        {
            if(map[i][j] == 0)
            {
                win = 0;
                sf::CircleShape shape;
                shape.setRadius(X/10);
                shape.setFillColor(sf::Color::Yellow);
                shape.setPosition(X*i + X/2, X*j + X/2);
                shape.setOrigin(shape.getRadius(), shape.getRadius());
                window -> draw(shape);
            }
            else if(map[i][j] == 3)
            {
                win = 0;
                sf::CircleShape shape;
                shape.setRadius(X/4);
                shape.setFillColor(sf::Color::Yellow);
                shape.setPosition(X*i + X/2, X*j + X/2);
                shape.setOrigin(shape.getRadius(), shape.getRadius());
                window -> draw(shape);
            }
        }
    if(win == 1)
        return true;
    return false;
}

std::string Dots::get_strscore()
{
    std::stringstream ss;
    ss.str("");
    ss << "Score - " << score;
    return ss.str();
}

void Dots::check(Pacman* p)
{
    int i = (int)floor(p->x/X);
    int j = (int)floor(p->y/X);
    if(map[i][j] == 0) {
        if(chomp.getStatus() != sf::Music::Playing) {
            chomp.play();
        }
        ++score;
        map[i][j] = 2;
    }
    else if(map[i][j] == 3) {
        chomp.stop();
        eatfruit.play();
        Enemy::make_fear();
        map[i][j] = 2;
    }
}
