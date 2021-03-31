#include "Header.h"

Railway::Railway(const string& name, const int colour, 
	const int price, const int collateralValue,
	const int* rent)
	: Property::Property(name, colour, price,
		collateralValue)
{
	SetRent(rent);
}

void Railway::SetRent(const int* rent)
{
	if (rent != nullptr)
	{
		_rent = new int[Railway::amountProperty];
		for (int i = 0; i < amountProperty; i++)
		{
			_rent[i] = rent[i];
		}
	}
}

void Railway::LayDown()
{
	_isLaidDown = true;
}

Railway* Railway::GetRailway()
{
	return this;
}

int Railway::GetAmountProperties() const
{
	return amountProperty;
}

int Railway::GetIdentificator() const
{
	return identificator;
}

const int Railway::amountProperty = 4;

const int Railway::identificator = 2;
