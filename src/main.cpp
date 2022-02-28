#include <iostream>
#include "GUI.hpp"
#include "world.hpp"
#include "player.hpp"
#include "block.hpp"
#include "../lib/SFML-2.5.1/include/SFML/Graphics.hpp"
#define VERSION "0.0.8"


void loadTextures(sf::Texture *receiver, std::string path);
void update(sf::RenderWindow *window, Player *player, Block *dirt, World *world);
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


    World world(true);

    for(int i(0); i<1280; i+=64){
        /*
            Le probleme vient d'ici.
            Impossible de charger le block avec de la texture sinon le jeu ram a mort.
            Je dois trouver une solution.
        */

        world.append(new Block(1, sf::RectangleShape(sf::Vector2f(64,64)), dirt_texture, i, 720-64));
    }
    
    
    //std::vector<std::vector<int>> grid = makeGrid(720, 1280);
    /*for(int i(0); i<720; i+=75){
        for(int j(0); j<1280; j+=75){
            if(&grid[i][j] != nullptr){
                if(grid[i][j] == 1){
                    
                }
            }
        }
    }*/
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
            
            
            if(keyboard.isKeyPressed(sf::Keyboard::Right) && player.isOnGround(&window)){
                    player.setVelX(10);
            }
            if(keyboard.isKeyPressed(sf::Keyboard::Left) && player.isOnGround(&window)){
                    player.setVelX(-10);
            }
        }

        if(keyboard.isKeyPressed(sf::Keyboard::Space)){
            if(player.isOnGround(&window)){
                player.setVelY(-10);
            }   
        }
        if(keyboard.isKeyPressed(sf::Keyboard::Escape)){
                window.close();
        }
        if(keyboard.isKeyPressed(sf::Keyboard::Right) == false && keyboard.isKeyPressed(sf::Keyboard::Left) == false && player.isOnGround(&window)){
            player.setVelX(0);
        }

        


        update(&window, &player, &dirt_block, &world);
        //movement(&window, &perso, &playerVelocityX);
    }

    return 0;
}


void loadTextures(sf::Texture *receiver, std::string path){
    receiver->loadFromFile(path,sf::IntRect(0,0,32,32));
}


void update(sf::RenderWindow *window, Player *player, Block *dirt, World *world){
    player->move();
    window->clear(sf::Color(190,220,255,255));
    player->update_player(window);
    dirt->update_block(window);
    world->draw(window);
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