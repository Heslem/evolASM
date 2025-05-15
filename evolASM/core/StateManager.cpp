#include "StateManager.h"
#include "states/StateLoading.h"
#include <core/utils/Logger.h>

StateManager::StateManager()
	: _current(nullptr)
{
}

void StateManager::tick()
{
	_current->tick();
}

void StateManager::drawImGui()
{
	if (_current != nullptr)
		_current->drawImGui();
}

void StateManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (_current != nullptr)
		target.draw(*_current, states);
}

void StateManager::addLoadingState()
{
	_states["loading"] = new StateLoading();
	set("loading");
}

StateManager::~StateManager()
{
	for (auto& pair : _states)
	{
		delete pair.second;
	}
}

void StateManager::add(const char* name, State* state)
{
	_states[name] = state;
	Logger::info("StateManager: added new state " + std::string(name));
}

void StateManager::remove(const char* name)
{
	delete _states[name];
	_states.erase(name);
}

void StateManager::set(const char* name)
{
	if (_current != nullptr)
		_current->end();
	
	if (_states.find(name) != _states.end())
	{
		_current = _states[name];

		Logger::info("StateManager: set state to " + std::string(name));
		_current->start();
	}
	else
		Logger::error("StateManager: state " + std::string(name) + " not found");


}

State* StateManager::get(const char* name)
{
	return _states[name];
}
