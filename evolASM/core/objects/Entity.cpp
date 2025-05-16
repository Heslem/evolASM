#include <core/objects/Entity.h>

Entity::Entity(const char* name)
    : GameObject(name), _health(100.f), _maxHealth(100.f), _speed(1.0f)
{
}

Entity::~Entity()
{
}


void Entity::setHealth(const float& health)
{
    this->_health = health;

    if (this->_health > this->_maxHealth)
        this->_health = this->_maxHealth;
}

void Entity::setSpeed(const float& speed) 
{
    this->_speed = speed;
}

void Entity::damage(const float& damage)
{
    if (damage < 0)
        return;

    this->_health -= damage;
    if (this->_health < 0)
        kill();
}

void Entity::heal(const float& heal)
{
    if (heal < 0)
        return;

    this->_health += heal;
    if (this->_health > this->_maxHealth)
        this->_health = this->_maxHealth;
}

void Entity::kill()
{
    destroy();
}

