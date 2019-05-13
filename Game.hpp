//
//  Game.hpp
//  Pacman 2.1
//
//  Created by Александр Плукчи on 13/05/2019.
//  Copyright © 2019 Александр Плукчи. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

class Game
{
    Map map;
    Dots dots;
    Pacman pacman;
    int dir; // 1 - left, 2 - down, 3 - right, 4 - up
    int n_of_e; //number of enemies
    Enemy* enemy;
    sf::Clock clock;
    sf::Clock global_clock;
    sf::Font font;
    sf::Text text;
    sf::Text score;
public:
    Game();
    ~Game();
    bool play();
    bool end(); //menu after play
};

#endif /* Game_hpp */
