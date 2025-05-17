#pragma once
#include <sfml.h>

#include <core/objects/GameObject.h>
#include <core/State.h>

#include <string>
#include <vector>

#include <core/tiles/TileGrid.h>

class StateWorld :
	public State
{

	std::vector<GameObject*> _objects;
	TileGrid _tileGrid;
public:
	StateWorld();
	virtual ~StateWorld();

	/// <summary>
	/// Tick the state and all objects in the state.
	/// Don't forget call this method while implementing your own state.
	/// </summary>
	virtual void tick() override;

	void spawn(GameObject* object);
	void destroyObject(const size_t& index);

	GameObject* computeClosestObject(GameObject& from);

	GameObject* computeClosestObjectByName(GameObject& from, const char* name);
protected:

	/// <summary>
	/// Draw the state and all objects in the state.
	/// Don't forget call this method while implementing your own state.
	/// </summary>
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

