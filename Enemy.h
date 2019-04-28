#ifndef Enemy_h
#define Enemy_h

class Enemy : public Character
{
    sf::Texture texture;
public:
    Enemy();
    void init(int _xi, int _yi);
    void draw(sf::RenderWindow* window);
    void walk();
    bool check_fail(class Pacman* p);
};

Enemy::Enemy()
{
    dir = 0;
    ds = (double)X/120;
    texture.loadFromFile(resourcePath() + "res/ghost.png", sf::IntRect(0, 0, 500, 500));
}

void Enemy::init(int _xi, int _yi)
{
    x = _xi*X + X/2;
    y = _yi*X + X/2;
}

void Enemy::draw(sf::RenderWindow* window)
{
    sf::RectangleShape shape;
    shape.setSize(sf::Vector2f(X, X));
    shape.setPosition(x, y);
    shape.setOrigin(X/2, X/2);
    shape.setTexture(&texture);
    window -> draw(shape);
}

void Enemy::walk()
{
    int _dir = rand()%4 + 1;
    if((_dir + dir)%2 != 0)
        go(_dir);
    else
        go(dir);
}

bool Enemy::check_fail(Pacman* p)
{
    if(pow(p -> x - x, 2) + pow(p -> y - y, 2) < X*X)
        return true;
    return false;
}

#endif /* Enemy_h */
