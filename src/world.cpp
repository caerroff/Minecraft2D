#include "world.hpp"
#include <vector>
#include "block.hpp"
#include "../lib/SFML-2.5.1/include/SFML/Graphics.hpp"


int World::getNbBlocks(){
    return this->nbBlocks;
}

Block World::getAt(int index){
    return this->blocks.at(index);
}


void World::append(Block * block){
    this->blocks.push_back(*block);
    this->nbBlocks ++;
}


void World::pop(){
    this->blocks.pop_back();
    this->nbBlocks --;
}


