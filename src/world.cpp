#include "world.hpp"
#include <vector>
#include "../lib/SFML-2.5.1/include/SFML/Graphics.hpp"

using namespace std;



    Grid::Grid(){
        this->height = 0;
        this->width = 0;
    }

    Grid::Grid(int pfHeight, int pfWidth){
        for(int i(0); i<pfHeight; i++){
            this->grid.push_back(vector<sf::RectangleShape *>(pfWidth));
        }
        this->height = pfHeight;
        this->width = pfWidth;
    };

    int Grid::getHeight(){
        return this->height;
    }

    int Grid::getWidth(){
        return this->width;
    }

    void Grid::setAt(int i, int j,sf::RectangleShape *obj){
        this->grid.at(i).at(j) = obj;
    }

    sf::RectangleShape *Grid::getAt(int i, int j){
        return this->grid.at(i).at(j);
    }


vector<vector<int>> superflatWorld(){
    vector<vector<int>> world;
    for(int i(0); i<720; i++){
        world.push_back(vector<int>(1280));
    }

    int random;
    unsigned int seed;
    int sizex = world.size();
    int sizey = world[0].size();
    bool proba;
    for(int i(0); i<sizex; i+=75){
        for(int j(0); j<sizey; j+=75){
            if(i>600){
                world[i][j] = 1;
            }else{
                world[i][j] = 0;
            }

        }
    }

    
    return world;
}


void printVector(vector<vector<int>> const &tab){
    int sizex = tab.size();
    int sizey = tab[0].size();
    for(int i(0); i<sizex; i+=75){
        for(int j(0); j<sizey; j+=75){
            printf("%d ; ",tab[i][j]);
            
        }
        printf("(%d)\n",i);
        printf("\n");
    } 
}


