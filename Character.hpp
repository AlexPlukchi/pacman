//
//  Character.hpp
//  Pacman 2.1
//
//  Created by Александр Плукчи on 13/05/2019.
//  Copyright © 2019 Александр Плукчи. All rights reserved.
//

#ifndef Character_hpp
#define Character_hpp

class Character
{
protected:
    double x;
    double y;
    int dir; // 1 - left, 2 - down, 3 - right, 4 - up
    double ds;
public:
    virtual void draw(sf::RenderWindow* window) = 0;
    void go(int _dir);
};

#endif /* Character_hpp */
