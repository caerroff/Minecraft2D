#include <iostream>
#include "GUI.hpp"
#include "../lib/SFML-2.5.1/include/SFML/Graphics.hpp"
#define VERSION "0.0.4"


void loadTextures(sf::Texture *receiver);
void gravity(sf::RenderWindow *window, sf::RectangleShape *player, float *playerVelocity);
bool isOnGround(sf::RenderWindow *window, sf::RectangleShape *player);
void update(sf::RenderWindow *window, sf::RectangleShape *player, float *playerVelocityX, float *playerVelocityY);

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
    perso.setSize(sf::Vector2f(140.f,140.f));
    window.clear(sf::Color(190,220,255,255));
    window.draw(perso);
    window.display();

    float playerVelocityX = 0.0;
    float playerVelocityY = 0.0;

    /*
        LAUNCHING WINDOW
    */
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }
        
        if(keyboard.isKeyPressed(sf::Keyboard::Escape)){
            window.close();
        }
        if(keyboard.isKeyPressed(sf::Keyboard::Space)){
            if(isOnGround(&window, &perso)){
                playerVelocityY = -15;
            }
            
        }


        update(&window,&perso,&playerVelocityX, &playerVelocityY);
        gravity(&window, &perso, &playerVelocityY);
    }

    return 0;
}


void loadTextures(sf::Texture *receiver){
    receiver->loadFromFile("sprite/perso.png",sf::IntRect(0,0,32,32));
}



void gravity(sf::RenderWindow *window, sf::RectangleShape *player, float *playerVelocity){
    if(isOnGround(window,player) == false && *playerVelocity*1.25 < 25){
        if(*playerVelocity == 0){
            *playerVelocity = 1.0;
        }else if(*playerVelocity >0){
            *playerVelocity = *playerVelocity * 1.25;
        }else if(*playerVelocity < -1.5){
            *playerVelocity = *playerVelocity * 0.865;
        }else{
            *playerVelocity = 0;
        }
    }else if(isOnGround(window,player) == true && playerVelocity > 0){
        *playerVelocity = 0;
        player->setPosition(player->getPosition().x,window->getSize().y -player->getSize().y );
    }
}


bool isOnGround(sf::RenderWindow *window, sf::RectangleShape *player){
    if(player->getPosition().y+player->getSize().y < window->getSize().y){
        return false;
    }else{
        return true;
    }
}

void update(sf::RenderWindow *window, sf::RectangleShape *player, float *playerVelocityX, float *playerVelocityY){
    player->move(*playerVelocityX,*playerVelocityY);
    window->clear(sf::Color(190,220,255,255));
    window->draw(*player);
    window->display();
}