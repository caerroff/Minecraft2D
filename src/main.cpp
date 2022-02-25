#include <iostream>
#include "GUI.hpp"
#include "../lib/SFML-2.5.1/include/SFML/Graphics.hpp"
#define VERSION "0.0.6"


void loadTextures(sf::Texture *receiver, std::string path);
void gravity(sf::RenderWindow *window, sf::RectangleShape *player, float *playerVelocity);
bool isOnGround(sf::RenderWindow *window, sf::RectangleShape *player);
void update(sf::RenderWindow *window, sf::RectangleShape *player, float *playerVelocityX, float *playerVelocityY,sf::RectangleShape *dirt);
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
    
<<<<<<< Updated upstream
    
    sf::RectangleShape dirt;
    sf::Texture dirt_texture;
    initDirt(&dirt, &dirt_texture);
    sf::RectangleShape perso;
    sf::Texture perso_texture;
=======
    std::vector<std::vector<int>> matrice;
    matrice = superflatWorld();
    int sizey = matrice.size();
    int sizex = matrice[0].size();
    /*
        INIT WORLD
    */
    int sizeY = matrice.size();
    int sizeX = matrice.at(0).size();

    World map;
    /*
    for(int i(0); i<sizeY; i+=75){
        for(int j(0); j<sizeX; j+=75){
            if(matrice.at(i).at(j) != 0){
                sf::RectangleShape *dirt = (sf::RectangleShape *) malloc (sizeof(sf::RectangleShape));
                sf::Texture *dirt_texture = (sf::Texture *) malloc (sizeof(sf::Texture));
                dirt_texture->loadFromFile("sprite/block.png",sf::IntRect(0,0,64,64));
                dirt->setTexture(dirt_texture);
                dirt->setSize(sf::Vector2f(75,75));
                dirt->setPosition(sf::Vector2f(j,i));
                Block current_block(matrice.at(i).at(j),j,i, dirt, dirt_texture);

                current_block.setPos(j,i);
                map.append(&current_block);

                free(dirt);
                free(dirt_texture);
            }
        }
    }*/

    //----WORLD----//
        sf::RectangleShape dirt;
        sf::Texture dirt_texture;
        dirt_texture.loadFromFile("sprite/block.png",sf::IntRect(0,0,64,64));
        dirt.setTexture(&dirt_texture);
        dirt.setSize(sf::Vector2f(75,75));
        dirt.setPosition(sf::Vector2f(100,100));
        Block current_block(1,100,100, &dirt, &dirt_texture);
        map.append(&current_block);

        sf::RectangleShape dirt2;
        sf::Texture dirt_texture2;
        dirt_texture2.loadFromFile("sprite/block.png",sf::IntRect(0,0,64,64));
        dirt2.setTexture(&dirt_texture2);
        dirt2.setSize(sf::Vector2f(75,75));
        dirt2.setPosition(sf::Vector2f(200,200));
        Block truc(1,200,200, &dirt2, &dirt_texture2);
        map.append(&truc);
    

    //----PLAYER----//
    sf::RectangleShape perso; 
    sf::Texture perso_texture;
   
>>>>>>> Stashed changes
    perso = *initPlayer(&perso, &perso_texture);

    window.clear(sf::Color(190,220,255,255));
    window.draw(perso);
    window.draw(dirt);
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
        if(event.type == sf::Event::KeyPressed){
            
            
            if(keyboard.isKeyPressed(sf::Keyboard::Right) && isOnGround(&window, &perso)){
                    playerVelocityX = 10;
            }
            if(keyboard.isKeyPressed(sf::Keyboard::Left) && isOnGround(&window, &perso)){
                    playerVelocityX = -10;
            }
        }

        if(keyboard.isKeyPressed(sf::Keyboard::Space)){
            if(isOnGround(&window, &perso)){
                playerVelocityY = -15;
            }   
        }
        if(keyboard.isKeyPressed(sf::Keyboard::Escape)){
                window.close();
        }
        if(keyboard.isKeyPressed(sf::Keyboard::Right) == false && keyboard.isKeyPressed(sf::Keyboard::Left) == false && !!isOnGround(&window, &perso)){
            playerVelocityX = 0;
        }

        

<<<<<<< Updated upstream
        
        update(&window,&perso,&playerVelocityX, &playerVelocityY, &dirt);
        gravity(&window, &perso, &playerVelocityY);
=======
        //printf("%.1f;%.1f\n",perso.getPosition().x,perso.getPosition().y);
        update(&window, &player, &map);
 
>>>>>>> Stashed changes
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

<<<<<<< Updated upstream
void update(sf::RenderWindow *window, sf::RectangleShape *player, float *playerVelocityX, float *playerVelocityY,sf::RectangleShape *dirt){
    player->move(*playerVelocityX,*playerVelocityY);
    window->clear(sf::Color(190,220,255,255));
    window->draw(*player);
    window->draw(*dirt);
=======
void update_player(sf::RenderWindow *window, Player *player){
    gravity(window, player);
    sf::Texture player_texture;
    player_texture.loadFromFile("sprite/perso.png", sf::IntRect(0,0,32,32));
    player->returnRect()->setTexture(&player_texture);
    player->returnRect()->move(player->getVelX(),player->getVelY());
    window->draw(*player->returnRect());
}

void update_world(sf::RenderWindow *window, World *world){
    int nbBlocks = world->getNbBlock();
    for(int i(0); i<nbBlocks; i++){
        sf::Texture dirt_texture;
        //dirt_texture.loadFromFile("sprite/block.png", sf::IntRect(0,0,64,64));
        //world->getAt(i)->getBlock()->setTexture(&dirt_texture);

        world->getAt(i)->setPos(100 , 100);
        window->draw(*world->getAt(i)->getBlock());
    }
}
void update(sf::RenderWindow *window, Player *player, World *world){

    window->clear(sf::Color(190,220,255,255));
    update_world(window, world);
    player->update_player(window);
    
>>>>>>> Stashed changes
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