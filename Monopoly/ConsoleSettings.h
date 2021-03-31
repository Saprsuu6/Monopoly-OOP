#pragma once

class ConsoleSettings
{
private:
	COORD c{};
	HANDLE h{};
	CONSOLE_CURSOR_INFO cursor{};
public:
	ConsoleSettings();
	~ConsoleSettings();

	void Cursor(const int X, const int Y);
	void SetColour(const int colour) const;

	const HANDLE& GetHandle();
};

