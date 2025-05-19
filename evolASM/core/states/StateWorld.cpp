#include "StateWorld.h"
#include <core/Core.h>
#include <core/utils/Math.h>

StateWorld::StateWorld()
	: _tileGrid(128, 128)
{
}

StateWorld::~StateWorld()
{
	for (size_t i = 0; i < _objects.size(); ++i)
	{
		delete _objects[i];
	}
}

void StateWorld::tick()
{
	_tileGrid.tick();
	for (size_t i = 0; i < this->_objects.size(); ++i)
	{
		if (this->_objects[i]->isDestroy()) {
			delete _objects[i];
			_objects.erase(_objects.begin() + i);

			continue;
		}
		else {
			this->_objects[i]->tick();
		}
	}

}

void StateWorld::spawn(GameObject* object)
{
	_objects.push_back(object);
}

void StateWorld::destroyObject(const size_t& index)
{
	delete _objects[index];
	_objects.erase(_objects.begin() + index);
}

GameObject* StateWorld::computeClosestObject(GameObject& from)
{
	GameObject* retObj = nullptr;

	size_t size = this->_objects.size();
	float closestDistance = 10000.0f;
	for (size_t i = 0; i < size; ++i)
	{
		if (!_objects[i]->isDestroy() && _objects[i] != &from) {
			float tempDistance = distance(_objects[i]->getPosition(), from.getPosition());

			if (tempDistance < closestDistance) {
				closestDistance = tempDistance;
				retObj = _objects[i];
			}
		}
	}
	return retObj;
}



GameObject* StateWorld::computeClosestObjectByName(GameObject& from, const char* name)
{
	GameObject* retObj = nullptr;

	size_t size = this->_objects.size();
	float closestDistance = 10000.0f;
	for (size_t i = 0; i < size; ++i)
	{
		if (!_objects[i]->isDestroy() && _objects[i]->getName() == name && _objects[i] != &from) {
			float tempDistance = distance(_objects[i]->getPosition(), from.getPosition());

			if (tempDistance < closestDistance) {
				closestDistance = tempDistance;
				retObj = _objects[i];
			}
		}
	}
	return retObj;
}

void StateWorld::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_tileGrid, states);
	for (size_t i = 0; i < _objects.size(); ++i)
	{
		target.draw(*_objects[i], states);
	}
}
