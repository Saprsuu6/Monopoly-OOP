#pragma once
#include <iostream>
#include <cstdio>
#include <ctime>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <exception>
#include <stdexcept>
#include <fstream>
using namespace std;

#include "TheSamePlayer.h"
#include "SoMuchPlayers.h"

#include "ConsoleSettings.h"
#include "Property.h"
#include "Railway.h"
#include "Street.h"
#include "WorkingFile.h"
#include "PropertyBase.h"
#include "Player.h"
#include "PlayerBase.h"
#include "View.h"
#include "GameEngine.h"

enum Colours {
	Green = 10, DarkGreen = 2, Red = 12, DarkPink = 5,
	DarkYellow = 6, Cyan = 3, DarkRed = 4, DarkWhite = 7,
	Pink = 13, Grey = 8
};