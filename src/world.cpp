#include <iostream>
#include "world.hpp"
#include <vector>
#include "block.hpp"
#include <SFML/Graphics.hpp>


World::World(bool test){
    this->nbBlocks = 0;
}

int World::getNbBlocks(){
    return this->nbBlocks;
}

Block World::getAt(int index){
    return this->blocks.at(index);
}

void World::append(Block * block){
    this->blocks.push_back(*block);
    this->nbBlocks +=1;
}


void World::pop(){
    this->blocks.pop_back();
    this->nbBlocks --;
}

void World::draw(sf::RenderWindow *window){
    
    
    for(int i(0); i<this->nbBlocks; i++){
        window->draw(*this->getAt(i).getRectangle());
    }
}


std::vector<std::vector<int>> makeGrid(int height, int width){
    std::vector<std::vector<int>> grid;

    for(int i(0); i<height; i++){
        std::vector<int> row;
        row.push_back(width);
        grid.push_back(row);
    }

    for(int i(0); i<height; i++){
        for(int j(0); j<width; j++){
            grid[i][j] = 0;
        }
    }

    for(int i(0); i<height; i+=75){
        for(int j(0); j<width; j+=75){
            if(i > 500){
                grid[i][j] = 1;
            }
        }
    }
    return grid;
}

int World::isIn(int x, int y){
    int indice = -1;
    for(int i(0); i<this->nbBlocks && indice == -1; i++){
        if(this->getAt(i).getRectangle()->getPosition().x == x && this->getAt(i).getRectangle()->getPosition().y == y){
            indice = i;
        }
    }
    return indice;
}

void World::deleteAt(int index){
    this->blocks.erase(this->blocks.begin() + index);
    this->nbBlocks -= 1;
}