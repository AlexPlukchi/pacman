#ifndef Strawberry_h
#define Strawberry_h
#include "Map_Generating.h"
class Strawberry: public Dots
{
private:
    sf::Texture texture;
public:
    sf::SoundBuffer buffer;
    sf::Sound sound;
    Strawberry();
    void draw(sf::RenderWindow* window);
    void check(int i, int j);

};
Strawberry::Strawberry()
{
    texture.loadFromFile(resourcePath()+"straw.png");//, sf::IntRect(0, 0, 225, 225));
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            map[i][j] = MAP[i][j];
        }
    }
    buffer.loadFromFile(resourcePath() + "sound_straw.wav");
    sound.setBuffer(buffer);
}
void Strawberry::draw(sf::RenderWindow* window)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(map[i][j] == 3)
            {
                sf::RectangleShape shape;
                shape.setSize(sf::Vector2f(X*2/3, X*2/3));
                shape.setPosition(X*i+X/4, X*j+X/4);
                shape.setTexture(&texture);
                window -> draw(shape);
            }
        }
    }
}

void Strawberry::check(int i, int j)
    {
        if(map[i][j] == 3)
        {
            score+=3;
            sound.play();
            if(score == 100)
            {
                fail = -1;
            }
            map[i][j] = 2;
            enemy_regime = 1;
        }
    }


#endif /* Strawberry_h */
