#ifndef WORLD
#define WORLD
#include <vector>
#include "../lib/SFML-2.5.1/include/SFML/Graphics.hpp"

class Grid{
    private:
    std::vector<std::vector<sf::RectangleShape *>> grid;
    int height;
    int width;

    public:
    Grid();

    Grid(int pfHeight, int pfWidth);

    int getHeight();

    int getWidth();

    void setAt(int i, int j,sf::RectangleShape *obj);

    sf::RectangleShape *getAt(int i, int j);
};


std::vector<std::vector<int>> superflatWorld();
void printVector(std::vector<std::vector<int>> const &tab);

#endif