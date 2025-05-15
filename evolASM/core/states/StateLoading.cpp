#include "StateLoading.h"
#include <core/utils/Content.h>

StateLoading::StateLoading()
{
}

StateLoading::~StateLoading()
{
}

void StateLoading::start()
{
	auto& content = Content::getInstance();
	content.load();

	/*

	auto& stateManager = core.getStateManager();*/

	/*stateManager.add("menu", new Menu());
	stateManager.add("multiplayer_menu", new MultiplayerSelectState());
	stateManager.add("overworld", new Overworld());
	stateManager.add("server_world", new ServerWorld());
	stateManager.add("server", new ServerWorld());
	stateManager.set("menu");*/
}

void StateLoading::tick()
{


}

void StateLoading::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
}
