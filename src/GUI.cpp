#include "GUI.hpp"
#include <iostream>
#include "../lib/SFML-2.5.1/include/SFML/Graphics.hpp"
#define VERSION "0.1.1"

int mainMenu(sf::RenderWindow *window){

    sf::Font fancy;
    sf::Font regular;
    fancy.loadFromFile("lib/fonts/Shizuru-Regular.ttf");
    regular.loadFromFile("lib/fonts/Ubuntu-Regular.ttf");

    window->setVerticalSyncEnabled(true);
    window->setFramerateLimit(60);
    sf::Color cyan(sf::Color::Cyan);
    window->clear(sf::Color(250,239,255));
    
    
    sf::RectangleShape title;
    title.setSize(sf::Vector2f(700,150));
    title.setPosition(sf::Vector2f(window->getSize().x/2-title.getSize().x/2,100));
    title.setFillColor(sf::Color(150,200,150,255));
    title.setOutlineColor(sf::Color::Black);
    title.setOutlineThickness(3);
    window->draw(title);

    sf::Text title_two(sf::String("MineCraft 2D"),fancy,100U);
    title_two.setOutlineColor(sf::Color(0,0,0,255));
    title_two.setFillColor(sf::Color(255,255,100,255));
    title_two.setOutlineThickness(5);
    title_two.setPosition(window->getSize().x/2-345,100);
    window->draw(title_two);

    sf::RectangleShape play;
    play.setSize(sf::Vector2f(500,80));
    play.setPosition(sf::Vector2f(window->getSize().x/2-play.getSize().x/2,300));
    play.setFillColor(sf::Color(255,255,255,255));
    play.setOutlineColor(sf::Color::Black);
    play.setOutlineThickness(3);
    window->draw(play);

    

    sf::Text play_text(sf::String("Play"),regular,70U);
    play_text.setOutlineColor(sf::Color(50,50,50,255));
    play_text.setFillColor(sf::Color(180,255,180,255));
    play_text.setOutlineThickness(5);
    play_text.setPosition(window->getSize().x/2-70,290);
    play_text.setLetterSpacing(2.25);
    window->draw(play_text);

    sf::RectangleShape options;
    options.setSize(sf::Vector2f(500,80));
    options.setPosition(sf::Vector2f(window->getSize().x/2-options.getSize().x/2,400));
    options.setFillColor(sf::Color(255,255,255,255));
    options.setOutlineColor(sf::Color::Black);
    options.setOutlineThickness(3);
    window->draw(options);

    sf::Text options_text(sf::String("Options"),regular,70U);
    options_text.setOutlineColor(sf::Color(50,50,50,255));
    options_text.setFillColor(sf::Color(180,255,180,255));
    options_text.setOutlineThickness(5);
    options_text.setPosition(window->getSize().x/2-130,395);
    options_text.setLetterSpacing(1.5);
    window->draw(options_text);


    sf::RectangleShape version;
    version.setSize(sf::Vector2f(150,30));
    version.setPosition(sf::Vector2f(0,690));
    version.setFillColor(sf::Color::Black);
    window->draw(version);
    
    sf::Text version_text(sf::String("Version ") + sf::String(VERSION),regular,20U);
    version_text.setOutlineColor(sf::Color(0,0,0,255));
    version_text.setFillColor(sf::Color(255,255,255,255));
    version_text.setOutlineThickness(2);
    version_text.setPosition(10,690);
    version_text.setLetterSpacing(1.5);
    window->draw(version_text);
    
    sf::Mouse mouse;
    sf::Vector2i mousePos;
    sf::Mouse::Button lClick(sf::Mouse::Button::Left);

    window->display();
    //################
    // RUNNING WINDOW
    //################
    bool menu(true);
    while(window->isOpen() && menu){
        sf::Event event;
        while(window->pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window->close();
            }
        }
        
        //printf("%d;%d\n",mousePos.x, mousePos.y);
        mousePos = mouse.getPosition(*window);
        
        if(mouse.isButtonPressed(lClick)){
            if(mousePos.x >= sf::Vector2i(window->getSize().x/2-play.getSize().x/2,300).x && mousePos.x <= sf::Vector2i(window->getSize().x/2+play.getSize().x/2,300).x){
                if(mousePos.y >= 300 && mousePos.y <= 380){
                    menu = false;
                }
            }  
        }

    }
    return 0;
}