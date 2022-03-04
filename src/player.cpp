#include "player.hpp"
#include <iostream>
#include "../lib/SFML-2.5.1/include/SFML/Graphics.hpp"


        


Player::Player(sf::Texture *text, sf::RectangleShape *bdy){
    this->player_texture = text;
    this->body = bdy;
    this->velocityX = 0.0;
    this->velocityY = 0.0;
    this->onGround = false;
    this->canMove = true;
}


float Player::getVelX(){
    return this->velocityX;
}

float Player::getVelY(){
    return this->velocityY;
}

void Player::setVelY(float value){
    this->velocityY = value;
}

void Player::setVelX(float value){
    this->velocityX = value;
}

void Player::setVel(float valueX, float valueY){
    this->velocityX = valueX;
    this->velocityY = valueY;
}


bool Player::isOnGround(sf::RenderWindow *window){
    return this->onGround;
}

void Player::gravity(sf::RenderWindow *window){
    if(this->onGround == false && this->getVelY()*1.25 < 25){
        if(this->getVelY() == 0){
            this->setVelY(1.0);
        }else if(this->getVelY() >0){
            this->setVelY(this->getVelY()*1.25);
        }else if(this->getVelY() < -1.5){
            this->setVelY(this->getVelY()*0.865);
        }else{
            this->setVelY(0);
        }
    }else if(this->onGround == true && this->getVelY() > 0){
        this->setVelY(-0.5);
    }

}

void Player::move(World *world){
    int nbBlocks = world->getNbBlocks();
    for(int i(0); i<nbBlocks; i++){
        
        if((world->getAt(i).getRectangle()->getPosition().y + 64 <= this->body->getPosition().y + this->body->getSize().y) && world->getAt(i).getRectangle()->getPosition().y > this->body->getPosition().y){
            if(world->getAt(i).getRectangle()->getPosition().x > this->body->getPosition().x + this->body->getSize().x){
                
                if(world->getAt(i).getRectangle()->getPosition().x - (this->body->getPosition().x + this->body->getSize().x) < this->velocityX){
                    this->canMove = false;
                    printf("1\n");
                }else{
                    this->canMove = true;
                    printf("2\n");
                }

            }else if(world->getAt(i).getRectangle()->getPosition().x + world->getAt(i).getRectangle()->getSize().x < this->body->getPosition().x){
                printf("%f\n", this->body->getPosition().x - (world->getAt(i).getRectangle()->getPosition().x + world->getAt(i).getRectangle()->getSize().x));
                if(this->body->getPosition().x - (world->getAt(i).getRectangle()->getPosition().x + world->getAt(i).getRectangle()->getSize().x) < -this->velocityX){
                    this->canMove = false;
                    printf("3\n");
                }else{
                    this->canMove = true;
                    printf("4\n");
                }
            }
            
        }


        if( this->body->getPosition().x <= world->getAt(i).getRectangle()->getPosition().x + world->getAt(i).getRectangle()->getSize().x &&  this->body->getPosition().x >= world->getAt(i).getRectangle()->getPosition().x){
                if(world->getAt(i).getRectangle()->getPosition().y <= this->body->getPosition().y + this->body->getSize().y){
                
                    if(this->body->getPosition().y + this->body->getSize().y > world->getAt(i).getRectangle()->getPosition().y ){
                        this->body->setPosition(this->body->getPosition().x, world->getAt(i).getRectangle()->getPosition().y-this->body->getSize().y);
                    }
                    
                    this->onGround = true;
                    
                }else{
                        this->onGround = false;
                }
            
        }else if(this->body->getPosition().x+this->body->getSize().x <= world->getAt(i).getRectangle()->getPosition().x + world->getAt(i).getRectangle()->getSize().x &&  this->body->getPosition().x+this->body->getSize().x >= world->getAt(i).getRectangle()->getPosition().x){
                if(world->getAt(i).getRectangle()->getPosition().y <= this->body->getPosition().y + this->body->getSize().y){
                
                    if(this->body->getPosition().y + this->body->getSize().y > world->getAt(i).getRectangle()->getPosition().y ){
                        this->body->setPosition(this->body->getPosition().x, world->getAt(i).getRectangle()->getPosition().y-this->body->getSize().y);
                    }
                    
                    this->onGround = true;

                    
                }else{
                        this->onGround = false;
                }
        }
        
        
    }
    if(this->canMove == true &&  this->onGround == false){
        this->returnRect()->move(this->velocityX, this->velocityY);
    }else if(this->canMove == false && this->onGround == false){
        this->returnRect()->move(0, this->velocityY);
    }else if(this->canMove == true && this->onGround == true){
        if(this->velocityY < -1){
            this->returnRect()->move(this->velocityX, this->velocityY);
        }else{
            this->returnRect()->move(this->velocityX, 0);
        }
    }else if(this->canMove == false && this->onGround == true){
        if(this->velocityY < -1){
            this->returnRect()->move(0, this->velocityY);
        }else{
            this->returnRect()->move(0, 0);
        }
    }
    printf("Can move : %d\n", this->canMove);
}

void Player::update_player(sf::RenderWindow *window, World *world){
    gravity(window);
    sf::Texture player_texture;
    player_texture.loadFromFile("sprite/perso.png", sf::IntRect(0,0,32,32));
    this->returnRect()->setTexture(&player_texture);
    this->move(world);
    
    window->draw(*this->returnRect());
}

sf::RectangleShape *Player::returnRect(){
    return this->body;
}