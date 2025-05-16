#include "StateWorldMain.h"
#include <core/objects/entities/Player.h>

StateWorldMain::StateWorldMain()
{
}

StateWorldMain::~StateWorldMain()
{
}

void StateWorldMain::start()
{
	StateWorld::start();

	Player* player = new Player();
	player->mSprite.setSize(sf::Vector2f(50, 50));

	spawn(player);
}

void StateWorldMain::tick()
{
	StateWorld::tick();
}

void StateWorldMain::end()
{
	StateWorld::end();
}
