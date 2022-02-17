#include <iostream>
#include "GUI.hpp"
#include "../lib/SFML-2.5.1/include/SFML/Graphics.hpp"
#define VERSION "0.0.1"


int main(){
    printf("Version %s\n", VERSION);
    sf::RenderWindow window(sf::VideoMode(1280,720), "MC2D");
    
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
    sf::Color cyan(sf::Color::Cyan);
    window.clear(cyan);
    sf::RectangleShape title;
    title.setSize(sf::Vector2f(700,100));
    title.setPosition(sf::Vector2f(window.getSize().x/2-title.getSize().x/2,100));
    title.setFillColor(sf::Color(200,150,200,255));
    window.draw(title);

    sf::RectangleShape play;
    play.setSize(sf::Vector2f(500,80));
    play.setPosition(sf::Vector2f(window.getSize().x/2-play.getSize().x/2,300));
    play.setFillColor(sf::Color(255,255,255,255));
    window.draw(play);

    sf::RectangleShape options;
    options.setSize(sf::Vector2f(500,80));
    options.setPosition(sf::Vector2f(window.getSize().x/2-options.getSize().x/2,400));
    options.setFillColor(sf::Color(255,255,255,255));
    window.draw(options);

    sf::RectangleShape version;
    version.setSize(sf::Vector2f(150,30));
    version.setPosition(sf::Vector2f(0,690));
    version.setFillColor(sf::Color::Black);
    window.draw(version);
    
    
    sf::Mouse mouse;
    sf::Vector2i mousePos;
    sf::Mouse::Button lClick(sf::Mouse::Button::Left);

    window.display();
    //################
    // RUNNING WINDOW
    //################
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }
        
        //printf("%d;%d\n",mousePos.x, mousePos.y);
        mousePos = mouse.getPosition(window);
        printf("%d %d\n", sf::Vector2i(window.getSize().x/2-play.getSize().x/2,300).x, sf::Vector2i(window.getSize().x/2+play.getSize().x/2,300).x);
        if(mousePos.x >= sf::Vector2i(window.getSize().x/2-play.getSize().x/2,300).x || mousePos.x <= sf::Vector2i(window.getSize().x/2+play.getSize().x/2,300).x){
            //printf("1\n");
            if(mousePos.y >= 300 || mousePos.y <= 380){
                //printf("2\n");
                if(mouse.isButtonPressed(lClick)){
                    printf("3\n");
                    window.close();
                }
            }  
        }

    }

    return 0;
}

