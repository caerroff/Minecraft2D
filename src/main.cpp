#include <iostream>
#include <math.h>
#include "GUI.hpp"
#include "world.hpp"
#include "player.hpp"
#include "block.hpp"
#include <SFML/Graphics.hpp>
#define VERSION "0.1.1"


void loadTextures(sf::Texture *receiver, std::string path);
void update(sf::RenderWindow *window, Player *player, Block *dirt, World *world, sf::RectangleShape *mouseRectangle);
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
    
    sf::View view;
    view.setCenter(0,0);
    view.setSize(1280, 720);
    window.setView(view);

    sf::RectangleShape dirt;
    sf::Texture dirt_texture;
    initDirt(&dirt, &dirt_texture);
    Block dirt_block(1, dirt, dirt_texture);

    sf::RectangleShape mouseRectangle;
    mouseRectangle.setSize(sf::Vector2f(64,64));
    mouseRectangle.setFillColor(sf::Color::Transparent);
    mouseRectangle.setOutlineColor(sf::Color::Black);
    mouseRectangle.setOutlineThickness(1);

    World world(true);
    for(int i(0); i<1280; i+=64){
        world.append(new Block(1, sf::RectangleShape(sf::Vector2f(64,64)), dirt_texture, i, 576));
    }
    world.append(new Block(1, sf::RectangleShape(sf::Vector2f(64,64)), dirt_texture, 128, 512));
    //world.append(new Block(1, sf::RectangleShape(sf::Vector2f(64,64)), dirt_texture, 256+64, 128));
    //world.append(new Block(1, sf::RectangleShape(sf::Vector2f(64,64)), dirt_texture, 512, 256));
    sf::RectangleShape perso;
    sf::Texture perso_texture;
    perso = *initPlayer(&perso, &perso_texture);
    Player player(&perso_texture, &perso);


    window.clear(sf::Color(190,220,255,255));
    window.draw(perso);
    window.draw(dirt);
    window.display();
    window.setView(view);
    bool stopUpdating = false;
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
            if(keyboard.isKeyPressed(sf::Keyboard::Right) && player.isOnGround(&window)){
                    player.setVelX(10);
            }else if(keyboard.isKeyPressed(sf::Keyboard::Right)){
                player.setVelX(5);
            }
            if(keyboard.isKeyPressed(sf::Keyboard::Left) && player.isOnGround(&window)){
                    player.setVelX(-10);
            }else if(keyboard.isKeyPressed(sf::Keyboard::Left)){
                player.setVelX(-5);
            }
        }

        if(keyboard.isKeyPressed(sf::Keyboard::Space)){
            if(player.isOnGround(&window)){
                player.setVelY(-15);
            }   
        }
        if(keyboard.isKeyPressed(sf::Keyboard::Escape)){
                window.close();
        }
        if(keyboard.isKeyPressed(sf::Keyboard::Right) == false && keyboard.isKeyPressed(sf::Keyboard::Left) == false && player.isOnGround(&window)){
            player.setVelX(0);
        }

        
        mouseRectangle.setPosition(sf::Vector2f((((int) mouse.getPosition(window).x/64)) *64, ((int) (mouse.getPosition(window).y/64))*64 ));
        if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
            if(!stopUpdating){
                int posX = ((int) mouse.getPosition(window).x/64)*64;
                int posY = ((int) (mouse.getPosition(window).y/64))*64;\
                int index = world.isIn(posX, posY);
                if(index != -1){
                    world.deleteAt(index);
                }else{
                    world.append(new Block(1, sf::RectangleShape(sf::Vector2f(64,64)), dirt_texture, posX, posY));
                }
            }
            
            stopUpdating=true;
        }else if(!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
            stopUpdating = false;
        }
        update(&window, &player, &dirt_block, &world, &mouseRectangle);
        view.setCenter(player.returnRect()->getPosition());
        window.setView(view);
        //movement(&window, &perso, &playerVelocityX);
    }

    return 0;
}


void loadTextures(sf::Texture *receiver, std::string path){
    receiver->loadFromFile(path,sf::IntRect(0,0,50,100));
}


void update(sf::RenderWindow *window, Player *player, Block *dirt, World *world, sf::RectangleShape *mouseRectangle){
    window->clear(sf::Color(190,220,255,255));
    player->update_player(window, world);
    world->draw(window);
    window->draw(*mouseRectangle);
    window->display();
}

sf::RectangleShape * initPlayer(sf::RectangleShape *perso, sf::Texture *perso_texture){
    loadTextures(perso_texture, "sprite/perso.png");
    perso_texture->setSmooth(true);
    perso->setTexture(perso_texture);
    perso->setSize(sf::Vector2f(50.f,100.f));
    return perso;

}

void initDirt(sf::RectangleShape *dirt, sf::Texture *dirt_texture){

    dirt_texture->loadFromFile("sprite/block.png",sf::IntRect(0,0,64,64));
    dirt->setTexture(dirt_texture);
    dirt->setSize(sf::Vector2f(75.f,75.f));
    dirt->setPosition(300,420);
}