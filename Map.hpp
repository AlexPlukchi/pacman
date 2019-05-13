//
//  Map.hpp
//  Pacman 2.1
//
//  Created by Александр Плукчи on 13/05/2019.
//  Copyright © 2019 Александр Плукчи. All rights reserved.
//

#ifndef Map_hpp
#define Map_hpp

class Map
{
    int map[N][N];
public:
    Map();
    void draw_rect(sf::RenderWindow* window, int i, int j, int k);
    void draw(sf::RenderWindow* window);
};

#endif /* Map_hpp */
