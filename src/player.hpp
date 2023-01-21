#ifndef PLAYER
#define PLAYER
#include <SFML/Graphics.hpp>
#include "world.hpp"

class Player{
    private:
        sf::Texture *player_texture;
        sf::RectangleShape *body;
        float velocityX;
        float velocityY;
        bool onGround;
        bool canMove;

    public:
        Player(sf::Texture *text, sf::RectangleShape *bdy);

        float getVelX();

        float getVelY();

        void setVelY(float value);

        void setVelX(float value);

        void setVel(float valueX, float valueY);

        bool isOnGround(sf::RenderWindow *window);
        
        void gravity(sf::RenderWindow *window);

        void move(World *world);

        void update_player(sf::RenderWindow *window, World *world);


        sf::RectangleShape *returnRect();
};




#endif