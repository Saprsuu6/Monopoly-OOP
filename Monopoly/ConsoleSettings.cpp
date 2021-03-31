#include "Header.h"

ConsoleSettings::ConsoleSettings()
{
	SetConsoleTitle("Monopoly");
	system("mode con cols=78 lines=19");

	h = GetStdHandle(STD_OUTPUT_HANDLE);

	cursor.dwSize = 10;
	cursor.bVisible = false;
	SetConsoleCursorInfo(h, &cursor);

	system("color 0");
}

ConsoleSettings::~ConsoleSettings()
{
	system("pause -> NULL");
}

void ConsoleSettings::Cursor(const int X, const int Y)
{
	c.X = X;
	c.Y = Y;
	SetConsoleCursorPosition(h, c);
}

void ConsoleSettings::SetColour(const int colour) const
{
	SetConsoleTextAttribute(h, colour);
}

const HANDLE& ConsoleSettings::GetHandle()
{
	return h;
}
