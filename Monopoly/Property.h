#pragma once

class Player;

class Property
{
protected:
	string _name;
	int _colour = 0;
	int _price = 0;
	int _collateralValue = 0;
	int* _rent = nullptr;
	Player* _master = nullptr;
	bool _isLaidDown = false;
public:
	Property() = default;
	Property(const string& name, const int colour,
		const int price, const int collateralValue);
	Property(const Property& property) = delete;
	Property(Property&& property) = delete;
	~Property();

	void SetName(const string& name);
	void SetColour(const int colour);
	void SetPrice(const int price) ;
	void SetCollateralValue(const int value);
	void SetMaster(Player* player);

	void Redeem();
	const string& GetName() const;
	int GetPrice() const;
	int GetCollateralValue() const;
	int GetColor() const;
	const int* GetRent() const;
	bool GetIsLayDown() const;
	Player* GetMaster();
    
	virtual void SetRent(const int* rent) = 0;
	virtual void LayDown() = 0;
	virtual void BuildHouse() = 0;
	virtual void DestroyHouse() = 0;
	virtual int GetAmountHouses() const = 0;
	virtual int GetAmountProperties() const = 0;
	virtual int GetIdentificator() const = 0;
	virtual void ResetAmountOfHouses() = 0;

	const Property* operator = (const Property& property) = delete;
	const Property* operator = (Property&& property) = delete;
};

