#include "StateWorldMain.h"
#include <core/objects/entities/Player.h>
#include <core/Core.h>

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
	player->mSprite.setSize(sf::Vector2f(16, 16));
	player->setTileGrid(&_tileGrid);

	Core::getInstance().getCamera().focus(player);

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
