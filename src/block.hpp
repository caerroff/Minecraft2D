#ifndef BLOCK
#define BLOCK
#include <SFML/Graphics.hpp>

class Block{
    private:
        int id;
        sf::RectangleShape rectangle;
        sf::Texture texture;

    public:
        Block(int pfId, sf::RectangleShape pfRectangle, sf::Texture pfTexture);
        Block(int pfId, sf::RectangleShape pfRectangle, sf::Texture pfTexture, int x, int y);
        Block(int pfId, sf::RectangleShape pfRectangle, int x, int y);
        int getId();
        sf::RectangleShape *getRectangle();
        sf::Texture *getTexture();
        void update_block(sf::RenderWindow *window);
    
};



#endif