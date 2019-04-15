#ifndef Game_h
#define Game_h

class Game
{
    Map map;
    Dots dots;
    Pacman pacman;
    int dir; // 1 - left, 2 - down, 3 - right, 4 - up
    int n_of_e; //number of enemies
    Enemy* enemy;
    sf::Clock clock;
    double time;
    sf::Font font;
    sf::Text text;
public:
    Game();
    ~Game();
    bool menu(sf::RenderWindow* window);
    bool play(sf::RenderWindow* window);
};

Game::Game()
{
    n_of_e = 4;
    enemy = new Enemy[n_of_e];
    enemy[0].init(1, 1);
    enemy[1].init(17, 17);
    enemy[2].init(1, 17);
    enemy[3].init(17, 1);
    
    dir = 0;
    time = 0;
    
    if (!font.loadFromFile("/Users/aleksandrplukci/Desktop/Информатика/2 семестр/Programms/Pacman 2.0/Pacman 2.0/arial.ttf"))
        return 1;
    text.setFont(font);
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::Blue);
    text.setString("Press P to play, Q to quit");
}

Game::~Game()
{
    delete[] enemy;
}

bool Game::menu(sf::RenderWindow* window)
{
    sf::Event event;
    while(window->pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::Closed:
                window->close();
                return false;
                
            case sf::Event::KeyPressed:
                switch(event.key.code)
                {
                    case sf::Keyboard::P:
                        return false;
                        
                    case sf::Keyboard::R:
                        return false;
                        
                    case sf::Keyboard::Q:
                        window->close();
                        return false;
                        
                    default:
                        break;
                }
                
            default:
                break;
        }
    }
    text.setPosition(window->getSize().x/2 - text.getGlobalBounds().width/2, window->getSize().y/2 - text.getGlobalBounds().height/2);
    window->clear();
    window->draw(text);
    window->display();
    return true;
}

bool Game::play(sf::RenderWindow* window)
{
    clock.restart();
    time = clock.getElapsedTime().asSeconds();
    
    sf::Event event;
    while(window->pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::Closed:
                window->close();
                break;
                    
            case sf::Event::KeyPressed:
                switch(event.key.code)
                {
                    case sf::Keyboard::Left:
                        dir = 1;
                        break;
                        
                    case sf::Keyboard::Down:
                        dir = 2;
                        break;
                        
                    case sf::Keyboard::Right:
                        dir = 3;
                        break;
                        
                    case sf::Keyboard::Up:
                        dir = 4;
                        break;
                        
                    default:
                        break;
                }
                    
            default:
                break;
        }
    }
    pacman.go(dir);
    dots.check(&pacman);
    
    window->clear();
    for(int i = 0; i < 4; i++)
    {
        enemy[i].walk();
        if(enemy[i].check_fail(&pacman))
        {
            text.setString("FAIL\n\nPress R to repeat, Q to close");
            return false;
        }
    }
    if(dots.draw(window))
    {
        text.setString("WICTORY\n\nPress R to repeat, Q to close");
        return false;
    }
    map.draw(window);
    pacman.draw(window);
    for(int i = 0; i < 4; i++)
        enemy[i].draw(window);
    text.setString(dots.get_strscore());
    text.setPosition(window->getSize().x/2 - text.getGlobalBounds().width/2, X*N + 10);
    window->draw(text);
    
    while(time < 0.001)
        time = clock.getElapsedTime().asSeconds();
    window->display();
    return true;
}

#endif /* Game_h */
