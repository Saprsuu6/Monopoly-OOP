#include "Header.h"

Property::Property(const string& name, const int colour,
	const int price, const int collateralValue)
{
	SetName(name);
	SetColour(colour);
	SetPrice(price);
	SetCollateralValue(collateralValue);
}

void Property::SetName(const string& name)
{
	if (name.find_first_not_of("AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz123456789 ")
		&& name != " " && name.size() != 0)
	{
		_name = name;
	}
}

void Property::SetColour(const int colour)
{
	if (colour > 0 && colour < 10)
	{
		_colour = colour;
	}
}

void Property::SetPrice(const int price)
{
	if (price > 0)
	{
		_price = price;
	}
}

void Property::SetCollateralValue(const int value)
{
	if (value > 0)
	{
		_collateralValue = value;
	}
}

void Property::SetMaster(Player* player)
{
	_master = player;
}

Property::~Property()
{
	delete[] _rent;
}

void Property::LayDown()
{
	if (!_isLaidDown)
	{
		_isLaidDown = true;
	}
}

void Property::Redeem()
{
	if (_isLaidDown)
	{
		_isLaidDown = false;
	}
}

const string& Property::GetName() const
{
	return _name;
}

int Property::GetPrice() const
{
	return _price;
}

int Property::GetCollateralValue() const
{
	return _collateralValue;
}

int Property::GetColor() const
{
	return _colour;
}

const int* Property::GetRent() const
{
	return _rent;
}

bool Property::GetIsLayDown() const
{
	return _isLaidDown;
}

Player* Property::GetMaster()
{
	return _master;
}

Property* Property::GetProperty()
{
	return this;
}
