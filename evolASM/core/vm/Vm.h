#pragma once
#include "TokenType.h"

class Vm final
{
	TokenType* _code;
	unsigned int _pointer;

public:
	Vm() = default;
	~Vm() = default;
};