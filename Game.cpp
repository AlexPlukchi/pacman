//
//  Game.cpp
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

#include "Map.hpp"
#include "Character.hpp"
#include "Pacman.hpp"
#include "Enemy.hpp"
#include "Dots.hpp"
#include "Game.hpp"

Game::Game()
{
    enemy = new Enemy[4];
    enemy[0].init(8, 10, 1, 1);
    enemy[1].init(9, 10, 1, 17);
    enemy[2].init(10, 10, 17, 1);
    enemy[3].init(8, 10, 17, 17);
    
    dir = 0;
    Dots::score = 0;
    
    if (!font.loadFromFile(resourcePath() + "res/arial.ttf"))
        return 1;
    text.setFont(font);
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::Green);
    text.setStyle(sf::Text::Bold);
    text.setString("Press P to play, Q to quit");
    score.setFont(font);
    score.setCharacterSize(50);
    score.setFillColor(sf::Color::Blue);
    
    global_clock.restart();
}

Game::~Game()
{
    delete[] enemy;
}

bool Game::play()
{
    sf::RenderWindow window(sf::VideoMode(X*N, X*N + 100), "Packman");
    score.setString("Score");
    score.setPosition(window.getSize().x/2 - score.getGlobalBounds().width/2, X*N + 10);
    while(window.isOpen())
    {
        clock.restart();
        double time;
        
        sf::Event event;
        while(window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    return false;
                    
                case sf::Event::KeyPressed:
                    switch(event.key.code)
                {
                    case sf::Keyboard::Left:
                        dir = 1;
                        break;
                        
                    case sf::Keyboard::Down:
                        dir = 2;
                        break;
                        
                    case sf::Keyboard::Right:
                        dir = 3;
                        break;
                        
                    case sf::Keyboard::Up:
                        dir = 4;
                        break;
                        
                    default:
                        break;
                }
                    
                default:
                    break;
            }
        }
        pacman.go(dir);
        dots.check(&pacman);
        
        window.clear();
        n_of_e = (int)global_clock.getElapsedTime().asSeconds()/10.0 + 1;
        for(int i = 0; i < n_of_e && i < 4; i++)
        {
            enemy[i].walk(&pacman);
            if(enemy[i].check_fail(&pacman))
            {
                text.setString("FAIL\n\nPress R to repeat, Q to close");
                window.close();
                return true;
            }
        }
        if(dots.draw(&window))
        {
            text.setString("WICTORY\n\nPress R to repeat, Q to close");
            window.close();
            return true;
        }
        map.draw(&window);
        pacman.draw(&window);
        for(int i = 0; i < 4; i++)
            enemy[i].draw(&window);
        score.setString(dots.get_strscore());
        window.draw(score);
        window.display();
        do
            time = clock.getElapsedTime().asSeconds();
        while(time < 0.002);
    }
    return true;
}

bool Game::end()
{
    sf::RenderWindow window(sf::VideoMode(X*N, X*N + 100), "Packman");
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    return false;
                    
                case sf::Event::KeyPressed:
                    switch(event.key.code)
                {
                    case sf::Keyboard::R: // Replay
                        window.close();
                        return true;
                        
                    case sf::Keyboard::Q: // Quit
                        window.close();
                        return false;
                        
                    default:
                        break;
                }
                    
                default:
                    break;
            }
        }
        text.setPosition(window.getSize().x/2 - text.getGlobalBounds().width/2, window.getSize().y/2 - text.getGlobalBounds().height/2);
        window.clear();
        dots.draw(&window);
        map.draw(&window);
        pacman.draw(&window);
        for(int i = 0; i < 4; i++)
            enemy[i].draw(&window);
        window.draw(score);
        window.draw(text);
        window.display();
    }
}
