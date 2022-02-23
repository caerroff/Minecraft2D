#include <iostream>
#include <vector>
#include "GUI.hpp"
#include "world.hpp"
#include "player.hpp"
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
void update(sf::RenderWindow *window, Player *player, Grid *gr);

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
    
    std::vector<std::vector<int>> world;
    world = superflatWorld();
    int sizey = world.size();
    int sizex = world[0].size();

    Grid grid(720,1280);
    
    for(int i(0); i<sizey; i+=75){
        for(int j(0); j<sizex; j+=75){
            if(world[i][j] == 1){
                sf::RectangleShape dirt;
                sf::Texture dirt_texture;
                initDirt(&dirt, &dirt_texture);
                window.draw(dirt);
                grid.setAt(i,j,&dirt);
            }  
        }
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
        update(&window, &player, &grid);
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

void update(sf::RenderWindow *window, Player *player, Grid *gr){

    window->clear(sf::Color(190,220,255,255));
    
    
    //WARNING
    /*
    for(int i(0); i<gr->getHeight(); i+=75){
        for(int j(0); j<gr->getWidth(); j+=75){
            if(gr->getAt(i,j) != nullptr){
                gr->getAt(i,j)->setPosition(j,i);
                window->draw(*gr->getAt(i,j));
            }
        }
    }*/
    player->returnRect()->move(player->getVelX(),player->getVelY());
    window->draw(*player->returnRect());
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