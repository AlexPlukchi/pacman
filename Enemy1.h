#ifndef Enemy1_h
#define Enemy1_h
#include "Enemy.h"
class Enemy1 : public Character
{
    sf::Texture texture;
public:
    Enemy1();
    Enemy1 set(Enemy1 enemy);
    void init(int _xi, int _yi);
    void draw(sf::RenderWindow* window);
    void move_left();
    void move_down();
    void move_right();
    void move_up();
    void move(int p_xi, int p_yi);
    void check_fail(double p_x, double p_y);
};
Enemy1::Enemy1()
{
    r = X/2;
    count = 200;
    mov = 0;
    texture.loadFromFile(resourcePath()+"ghost1.png", sf::IntRect(0, 0, 500, 500));
}

void Enemy1::init(int _xi, int _yi)
{
    x = _xi*X + X/2;
    xi = _xi;
    y = _yi*X + X/2;
    yi = _yi;
}

void Enemy1::draw(sf::RenderWindow* window)
{
    sf::RectangleShape shape;
    shape.setSize(sf::Vector2f(2*r, 2*r));
    //shape.setFillColor(sf::Color::Red);
    shape.setPosition(x, y);
    shape.setOrigin(r, r);
    shape.setTexture(&texture);
    window -> draw(shape);
}
void Enemy1::move_left()
{
    if(count > 0)
    {
        x -= 0.2;
        --count;
    }
    else
    {
        --xi;
        count = 200;
        mov = 0;
    }
    
}
void Enemy1::move_down()
{
    if(count > 0)
    {
        y += 0.2;
        --count;
    }
    else
    {
        ++yi;
        count = 200;
        mov = 0;
    }
    
}
void Enemy1::move_right()
{
    if(count > 0)
    {
        x += 0.2;
        --count;
    }
    else
    {
        ++xi;
        count = 200;
        mov = 0;
    }
    
}
void Enemy1::move_up()
{
    if(count > 0)
    {
        y -= 0.2;
        --count;
    }
    else
    {
        --yi;
        count = 200;
        mov = 0;
    }
    
}
void Enemy1::move(int p_xi, int p_yi)
{
    if(mov == 0)
    {
        if(p_yi - yi < 0 && MAP[xi][yi - 1] != 1)
        {
            mov = 1;
            move_up();
        }
        else if(p_yi - yi > 0 && MAP[xi][yi + 1] != 1)
        {
            mov = 2;
            move_down();
        }
        else if(p_xi - xi > 0 && MAP[xi + 1][yi] != 1)
        {
            mov = 3;
            move_right();
        }
        else if(p_xi - xi < 0 && MAP[xi - 1][yi] != 1)
        {
            mov = 4;
            move_left();
        }
    }
    else
    {
        switch (mov) {
            case 1:
                move_up();
                break;
            case 2:
                move_down();
                break;
            case 3:
                move_right();
                break;
            case 4:
                move_left();
                break;
                
            default:
                break;
        }
    }
}
void Enemy1::check_fail(double p_x, double p_y)
{
    if(pow(p_x - x, 2) + pow(p_y - y, 2) < X*X/4)
    {
        fail = 1;
    }
}


#endif /* Enemy1_h */
