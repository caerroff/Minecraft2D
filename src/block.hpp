#ifndef BLOCK
#define BLOCK
#include "../lib/SFML-2.5.1/include/SFML/Graphics.hpp"


class Block{
    private:
    int type_block;
    sf::RectangleShape *block;
    sf::Texture *texture;
    int posX;
    int posY;

    public:
    Block();

    Block(int pf_nb_block);

    Block(int pf_nb_block, int pf_posX, int _pf_posY);

    Block(int pf_type_block, int pf_posX, int pf_posY, sf::RectangleShape *pf_Block);

    Block(int pf_type_block, int pf_posX, int pf_posY, sf::RectangleShape *pf_Block, sf::Texture *pf_texture);

    int getType();

    int getPosX();

    sf::RectangleShape * getBlock();

    sf::Texture * getTexture();

    int getPosY();

    void setPos(int x, int y);

    void setX(int x);

    void setY(int y);

};


#endif