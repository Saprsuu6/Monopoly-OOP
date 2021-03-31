#pragma once
class View
{
private:
	ConsoleSettings _settings;
	Property* _property = nullptr;
	Player* _player = nullptr;
public:
	void SetProperty(Property* property);
	void SetPlayer(Player* player);

	void ShowRules() const;
	void ShowRailway(const int coulour);
	void ShowStreet(const int coulour);
	void ShowPlayer(const int x, const int y);
	void DrowFrame(const int hight, const int width, int x, int y);
	void DrawLine(const int width, int x, int y);
};

