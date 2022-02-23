#include "block.hpp"


Block::Block(){

}

Block::Block(int pf_type_block){
    this->type_block = pf_type_block;
}

Block::Block(int pf_type_block, int pf_posX, int pf_posY){
    this->type_block = pf_type_block;
    this->posX = pf_posX;
    this->posY = pf_posY;
}

Block::Block(int pf_type_block, int pf_posX, int pf_posY, sf::RectangleShape *pf_Block){
    this->type_block = pf_type_block;
    this->posX = pf_posX;
    this->posY = pf_posY;
    this->block = pf_Block;
}

Block::Block(int pf_type_block, int pf_posX, int pf_posY, sf::RectangleShape *pf_Block, sf::Texture *pf_texture){
    this->type_block = pf_type_block;
    this->posX = pf_posX;
    this->posY = pf_posY;
    this->block = pf_Block;
    this->texture = pf_texture;
}

int Block::getType(){
    return this->type_block;
}

sf::RectangleShape * Block::getBlock(){
    return this->block;
}

sf::Texture * Block::getTexture(){
    return this->texture;
}

int Block::getPosX(){
    return this->posX;
}

int Block::getPosY(){
    return this->posX;
}

void Block::setPos(int x, int y){
    this->posX = x;
    this->posY = y;
}

void Block::setX(int x){
    this->posX = x;
}

void Block::setY(int y){
    this->posY = y;
}