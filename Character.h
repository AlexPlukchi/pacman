#ifndef Character_h
#define Character_h

class Character
{
protected:
    int r;
    int count;
    int mov;
    double vel;
public:
    double x;
    double y;
    int xi;
    int yi;
    virtual void draw(sf::RenderWindow* window) = 0;
    int get_xi();
    int get_yi();
    int get_x();
    int get_y();
};

int Character::get_xi()
{
    return xi;
}
int Character::get_yi()
{
    return yi;
}
int Character::get_x()
{
    return x;
}
int Character::get_y()
{
    return y;
}
#endif /* Character_h */
