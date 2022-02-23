#include "player.hpp"
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

sf::RectangleShape *Player::returnRect(){
    return this->body;
}