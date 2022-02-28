#include "player.hpp"
#include <iostream>
#include "../lib/SFML-2.5.1/include/SFML/Graphics.hpp"


        


Player::Player(sf::Texture *text, sf::RectangleShape *bdy){
    this->player_texture = text;
    this->body = bdy;
    this->velocityX = 0.0;
    this->velocityY = 0.0;
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
    if(this->returnRect()->getPosition().y+this->returnRect()->getSize().y < window->getSize().y-64){
        return false;
    }else{
        return true;
    }
}

void Player::gravity(sf::RenderWindow *window){
    if(this->isOnGround(window) == false && this->getVelY()*1.25 < 25){
        if(this->getVelY() == 0){
            this->setVelY(1.0);
        }else if(this->getVelY() >0){
            this->setVelY(this->getVelY()*1.25);
        }else if(this->getVelY() < -1.5){
            this->setVelY(this->getVelY()*0.865);
        }else{
            this->setVelY(0);
        }
    }else if(this->isOnGround(window) == true && this->getVelY() > 0){
        this->setVelY(0);
        this->returnRect()->setPosition(this->returnRect()->getPosition().x,window->getSize().y-64 -this->returnRect()->getSize().y );
    }
}

void Player::move(){
    this->returnRect()->move(this->getVelX(), this->getVelY());
}

void Player::update_player(sf::RenderWindow *window){
    gravity(window);
    sf::Texture player_texture;
    player_texture.loadFromFile("sprite/perso.png", sf::IntRect(0,0,32,32));
    this->returnRect()->setTexture(&player_texture);
    this->returnRect()->move(this->getVelX(),this->getVelY());
    window->draw(*this->returnRect());
}

sf::RectangleShape *Player::returnRect(){
    return this->body;
}