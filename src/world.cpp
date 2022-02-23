#include "world.hpp"
#include "block.hpp"
#include <vector>
#include "../lib/SFML-2.5.1/include/SFML/Graphics.hpp"

using namespace std;






World::World(){
    this->nb_block = 0;
}


int World::getNbBlock(){
    return this->nb_block;
}

void World::append(Block *pfBlock){
    this->list.push_back(pfBlock);
    this->nb_block += 1;
}

void World::pop(){
    this->list.pop_back();
    this->nb_block -= 1;
}

Block * World::getAt(int i){
    return this->list.at(i);
}


void World::setAt(Block *block, int i){
    this->list.at(i) = block;
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


