#ifndef BLOCK
#define BLOCK
#include "../lib/SFML-2.5.1/include/SFML/Graphics.hpp"

class Block{
    private:
        int id;
        sf::RectangleShape rectangle;
        sf::Texture texture;

    public:
        Block(int pfId, sf::RectangleShape pfRectangle, sf::Texture pfTexture);
        int getId();
        sf::RectangleShape *getRectangle();
        sf::Texture *getTexture();
        void update_block(sf::RenderWindow *window);
    
};



#endif