#pragma once
#include "Header.h"
class SoMuchPlayers : public logic_error
{
public:
	SoMuchPlayers() : logic_error("So much players.") {};
};

