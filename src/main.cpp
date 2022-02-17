#include <iostream>
#include "GUI.hpp"
#include "../lib/SFML-2.5.1/include/SFML/Graphics.hpp"
#define VERSION "0.0.2"


void loadTextures(sf::Texture *receiver);

int main(){
    printf("Version %s\n", VERSION);
    sf::Keyboard keyboard;
    sf::RenderWindow window(sf::VideoMode(1280,720), "MC2D");
    mainMenu(&window);
    window.clear(sf::Color(200,200,255,255));
    window.display();
    sf::Mouse mouse;
    sf::Vector2i mousePos;
    sf::Mouse::Button lClick(sf::Mouse::Button::Left);
    sf::Mouse::Button rClick(sf::Mouse::Button::Right);
    sf::Texture perso_texture;
    loadTextures(&perso_texture);
    sf::RectangleShape perso;
    //perso.setFillColor(sf::Color::Black);
    perso.setTexture(&perso_texture);
    perso.setSize(sf::Vector2f(120.f,120.f));
    window.clear(sf::Color(190,220,255,255));
    window.draw(perso);
    window.display();
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }
        
        mousePos = mouse.getPosition(window);
        if(keyboard.isKeyPressed(sf::Keyboard::Escape)){
            window.close();
        }
        
    }

    return 0;
}


void loadTextures(sf::Texture *receiver){
    receiver->loadFromFile("sprite/perso.png",sf::IntRect(0,0,32,32));
}