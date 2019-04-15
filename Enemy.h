#ifndef Enemy_h
#define Enemy_h
#include "Enemy1.h"
class Enemy : public Character
{
    sf::Texture texture;
public:
    Enemy();
    Enemy& operator= (Enemy1 &enemy1);
    void init(int _xi, int _yi);
    void draw(sf::RenderWindow* window);
    void move_left();
    void move_down();
    void move_right();
    void move_up();
    void move(int p_xi, int p_yi);
    void check_fail(double p_x, double p_y);
};

Enemy::Enemy()
{
    r = X/2;
    count = 100;
    mov = 0;
    texture.loadFromFile(resourcePath()+"ghost.png", sf::IntRect(0, 0, 500, 500));
}

Enemy& Enemy::operator= (Enemy1 &enemy1)
{
    x = enemy1.get_x();
    y = enemy1.get_y();
    xi = enemy1.get_xi();
    yi = enemy1.get_yi();
    return *this;
}

void Enemy::init(int _xi, int _yi)
{
    x = _xi*X + X/2;
    xi = _xi;
    y = _yi*X + X/2;
    yi = _yi;
}
void Enemy::draw(sf::RenderWindow* window)
{
    sf::RectangleShape shape;
    shape.setSize(sf::Vector2f(2*r, 2*r));
    //shape.setFillColor(sf::Color::Red);
    shape.setPosition(x, y);
    shape.setOrigin(r, r);
    shape.setTexture(&texture);
    window -> draw(shape);
}
void Enemy::move_left()
{
    if(count > 0)
    {
        x -= 0.4;
        --count;
    }
    else
    {
        --xi;
        count = 100;
        mov = 0;
    }
    
}
void Enemy::move_down()
{
    if(count > 0)
    {
        y += 0.4;
        --count;
    }
    else
    {
        ++yi;
        count = 100;
        mov = 0;
    }
    
}
void Enemy::move_right()
{
    if(count > 0)
    {
        x += 0.4;
        --count;
    }
    else
    {
        ++xi;
        count = 100;
        mov = 0;
    }
    
}
void Enemy::move_up()
{
    if(count > 0)
    {
        y -= 0.4;
        --count;
    }
    else
    {
        --yi;
        count = 100;
        mov = 0;
    }
    
}
void Enemy::move(int p_xi, int p_yi)
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
void Enemy::check_fail(double p_x, double p_y)
{
    if(pow(p_x - x, 2) + pow(p_y - y, 2) < X*X/4)
    {
        fail = 1;
    }
}

#endif /* Enemy_h */
