#include <core/objects/entities/Player.h>
#include <sfml.h>

Player::Player()
    : Entity("player")
{
}

Player::~Player()
{
}

void Player::tick()
{
    // Get keyboard input
    sf::Vector2f movement(0.f, 0.f);
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        movement.y -= getSpeed();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        movement.y += getSpeed();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        movement.x -= getSpeed();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        movement.x += getSpeed();

    move(movement);
}





