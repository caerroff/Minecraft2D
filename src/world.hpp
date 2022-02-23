#ifndef WORLD
#define WORLD
#include <vector>
#include "block.hpp"
#include "../lib/SFML-2.5.1/include/SFML/Graphics.hpp"



class World{
    private:
    int nb_block;
    std::vector<Block *> list;


    public:
    World();
    int getNbBlock();
    void append(Block *pfBlock);
    void pop();
    Block * getAt(int i);
    void setAt(Block *block, int i);
    
};


std::vector<std::vector<int>> superflatWorld();
void printVector(std::vector<std::vector<int>> const &tab);

#endif