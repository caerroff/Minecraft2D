#include <iostream>
#include <vector>
#include "GUI.hpp"
#include "world.hpp"
#include "player.hpp"
#include "block.hpp"
#include "../lib/SFML-2.5.1/include/SFML/Graphics.hpp"
#define VERSION "0.0.6"

/**
 * @brief Loads the texture in path in the sf::Texture object
 * 
 * @param receiver the object you want to apply the texture to
 * @param path the path to the texture
 */
void loadTextures(sf::Texture *receiver, std::string path);

/**
 * @brief Applies gravity to the player
 * 
 * @param window the window the player is in
 * @param player the player
 * @param playerVelocity their velocity
 */
void gravity(sf::RenderWindow *window, Player *player);

/**
 * @brief tells if the player is on the ground
 * 
 * @param window the window the player is in
 * @param player the player
 * @return true if they're on the ground
 * @return false otherwise
 */
bool isOnGround(sf::RenderWindow *window, sf::RectangleShape *player);

/**
 * @brief new frame
 * 
 * @param window the window
 * @param player the player
 * @param playerVelocityX X velocity of the player
 * @param playerVelocityY Y velocity of the player
 * @param gr the grid of blocks (beta)
 */
void update(sf::RenderWindow *window, Player *player, World *world);

/**
 * @brief initialises the player
 * 
 * @param perso the RectangleShape representing the player
 * @param perso_texture the texture of the player
 * @return sf::RectangleShape* the player finished :)
 */
sf::RectangleShape * initPlayer(sf::RectangleShape *perso, sf::Texture *perso_texture);

/**
 * @brief Initialises the dirt with its texture
 * 
 * @param dirt the RectangleShape representing the dirt
 * @param dirt_texture the dirt texture
 */
void initDirt(sf::RectangleShape *dirt, sf::Texture *dirt_texture);

void update_world(sf::RenderWindow *window,World *world);
void update_player(sf::RenderWindow *window, Player *player);

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
    for(int i(0); i<2; i++){
        printf("%d\n", i);
        sf::RectangleShape dirt;
        sf::Texture dirt_texture;
        dirt_texture.loadFromFile("sprite/block.png",sf::IntRect(0,0,64,64));
        dirt.setTexture(&dirt_texture);
        dirt.setSize(sf::Vector2f(75,75));
        dirt.setPosition(sf::Vector2f(i*75,i*75));
        Block current_block(1,i*75,i*75, &dirt, &dirt_texture);
        map.append(&current_block);
        printf("%d\n", i);
    }
    
    
    sf::Texture perso_texture;
    sf::RectangleShape perso;
    perso = *initPlayer(&perso, &perso_texture);
    Player player(&perso_texture, &perso);
    window.clear(sf::Color(190,220,255,255));
    window.draw(*player.returnRect());
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
            if(isOnGround(&window, player.returnRect())){
                player.setVelY(-15);
            }   
        }
        if(keyboard.isKeyPressed(sf::Keyboard::Escape)){
                window.close();
        }
        if(keyboard.isKeyPressed(sf::Keyboard::Right) == false && keyboard.isKeyPressed(sf::Keyboard::Left) == false && isOnGround(&window, &perso)){
            player.setVelX(0);
        }

        

        //printf("%.1f;%.1f\n",perso.getPosition().x,perso.getPosition().y);
        update(&window, &player, &map);
        gravity(&window, &player);
        //movement(&window, &perso, &playerVelocityX);
    }

    return 0;
}


void loadTextures(sf::Texture *receiver, std::string path){
    receiver->loadFromFile(path,sf::IntRect(0,0,32,32));
}

void movement(sf::RenderWindow *window, sf::RectangleShape *player, float *playerVelocityX){
    
}

void gravity(sf::RenderWindow *window, Player *player){
    if(isOnGround(window,player->returnRect()) == false && player->getVelY()*1.25 < 25){
        if(player->getVelY() == 0){
            player->setVelY(1.0);
        }else if(player->getVelY() >0){
            player->setVelY(player->getVelY()*1.25);
        }else if(player->getVelY() < -1.5){
            player->setVelY(player->getVelY()*0.865);
        }else{
            player->setVelY(0);
        }
    }else if(isOnGround(window,player->returnRect()) == true && player->getVelY() > 0){
        player->setVelY(0);
        player->returnRect()->setPosition(player->returnRect()->getPosition().x,window->getSize().y -player->returnRect()->getSize().y );
    }
}


bool isOnGround(sf::RenderWindow *window, sf::RectangleShape *player){
    if(player->getPosition().y+player->getSize().y < window->getSize().y){
        return false;
    }else{
        return true;
    }
}

void update_player(sf::RenderWindow *window, Player *player){
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
        dirt_texture.loadFromFile("sprite/block.png", sf::IntRect(0,0,64,64));
        world->getAt(i)->getBlock()->setTexture(&dirt_texture);
        window->draw(*world->getAt(i)->getBlock());
    }
}
void update(sf::RenderWindow *window, Player *player, World *world){

    window->clear(sf::Color(190,220,255,255));
    update_player(window, player);
    update_world(window, world);
    
    
    
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
    
}