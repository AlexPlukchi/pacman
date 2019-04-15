#ifndef Dots_h
#define Dots_h
#include "Map_Generating.h"
class Dots
{
protected:
    sf::SoundBuffer buffer;
    sf::Sound sound;
    int map[N][N];
public:
    Dots();
    void draw(sf::RenderWindow* window);
    void check(int i, int j);
    void restart();
    Dots& operator= (const Dots &dots)
    {
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                map[i][j] = dots.map[i][j];
        return *this;
    }
};

Dots::Dots()
{
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            map[i][j] = MAP[i][j];
        }
    }
    buffer.loadFromFile(resourcePath() + "sound.wav");
    sound.setBuffer(buffer);
}

void Dots::draw(sf::RenderWindow* window)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(map[i][j] == 0)
            {
                sf::CircleShape shape;
                shape.setRadius(4);
                shape.setFillColor(sf::Color::Yellow);
                shape.setPosition(X*i + X/2, X*j + X/2);
                shape.setOrigin(4, 4);
                window -> draw(shape);
            }
        }
    }
}

void Dots::check(int i, int j)
{
    if(map[i][j] == 0)
    {
        ++score;
        sound.play();
        /*sf::SoundBuffer buffer;
        buffer.loadFromFile("sound.wav");
        sf::Sound sound;
        sound.setBuffer(buffer);*/
        sound.play();
        if(score == 100)
        {
            fail = -1;
        }
        map[i][j] = 2;
    }
}

void Dots::restart()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            map[i][j] = MAP[i][j];
        }
    }
}

#endif /* Dots_h */
