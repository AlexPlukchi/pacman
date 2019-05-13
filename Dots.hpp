#ifndef Dots_hpp
#define Dots_hpp

class Dots
{
    int map[N][N];
    int win;
public:
    Dots();
    static int score;
    bool draw(sf::RenderWindow* window);
    std::string get_strscore();
    void check(Pacman* p);
    sf::SoundBuffer buffer_chomp;
    sf::Sound chomp;
    sf::SoundBuffer buffer_eatfruit;
    sf::Sound eatfruit;
};

#endif /* Dots_hpp */
