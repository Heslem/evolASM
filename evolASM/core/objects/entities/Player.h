#include <core/objects/Entity.h>

class Player final :
	public Entity
{
public:
	Player();
	~Player();

	void tick() override;

private:


};
