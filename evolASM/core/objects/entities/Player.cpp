#include <core/objects/entities/Player.h>
#include <sfml.h>

Player::Player()
    : Entity("player")
{
    mSprite.setTexture("player");
}

Player::~Player()
{
}


void Player::tick()
{
    static bool pressed = false;

    sf::Vector2f movement(0.f, 0.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        movement.y -= getSpeed();
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        movement.y += getSpeed();
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        movement.x -= getSpeed();
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        movement.x += getSpeed();
    else
        pressed = false;
    if (!pressed) {

        pressed = movement.x != 0.f || movement.y != 0.f;
        move(movement);
    }
}





