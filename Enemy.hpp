//
//  Enemy.hpp
//  Pacman 2.1
//
//  Created by Александр Плукчи on 13/05/2019.
//  Copyright © 2019 Александр Плукчи. All rights reserved.
//

#ifndef Enemy_hpp
#define Enemy_hpp

class Enemy : public Character
{
    sf::RectangleShape shape;
    sf::Texture ghost;
    sf::Texture gh_fear;
    sf::Texture gh_dead;
    static sf::Clock clock;
    sf::Clock dead_clock;
    sf::SoundBuffer buffer_eatghost;
    sf::Sound eatghost;
    sf::SoundBuffer buffer_death;
    sf::Sound death;
    static bool f; // fear - true or false
    int i0;
    int j0;
    bool dead;
public:
    Enemy();
    void init(int _xi, int _yi, int i0_, int j0_);
    void draw(sf::RenderWindow* window);
    int Lee(int i_beg, int j_beg, int i_end, int j_end); // Lee algorithm for walk()
    void walk(Pacman* p);
    bool check_fail(Pacman* p);
    static void make_fear();
};

#endif /* Enemy_hpp */
