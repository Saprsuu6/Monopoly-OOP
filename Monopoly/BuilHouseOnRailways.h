#pragma once
#include "Header.h"
class HouseOnRailways : public logic_error
{
public:
	HouseOnRailways() : logic_error("House couldn't exist on railway.") {};
};


