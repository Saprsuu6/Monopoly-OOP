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
		_rent = new int[amountProperty];
		for (int i = 0; i < amountProperty; i++)
		{
			_rent[i] = rent[i];
		}
	}
}

void Railway::BuildHouse()
{
	ShowExeption();
}

void Railway::DestroyHouse()
{
	ShowExeption();
}

int Railway::GetAmountHouses() const
{
	ShowExeption();
	return 0;
}

void Railway::ResetAmountOfHouses()
{
	ShowExeption();
}

int Railway::GetAmountProperties() const
{
	return amountProperty;
}

int Railway::GetIdentificator() const
{
	return identificator;
}

void Railway::ShowExeption() const
{
	try
	{
		throw HouseOnRailways();
	}
	catch (const HouseOnRailways& ex)
	{
		cout << ex.what() << endl;
		Sleep(500);
	}
}

const int Railway::amountProperty = 4;

const int Railway::identificator = 2;
