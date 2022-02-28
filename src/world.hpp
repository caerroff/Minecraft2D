#ifndef WORLD
#define WORLD
#include <vector>
#include "block.hpp"
#include "../lib/SFML-2.5.1/include/SFML/Graphics.hpp"

class World{
    private:
    std::vector<Block> blocks;
    int nbBlocks = 0;
    

    public:
    World(bool test);
    int getNbBlocks();
    Block getAt(int index);
    void append(Block * block);
    void pop();
    void draw(sf::RenderWindow *window);

};

std::vector<std::vector<int>> makeGrid(int height, int width);

#endif