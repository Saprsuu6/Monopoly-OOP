#pragma once
class PropertyBase
{
	static PropertyBase* instance;
private:
	Railway* _railwayArray = nullptr;
	Street* _streetArray = nullptr;

	PropertyBase() = default;
public:
	PropertyBase(const PropertyBase& base) = delete;
	PropertyBase(PropertyBase&& base) = delete;
	~PropertyBase();

	void CreateRailways();
	void CreateStreets();
	Railway* const GetRailwayArr() const;
	Street* const GetStreetArr() const;

	const PropertyBase operator = (const PropertyBase& property) = delete;
	const PropertyBase operator = (PropertyBase&& property) = delete;

	static PropertyBase* GetInstance();
	static const int amountRailway;
	static const int amountStreets;
};

