#include <core/objects/GameObject.h>

/// <summary>
/// Base class for all entities. (Player, NPC, etc.)
/// Have health, speed.
/// </summary>
class Entity :
	public GameObject
{
private:
    float _health;
    float _maxHealth;
    float _speed;
public:
	Entity(const char* name);
	virtual ~Entity();

    void setHealth(const float& health);
    void setSpeed(const float& speed);

    float getHealth() const noexcept { return _health; }
    float getSpeed() const noexcept { return _speed; }

    // Damage the entity.
    void damage(const float& damage);
    // Heal the entity.
    void heal(const float& heal);    

    // Kill the entity.
    void kill();
};
