#include "Header.h"

void Show::SetObj(const Property* property)
{
	_property = property;
}

void Show::ShowRailway() const
{
	if (_property != nullptr)
	{
		cout << "Name: " << _property->GetName() << endl
			<< "Price: " << _property->GetPrice() << endl
			<< "Collateral value: " << _property->GetCollateralValue() << endl;
		const int* temp = _property->GetRent();
		for (int i = 0; i < _property->GetAmountProperties(); i++)
		{
			cout << "Rl. Station #" << i + 1 << ": rent - " << temp[i] << endl;
		}
		if (_property->GetIsLayDown())
		{
			cout << "Is lay down\n" << endl;
		}
		else
		{
			cout << "Isn't lay down\n" << endl;
		}
	}
}

inline void Show::ShowStreet() const
{
	if (_property != nullptr)
	{
		cout << "Name: " << _property->GetName() << endl
			<< "Price: " << _property->GetPrice() << endl
			<< "Collateral value: " << _property->GetCollateralValue() << endl
			<< "Amount houses: " << _property->GetAmountHouses() << endl;
		const int* temp = _property->GetRent();
		for (int i = 0; i < _property->GetAmountProperties(); i++)
		{
			cout << i + 1 << " houses: rent - " << temp[i] << endl;
		}
		if (_property->GetIsLayDown())
		{
			cout << "Is lay down" << endl;
		}
		else
		{
			cout << "Isn't lay down" << endl;
		}
	}
}

//inline void Show::ShowPlayer() const
//{
//	if (_property != nullptr)
//	{
//		cout << "Nick: " << _o_playerbj->GetNick() << endl;
//		if (_player->GetInPrison())
//		{
//			cout << "In prison" << endl;
//		}
//		else
//		{
//			cout << "Not in prison" << endl;
//		}
//		int amount = _player->AmountStreet();
//		for (int i = 0; i < amount; i++)
//		{
//			cout << _player->GetStreetArr()[i]->GetName() << endl;
//		}
//		amount = _player->AmountRailway();
//		for (int i = 0; i < amount; i++)
//		{
//			cout << _player->GetRailwayArr()[i]->GetName() << endl;
//		}
//	}
//}