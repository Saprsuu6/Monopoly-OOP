#include "Header.h"

void View::SetProperty(Property* property)
{
	_property = property;
}

void View::SetPlayer(Player* player)
{
	_player = player;
}

void View::ShowRules() const
{
	WorkingFile work("Rules\\Rules.dll");
	work.ReadRules();

	cout << "\nFor exape press any key.";
}

void View::ShowRailway(const int coulour)
{
	if (_property != nullptr)
	{
		DrowFrame(15, 29, 25, 0);

		_settings.Cursor(26, 1);

		_settings.SetColour(coulour);
		cout << "Name: " << _property->GetName();
		_settings.SetColour(Colours::Green);

		DrawLine(29, 25, 2);

		_settings.Cursor(26, 3);
		cout << "Price: " << _property->GetPrice();
		_settings.Cursor(26, 4);
		cout << "Collateral value: " << _property->GetCollateralValue() << endl;

		DrawLine(29, 25, 5);

		_settings.SetColour(coulour);
		const int* temp = _property->GetRent();
		for (int i = 0; i < _property->GetAmountProperties(); i++)
		{
			_settings.Cursor(26, i + 6);
			cout << "Rl. Station #" << i + 1 << ": rent - " << temp[i] << endl;
		}
		_settings.SetColour(Colours::Green);

		DrawLine(29, 25, 10);

		_settings.SetColour(Colours::Green);
		_settings.Cursor(26, 11);
		if (_property->GetIsLayDown())
		{
			cout << "Is lay down\n" << endl;
		}
		else
		{
			cout << "Isn't lay down\n" << endl;
		}

		DrawLine(29, 25, 12);

		_settings.Cursor(26, 13);
		if (_property->GetMaster() != nullptr)
		{
			cout << "Owner: ";
			_settings.SetColour(Colours::Red);
			cout << _property->GetMaster()->GetNick() << endl;
		}
		else
		{
			cout << "Owner: ";
			_settings.SetColour(Colours::Red);
			cout << '-' << endl;
		}

		_settings.SetColour(Colours::Green);
	}
}

void View::ShowStreet(const int coulour)
{
	if (_property != nullptr)
	{
		DrowFrame(18, 29, 25, 0);

		_settings.Cursor(26, 1);

		_settings.SetColour(coulour);
		cout << "Name: " << _property->GetName();
		_settings.SetColour(Colours::Green);

		DrawLine(29, 25, 2);

		_settings.Cursor(26, 3);
		cout << "Price: " << _property->GetPrice();
		_settings.Cursor(26, 4);
		cout << "Collateral value: " << _property->GetCollateralValue();
		_settings.Cursor(26, 5);
		cout << "Amount houses: " << _property->GetAmountHouses();

		DrawLine(29, 25, 6);
		
		const int* temp = _property->GetRent();
		_settings.SetColour(coulour);
		for (int i = 0; i < _property->GetAmountProperties(); i++)
		{
			_settings.Cursor(26, i + 7);
			cout << i << " houses: rent - " << temp[i];
		}
		_settings.SetColour(Colours::Green);

		DrawLine(29, 25, 13);

		_settings.Cursor(26, 14);
		_settings.SetColour(Colours::Green);
		if (_property->GetIsLayDown())
		{
			cout << "Is lay down" << endl;
		}
		else
		{
			cout << "Isn't lay down" << endl;
		}

		DrawLine(29, 25, 15);

		_settings.Cursor(26, 16);
		if (_property->GetMaster() != nullptr)
		{
			cout << "Owner: ";
			_settings.SetColour(Colours::Red);
			cout << _property->GetMaster()->GetNick() << endl;
		}
		else
		{
			cout << "Owner: ";
			_settings.SetColour(Colours::Red);
			cout << '-' << endl;
		}

		_settings.SetColour(Colours::Green);
	}
}

void View::ShowPlayer(const int x, const int y)
{
	_settings.Cursor(x, y);
	cout << "Nick: ";
	_settings.SetColour(Colours::Red);
	cout << _player->GetNick() << endl;

	DrawLine(23, 0, 2);

	_settings.Cursor(x, y + 1);
	_settings.SetColour(Colours::Green);
	cout << "Money: " << _player->GetMoney() << endl;

	if (_player->AmountProperty()) {
		DrawLine(23, 0, 6);
	}

	_settings.Cursor(x, y + 2);
	if (_player->GetInPrison())
	{
		cout << "In prison" << endl;
	}
	else
	{
		cout << "Not in prison" << endl;
	}

	if (_player->AmountProperty() > 0)
	{
		_settings.Cursor(x, y + 4);
		cout << "Propertyes: " << endl;
		int amount = _player->AmountProperty();
		for (int i = 0; i < amount; i++)
		{
			_settings.Cursor(x, (y + 4) + i + 1);
			_settings.SetColour(_player->GetPropertyArr()[i]->GetColor());
			cout << _player->GetPropertyArr()[i]->GetName() << endl;
		}

		_settings.SetColour(Colours::Green);
	}
}

void View::DrowFrame(const int hight, const int width, int x, int y)
{
	_settings.SetColour(Colours::DarkYellow);

	for (int i = 0; i < hight; i++)
	{
		for (int j = 0; j < width; j++)
		{
			_settings.Cursor(x + j, y + i);
			if (i == 0 && j == 0)
			{
				cout << char(201);
			}
			else if (i == 0 && j == width - 1)
			{
				cout << char(187);
			}
			else if (i == hight - 1 && j == 0)
			{
				cout << char(200);
			}
			else if (i == hight - 1 && j == width - 1)
			{
				cout << char(188);
			}
			else if (j == 0 || j == width - 1)
			{
				cout << char(186);
			}
			else if (i == 0 || i == hight - 1)
			{
				cout << char(205);
			}
			else
			{
				cout << " ";
			}
		}
	}
	_settings.SetColour(Colours::Green);
}

void View::DrawLine(const int width, int x, int y)
{
	_settings.SetColour(Colours::DarkYellow);

	for (int j = 0; j < width; j++)
	{
		_settings.Cursor(x + j, y);
		if (j == 0)
		{
			cout << char(204);
		}
		else if (j == width - 1)
		{
			cout << char(185);
		}
		else
		{
			cout << char(205);
		}
	}
	_settings.SetColour(Colours::Green);
}
