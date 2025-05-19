#pragma once
#include <core/objects/Entity.h>
#include <core/vm/Vm.h>

class Bot final
	: public Entity
{
	Vm* brain;
public:
	Bot();
	~Bot();

	void tick() override;

};