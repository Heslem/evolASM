#include "StateLoading.h"
#include <core/utils/Content.h>
#include <core/Core.h>

#include <core/states/StateWorldMain.h>

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

	auto& core = Core::getInstance();

	auto& stateManager = core.getStateManager();
	stateManager.add("main", new StateWorldMain());

	stateManager.set("main");
	/*

	*/

	/*
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
