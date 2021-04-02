#pragma once
#include "Header.h"
class PlayerHaventStreets : public logic_error
{
public:
	PlayerHaventStreets() : logic_error("Ups... Player haven't streets.") {};
};

