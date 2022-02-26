#include "block.hpp"
#include "../lib/SFML-2.5.1/include/SFML/Graphics.hpp"


Block::Block(int pfId, sf::RectangleShape pfRectangle, sf::Texture pfTexture){
    this->id = pfId;
    this->rectangle = pfRectangle;
    this->texture = pfTexture;
}

int Block::getId(){
    return this->id;
}

sf::RectangleShape * Block::getRectangle(){
    return &this->rectangle;
}

void Block::update_block(sf::RenderWindow *window){
    window->draw(*this->getRectangle());
}


sf::Texture * Block::getTexture(){
    return &this->texture;
}