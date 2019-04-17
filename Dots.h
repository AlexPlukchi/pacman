#ifndef Dots_h
#define Dots_h

class Dots
{
    int map[N][N];
    int score;
    int win;
public:
    Dots();
    bool draw(sf::RenderWindow* window);
    std::string get_strscore();
    void check(Pacman* p);
};

Dots::Dots()
{
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            map[i][j] = MAP[i][j];
    win = 0;
    score = 0;
}

bool Dots::draw(sf::RenderWindow* window)
{
    win = 1;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
        {
            if(map[i][j] == 0)
            {
                win = 0;
                sf::CircleShape shape;
                shape.setRadius(X/10);
                shape.setFillColor(sf::Color::Yellow);
                shape.setPosition(X*i + X/2, X*j + X/2);
                shape.setOrigin(shape.getRadius(), shape.getRadius());
                window -> draw(shape);
            }
        }
    if(win == 1)
        return true;
    return false;
}

std::string Dots::get_strscore()
{
    std::stringstream ss;
    ss.str("");
    ss << "Score - " << score;
    return ss.str();
}

void Dots::check(Pacman* p)
{
    if(map[(int)floor(p->x/X)][(int)floor(p->y/X)] == 0)
    {
        ++score;
        map[(int)floor(p->x/X)][(int)floor(p->y/X)] = 2;
    }
}

#endif /* Dots_h */
