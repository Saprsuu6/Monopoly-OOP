#pragma once
class Show
{
private:
	const Property* _property = nullptr;
	//const Player* _player = nullptr;
public:
	void SetObj(const Property* obj);

	void ShowRailway() const;
	void ShowStreet() const;
	//void ShowPlayer() const;
};

