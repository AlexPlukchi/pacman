#ifndef Character_h
#define Character_h

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

void Character::go(int _dir)
{
    if(_dir != 0)
    {
        if(MAP[(int)floor((x + ((_dir - 2)%2)*(ds + X/2))/X)][(int)floor((y + ((3 - _dir)%2)*(ds + X/2))/X)] != 1 && abs(x/X - trunc(x/X) - 0.5) < ds/X && abs(y/X - trunc(y/X) - 0.5) < ds/X)
        {
            dir = _dir;
            x += ((dir - 2)%2)*ds;
            y += ((3 - dir)%2)*ds;
        }
        else if(dir != 0)
        {
            if(MAP[(int)floor((x + ((dir - 2)%2)*(ds + X/2))/X)][(int)floor((y + ((3 - dir)%2)*(ds + X/2))/X)] != 1)
            {
                x += ((dir - 2)%2)*ds;
                y += ((3 - dir)%2)*ds;
            }
        }
    }
}

#endif /* Character_h */
