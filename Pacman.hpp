#ifndef Pacman_hpp
#define Pacman_hpp

class Enemy;
class Dots;

class Pacman : public Character
{
    sf::Texture texture[2];
public:
    Pacman();
    void draw(sf::RenderWindow* window);
    friend Enemy;
    friend Dots;
};

#endif /* Pacman_hpp */
