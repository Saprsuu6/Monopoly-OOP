#include "Header.h"

Street::Street(const string& name, const int colour, 
	const int price, const int collateralValue, 
	const int* rent, const int amountHouse)
	: Property::Property(name, colour, price,
		collateralValue)
{
	SetRent(rent);
}

void Street::SetRent(const int* rent)
{
	if (rent != nullptr)
	{
		_rent = new int[amountProperty];
		for (int i = 0; i < amountProperty; i++)
		{
			_rent[i] = rent[i];
		}
	}
}

void Street::BuildHouse()
{
	if (_amountHouse < 6)
	{
		_amountHouse++;
	}
}

void Street::DestroyHouse()
{
	if (_amountHouse > 0)
	{
		_amountHouse--;
	}
}

int Street::GetAmountHouses() const
{
	return _amountHouse;
}

int Street::GetAmountProperties() const
{
	return amountProperty;
}

int Street::GetIdentificator() const
{
	return identificator;
}

void Street::ResetAmountOfHouses()
{
	if (_amountHouse > 0)
	{
		_amountHouse = 0;
	}
}

const int Street::amountProperty = 6;

const int Street::identificator = 1;