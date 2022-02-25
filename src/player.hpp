#ifndef PLAYER
#define PLAYER
#include "../lib/SFML-2.5.1/include/SFML/Graphics.hpp"

class Player{
    private:
        sf::Texture *player_texture;
        sf::RectangleShape *body;
        float velocityX;
        float velocityY;

    public:
        Player(sf::Texture *text, sf::RectangleShape *bdy);

        float getVelX();

        float getVelY();

        void setVelY(float value);

        void setVelX(float value);

        void setVel(float valueX, float valueY);

        bool isOnGround(sf::RenderWindow *window);
        
        void gravity(sf::RenderWindow *window);

        void update_player(sf::RenderWindow *window);

        sf::RectangleShape *returnRect();
};




#endif