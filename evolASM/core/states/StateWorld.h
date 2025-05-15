#pragma once
#include <sfml.h>

#include <core/objects/GameObject.h>
#include <core/State.h>

#include <string>
#include <vector>

struct GameObject;

class World :
	public State
{

	std::vector<GameObject*> _objects;
public:
	World();
	virtual ~World();

	virtual void tick() override;

	void create(GameObject* object);
	void destroyObject(const size_t& index);

	GameObject* computeClosestObject(GameObject& from);

	GameObject* computeClosestObjectByName(GameObject& from, const char* name);
protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

