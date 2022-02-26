#include <iostream>
#include "GUI.hpp"
#include "world.hpp"
#include "player.hpp"
#include "block.hpp"
#include "../lib/SFML-2.5.1/include/SFML/Graphics.hpp"
#define VERSION "0.0.7"


void loadTextures(sf::Texture *receiver, std::string path);
void gravity(sf::RenderWindow *window, sf::RectangleShape *player, float *playerVelocity);
bool isOnGround(sf::RenderWindow *window, sf::RectangleShape *player);
void update(sf::RenderWindow *window, Player *player, Block *dirt);
sf::RectangleShape * initPlayer(sf::RectangleShape *perso, sf::Texture *perso_texture);
void initDirt(sf::RectangleShape *dirt, sf::Texture *dirt_texture);



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
    
    
    sf::RectangleShape dirt;
    sf::Texture dirt_texture;
    initDirt(&dirt, &dirt_texture);
    Block dirt_block(1, dirt, dirt_texture);
    
    
    sf::RectangleShape perso;
    sf::Texture perso_texture;
    perso = *initPlayer(&perso, &perso_texture);
    Player player(&perso_texture, &perso);


    window.clear(sf::Color(190,220,255,255));
    window.draw(perso);
    window.draw(dirt);
    window.display();

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
        if(event.type == sf::Event::KeyPressed){
            
            
            if(keyboard.isKeyPressed(sf::Keyboard::Right) && isOnGround(&window, &perso)){
                    player.setVelX(10);
            }
            if(keyboard.isKeyPressed(sf::Keyboard::Left) && isOnGround(&window, &perso)){
                    player.setVelX(-10);
            }
        }

        if(keyboard.isKeyPressed(sf::Keyboard::Space)){
            if(isOnGround(&window, &perso)){
                player.setVelY(-10);
            }   
        }
        if(keyboard.isKeyPressed(sf::Keyboard::Escape)){
                window.close();
        }
        if(keyboard.isKeyPressed(sf::Keyboard::Right) == false && keyboard.isKeyPressed(sf::Keyboard::Left) == false && !!isOnGround(&window, &perso)){
            player.setVelX(0);
        }

        

        
        update(&window, &player, &dirt_block);
        //movement(&window, &perso, &playerVelocityX);
    }

    return 0;
}


void loadTextures(sf::Texture *receiver, std::string path){
    receiver->loadFromFile(path,sf::IntRect(0,0,32,32));
}

void movement(sf::RenderWindow *window, sf::RectangleShape *player, float *playerVelocityX){
    
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

void update(sf::RenderWindow *window, Player *player, Block *dirt){
    player->move();
    window->clear(sf::Color(190,220,255,255));
    player->update_player(window);
    dirt->update_block(window);
    window->display();
}

sf::RectangleShape * initPlayer(sf::RectangleShape *perso, sf::Texture *perso_texture){
    loadTextures(perso_texture, "sprite/perso.png");
    perso->setTexture(perso_texture);
    perso->setSize(sf::Vector2f(140.f,140.f));
    return perso;

}

void initDirt(sf::RectangleShape *dirt, sf::Texture *dirt_texture){

    dirt_texture->loadFromFile("sprite/block.png",sf::IntRect(0,0,64,64));
    dirt->setTexture(dirt_texture);
    dirt->setSize(sf::Vector2f(75.f,75.f));
    dirt->setPosition(300,420);
}