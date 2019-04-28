#ifndef Menu_h
#define Menu_h

bool menu()
{
    sf::Clock clock;
    double time;
    
    sf::SoundBuffer buffer;
    sf::Sound sound;
    buffer.loadFromFile(resourcePath() + "res/click.wav");
    sound.setBuffer(buffer);
    
    sf::Texture buttonTexture, backgroundTexture;
    buttonTexture.loadFromFile(resourcePath() + "res/button.png");
    backgroundTexture.loadFromFile(resourcePath() + "res/background.png");
    sf::Sprite button(buttonTexture), background(backgroundTexture);
    sf::RenderWindow window(sf::VideoMode(background.getGlobalBounds().width, background.getGlobalBounds().height), "Pacman");
    int menuNum = 0;
    button.setPosition(340, 100);
    background.setPosition(0, 0);
    
    sf::Music music;
    music.openFromFile(resourcePath() + "res/opening.wav");
    music.play();
    music.setLoop(true);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    return false;
                    
                default:
                    break;
            }
        }
        button.setColor(sf::Color::White);
        menuNum = 0;
        window.clear();
        
        if (sf::IntRect(340, 100, 220, 220).contains(sf::Mouse::getPosition(window)))
        {
            button.setColor(sf::Color::Yellow);
            menuNum = 1;
        }
        
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (menuNum == 1)
            {
                clock.restart();
                time = clock.getElapsedTime().asSeconds();
                sound.play();
                while(time < 0.05)
                {
                    time = clock.getElapsedTime().asSeconds();
                }
                
                window.close();
                return true;
            } //если нажали кнопку, то выходим из меню и идем в игру
        }
        window.draw(background);
        window.draw(button);
        window.display();
    }
}

#endif /* Menu_h */
