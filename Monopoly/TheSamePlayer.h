#pragma once
#include "Header.h"
class TheSamePlayer : public logic_error
{
public:
	TheSamePlayer() : logic_error("Player with the same nick already exists.") {};
};

