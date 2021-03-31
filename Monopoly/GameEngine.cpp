#include "Header.h"

GameEngine* GameEngine::instance = nullptr;

GameEngine* GameEngine::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new GameEngine;

		instance->_playerBase = instance->_playerBase->GetInstance();
		instance->_propertyBase = instance->_propertyBase->GetInstance();

		instance->_propertyBase->CreateRailways();
		instance->_propertyBase->CreateStreets();

		srand(time(NULL));
	}
	return instance;
}

GameEngine::~GameEngine()
{
	delete _playerBase;
	delete _propertyBase;
}

void GameEngine::Load() 
{
	_settings.Cursor(55, 9);

	cout << "Loading...";
	setlocale(0, "C");

	_settings.Cursor(41, 11);

	for (int i = 0; i < 40; i++) {
		int random = rand() % 100 + 50;
		cout << char(219);
		_settings.Cursor(41 + i, 11);
		Sleep(random);
	}

	ClearScreen();
}

void GameEngine::Rules()
{
	system("mode con cols=88 lines=33");

	_settings.Cursor(0, 0);
	_show.ShowRules();

	int code;
	code = _getch();

	system("mode con cols=78 lines=19");
}

void GameEngine::NotAnoughtMoney()
{
	_settings.Cursor(80, 1);
	cout << "Not anough money!";
	Sleep(1000);
	_settings.Cursor(80, 1);
	cout << "                 ";
}

void GameEngine::ClearScreen()
{
	_settings.Cursor(0, 0);

	for (int i = 0; i < 2105; i++)
	{
		cout << " ";
	}
}

void GameEngine::Menu()
{
	_settings.Cursor(0, 0);
	_settings.SetColour(Colours::Green);

	cout << "Amount players: " << _playerBase->GetAmountPlayer() << "\n\n"
		<< "Add Players: 1" << endl;

	if (_playerBase->GetAmountPlayer() < 2)
	{
		_settings.SetColour(Colours::DarkRed);
	}
	else
	{
		_settings.SetColour(Colours::Cyan);
	}

	cout << "Start Game: 2" << endl;

	_settings.SetColour(Colours::Green);

	_settings.SetColour(Colours::DarkPink);
	cout << "Rules: 3" << endl;
	_settings.SetColour(Colours::Green);

	_settings.SetColour(Colours::DarkYellow);
	cout << "For escape press: ESC" << endl;
	_settings.SetColour(Colours::Green);
}

void GameEngine::ChekForAmountPlayers()
{
	if (_playerBase->GetAmountPlayer() > 4)
	{
		ClearScreen();
		_settings.Cursor(0, 0);
		throw SoMuchPlayers();
	}
}

void GameEngine::SetPlayers()
{
	ClearScreen();

	_settings.Cursor(0, 0);

	string nick;
	cout << "Enter nick: ";
	cin >> nick;

	try
	{
		ChekForAmountPlayers();
		ChekingForTheSameNick(nick);
	}
	catch (const SoMuchPlayers muchPlayers)
	{
		cout << muchPlayers.what();
		Sleep(500);
	}
	catch (const TheSamePlayer& samePlayer)
	{
		cout << samePlayer.what();
		Sleep(500);
	}
}

void GameEngine::ShowingTurn(Player* player)
{
	if (_player->AmountProperty())
	{
		_show.DrowFrame(7 + _player->AmountProperty() + 2, 23, 0, 0);
	}
	else
	{
		_show.DrowFrame(7, 23, 0, 0);
	}
	_settings.Cursor(1, 1);

	cout << "Now turn: ";
	_settings.SetColour(Colours::Red);
	cout << player->GetNick() << endl << endl;
	_settings.SetColour(Colours::Green);
}

void GameEngine::ShowingPlayer(Player* player)
{
	_show.SetPlayer(player);
	_show.ShowPlayer(1, 3);
}

void GameEngine::ShowingCard()
{
	int random = rand() % 10 + 1;

	switch (random)
	{
	case (1):
		_property = _propertyBase->GetStreetArr()[0].GetStreet();
		_show.SetProperty(_property);
		_show.ShowStreet(Colours::DarkGreen);
		break;
	case (2):
		_property = _propertyBase->GetStreetArr()[1].GetStreet();
		_show.SetProperty(_property);
		_show.ShowStreet(Colours::DarkPink);
		break;
	case (3):
		_property = _propertyBase->GetStreetArr()[2].GetStreet();
		_show.SetProperty(_property);
		_show.ShowStreet(Colours::DarkYellow);
		break;
	case (4):
		_property = _propertyBase->GetStreetArr()[3].GetStreet();
		_show.SetProperty(_property);
		_show.ShowStreet(Colours::Cyan);
		break;
	case (5):
		_property = _propertyBase->GetStreetArr()[4].GetStreet();
		_show.SetProperty(_property);
		_show.ShowStreet(Colours::DarkRed);
		break;
	case (6):
		_property = _propertyBase->GetRailwayArr()[0].GetRailway();
		_show.SetProperty(_property);
		break;
	case (7):
		_property = _propertyBase->GetRailwayArr()[1].GetRailway();
		_show.SetProperty(_property);
		break;
	case (8):
		_property = _propertyBase->GetRailwayArr()[2].GetRailway();
		_show.SetProperty(_property);
		break;
	case (9):
		_property = _propertyBase->GetRailwayArr()[3].GetRailway();
		_show.SetProperty(_property);
		break;
	case (10):
		Arest();
		break;
	}

	if (random > 5 && !_player->GetInPrison())
	{
		_show.ShowRailway(Colours::DarkWhite);
	}
}

bool GameEngine::StartMenu()
{
	int code;

	while (true)
	{
		_settings.SetColour(Colours::Green);
		Menu();

		code = _getch();
		if (code == Keys::One)
		{
			SetPlayers();
		}
		else if (code == Keys::Two && _playerBase->GetAmountPlayer() > 1)
		{
			ClearScreen();
			break;
		}
		else if (code == Keys::Three)
		{
			ClearScreen();
			Rules();
		}
		else if (code == Keys::ESC)
		{
			return true;
		}
		ClearScreen();
	}

	return false;
}

void GameEngine::ShowingPlayerActrions()
{
	_show.DrowFrame(19, 21, 56, 0);

	_settings.Cursor(57, 1);

	if (_property->GetMaster() != nullptr)
	{
		_settings.SetColour(Colours::DarkRed);
	}
	cout << "By property: 1" << endl;
	_settings.SetColour(Colours::Green);

	_show.DrawLine(21, 56, 2);

	//////////////////////////////////////////////////////

	_settings.Cursor(57, 3);

	if (_property->GetMaster() == nullptr)
	{
		_settings.SetColour(Colours::DarkRed);
	}
	else if (_property->GetMaster()->GetNick() == _player->GetNick() ||
		_property->GetMaster()->GetInPrison() || _property->GetIsLayDown())
	{
		_settings.SetColour(Colours::DarkRed);
	}
	cout << "Pay rent: 2" << endl;
	_settings.SetColour(Colours::Green);

	_show.DrawLine(21, 56, 4);

	//////////////////////////////////////////////////////

	_settings.Cursor(57, 5);

	if (_property->GetMaster() == nullptr)
	{
		_settings.SetColour(Colours::DarkRed);
	}
	else if (_property->GetMaster()->GetNick() != _player->GetPlayer()->GetNick() ||
		_property->GetIsLayDown() || _property->GetAmountHouses() > 0)
	{
		_settings.SetColour(Colours::DarkRed);
	}
	cout << "Lay down: 3" << endl;
	_settings.SetColour(Colours::Green);

	_show.DrawLine(21, 56, 6);

	//////////////////////////////////////////////////////

	_settings.Cursor(57, 7);

	if (_property->GetIdentificator() == 2)
	{
		_settings.SetColour(Colours::DarkRed);
	}
	else if (_property->GetMaster() == nullptr)
	{
		_settings.SetColour(Colours::DarkRed);
	}
	else if (_property->GetMaster()->GetNick() != _player->GetPlayer()->GetNick() ||
		_property->GetAmountHouses() >= 5 || _property->GetIsLayDown())
	{
		_settings.SetColour(Colours::DarkRed);
	}
	cout << "Build house: 4" << endl;
	_settings.SetColour(Colours::Green);

	_show.DrawLine(21, 56, 8);

	//////////////////////////////////////////////////////

	_settings.Cursor(57, 9);

	if (_property->GetMaster() != nullptr)
	{
		if (_property->GetMaster()->GetNick() == _player->GetNick() &&
			_property->GetAmountHouses() == 0 || 
			_property->GetMaster()->GetNick() != _player->GetNick())
		{
			_settings.SetColour(Colours::DarkRed);
		}
	}
	else
	{
		_settings.SetColour(Colours::DarkRed);
	}
	cout << "Destroy house: 5" << endl;
	_settings.SetColour(Colours::Green);

	_show.DrawLine(21, 56, 10);

	//////////////////////////////////////////////////////
	
	_settings.Cursor(57, 11);

	if (_property->GetMaster() == nullptr)
	{
		_settings.SetColour(Colours::DarkRed);
	}
	else if (_property->GetMaster()->GetNick() != _player->GetPlayer()->GetNick() ||
		!_property->GetIsLayDown())
	{
		_settings.SetColour(Colours::DarkRed);
	}
	cout << "Redeem property: 6" << endl;
	_settings.SetColour(Colours::Green);

	_show.DrawLine(21, 56, 12);

	//////////////////////////////////////////////////////

	_settings.Cursor(57, 13);

	cout << "Declare bankrupt: 7" << endl;

	_show.DrawLine(21, 56, 14);

	//////////////////////////////////////////////////////

	_settings.Cursor(57, 15);

	if (_property->GetMaster() != nullptr)
	{
		if (!_property->GetIsLayDown() && _property->GetMaster()->GetNick() != _player->GetNick() &&
			!_property->GetMaster()->GetInPrison())
		{
			_settings.SetColour(Colours::DarkRed);
		}
	}
	cout << "Skip turn: 8" << endl;
	_settings.SetColour(Colours::Green);

	_show.DrawLine(21, 56, 16);

	//////////////////////////////////////////////////////

	_settings.Cursor(57, 17);

	if (_property->GetMaster() != nullptr)
	{
		if (_property->GetMaster()->GetNick() != _player->GetPlayer()->GetNick())
		{
			if (!_property->GetIsLayDown() && !_property->GetMaster()->GetInPrison())
			{
				_settings.SetColour(Colours::DarkRed);
			}
		}
		else if (_player->GetInPrison())
		{
			_settings.SetColour(Colours::DarkRed);
		}
	}
	if (_player->AmountProperty() == 0)
	{
		_settings.SetColour(Colours::DarkRed);
	}

	cout << "Make a deal: 9" << endl;
	_settings.SetColour(Colours::Green);
}

void GameEngine::ChekingForTheSameNick(const string& nick)
{
	if (_playerBase->GetPlayerArray() != nullptr)
	{
		bool temp = false;

		size_t size = _playerBase->GetAmountPlayer();
		for (size_t i = 0; i < size; i++)
		{
			if (nick == _playerBase->GetPlayerArray()[i].GetNick())
			{
				temp = true;
				break;
			}
		}

		if (!temp)
		{
			Player player(nick);
			_playerBase->SetPlayer(player);
		}
		else
		{
			_settings.Cursor(0, 0);
			cout << "Player with the same nick already exists." << endl;

			Sleep(500);
		}
	}
	else
	{
		Player player(nick);
		_playerBase->SetPlayer(player);
	}
}

bool GameEngine::BumCheking(Player* player)
{
	if (_player->GetMoney() < 0)
	{
		_playerBase->DeletePlayer(_player);
		_player = nullptr;

		return true;
	}
	return false;
}

bool GameEngine::CheckingForLastPlayer()
{
	if (_playerBase->GetAmountPlayer() == 1)
	{
		return true;
	}
	return false;
}

void GameEngine::Actions(int& i)
{
	bool action = false;

	int code;

	while (!action)
	{
		code = _getch();

		switch (code)
		{
		case(Keys::One):
			Buying(action);
			break;
		case(Keys::Two):
			PayRent(action);
			break;
		case(Keys::Three):
			LayDownProperty(action);
			break;
		case(Keys::Four):
			BuildHouse(action);
			break;
		case(Keys::Five):
			DestroyHouse(action);
			break;
		case(Keys::Six):
			RedeemProperty(action);
			break;
		case(Keys::Seven):
			DeletePlayer(action, i);
			break;
		case(Keys::Eight):
			SkeepTurn(action);
			break;
		case(Keys::Nine):
			if (_property->GetMaster() != nullptr)
			{
				if (_property->GetMaster()->GetNick() == _player->GetPlayer()->GetNick())
				{
					if (!_player->GetInPrison())
					{
						ShowPlayersToDeal(action);
					}
				}
				else if (_property->GetIsLayDown() || _property->GetMaster()->GetInPrison())
				{
					if (!_player->GetInPrison())
					{
						ShowPlayersToDeal(action);
					}
				}
			}
			else
			{
				if (_player->GetPlayer()->AmountProperty() != 0)
				{
					ShowPlayersToDeal(action);
				}
			}
			break;
		}
	}
}

void GameEngine::ShowPlayersToDeal(bool& action)
{
	Property* myProperty = nullptr;
	Property* otherPlayerProperty = nullptr;

	Player* player = nullptr;
	const int size = _playerBase->GetAmountPlayer();

	while (true)
	{
		for (int i = 0; i < size; i++)
		{
			player = _playerBase->GetPlayerArray()[i].GetPlayer();

			if (player != _player && !player->GetInPrison())
			{
				ClearScreen();

				ShowingTurn(_player);
				ShowingPlayer(_player);

				_show.DrowFrame(5, 35, 24, 0);

				_settings.Cursor(25, 1);
				cout << "Next player: 1";
				_settings.Cursor(25, 2);
				cout << "Select: 2";
				_settings.Cursor(25, 3);
				cout << "Exit(You will skeep your turn): 3";
				_settings.Cursor(25, 4);
				
				int select = Select();
				if (select == 2 && player->AmountProperty() != 0)
				{
					ShowPlayerStreets(player);
				}
				else if (select == 3)
				{
					player = nullptr;
					action = true;
					return;
				}
			}
		}
	}
}

void GameEngine::ShowPlayerStreets(Player* player)
{
	Property* property = nullptr;
	const int size = player->AmountProperty();

	while (true)
	{
		for (int i = 0; i < size; i++)
		{
			property = player->GetPropertyArr()[i];

			ClearScreen();
			_settings.Cursor(0, 0);

			_show.SetProperty(property);
			if (property->GetIdentificator() == 1)
			{
				_show.ShowStreet(property->GetColor());
			}
			else
			{
				_show.ShowRailway(property->GetColor());
			}

			TextDeal();

			int select = Select();
			if (select == 2)
			{
				if (ShowMyStreets(i, player))
				{
					return;
				}
			}
			else if (select == 3)
			{
				property = nullptr;
				return;
			}
		}
	}
}

bool GameEngine::ShowMyStreets(const int propertyIndex, Player* player)
{
	Property* myProperty = nullptr;
	const int size = _player->AmountProperty();

	while (true)
	{
		for (int i = 0; i < size; i++)
		{
			myProperty = _player->GetPropertyArr()[i];

			ClearScreen();
			_settings.Cursor(0, 0);

			_show.SetProperty(myProperty);
			if (myProperty->GetIdentificator() == 1)
			{
				_show.ShowStreet(myProperty->GetColor());
			}
			else
			{
				_show.ShowRailway(myProperty->GetColor());
			}

			TextDeal();

			int select = Select();
			if (select == 2)
			{
				if (Deal(i, propertyIndex, player))
				{
					return true;
				}
			}
			else if (select == 3)
			{
				myProperty = nullptr;
				return false;
			}
		}
	}
}

void GameEngine::TextDeal()
{
	_show.DrowFrame(5, 18, 0, 0);

	_settings.Cursor(1, 1);
	cout << "Next property: 1";
	_settings.Cursor(1, 2);
	cout << "Select: 2";
	_settings.Cursor(1, 3);
	cout << "Exit: 3";
}

bool GameEngine::Deal(const int myPropertyIndex, const int PropertyIndex, Player* player)
{
	Property* myProperty = _player->GetPropertyArr()[myPropertyIndex];
	Property* playerProperty = player->GetPropertyArr()[PropertyIndex];

	myProperty->SetMaster(player);
	playerProperty->SetMaster(_player);

	if (myProperty->GetIdentificator() != 2 && playerProperty->GetIdentificator() != 2)
	{
		if (myProperty->GetIdentificator() == 2)
		{
			_player->SetAmountRailways(_player->AmountRailway() - 1);
			player->SetAmountRailways(player->AmountRailway() + 1);
		}
		else if (playerProperty->GetIdentificator() == 2)
		{
			_player->SetAmountRailways(_player->AmountRailway() + 1);
			player->SetAmountRailways(player->AmountRailway() - 1);
		}
	}

	swap(player->GetPropertyArr()[PropertyIndex], _player->GetPropertyArr()[myPropertyIndex]);

	return true;
}

int GameEngine::Select()
{
	while (true)
	{
		int code = _getch();

		switch (code)
		{
		case(Keys::One):
			return 1;
		case(Keys::Two):
			return 2;
		case(Keys::Three):
			return 3;
		}
	}

	return 0;
}

void GameEngine::Buying(bool& action)
{
	if (_property->GetMaster() == nullptr && _player->GetMoney() >= _property->GetPrice())
	{
		_player->SetProperty(_property);
		_property->SetMaster(_player);
		action = true;
	}
	else if (_player->GetMoney() < _property->GetPrice())
	{
		NotAnoughtMoney();
	}
}

void GameEngine::PayRent(bool& action)
{
	if (_property->GetMaster() != nullptr)
	{
		if (_property->GetMaster()->GetNick() != _player->GetPlayer()->GetNick() &&
			!_property->GetIsLayDown() && !_property->GetMaster()->GetInPrison())
		{
			if (_property->GetIdentificator() == 1)
			{
				_player->PayRent(_property->GetMaster(), _property->GetRent()[_property->GetAmountHouses()]);
			}
			else if (_property->GetIdentificator() == 2)
			{
				_player->PayRent(_property->GetMaster(), _property->GetRent()[_player->AmountRailway()]);
			}
			action = true;
		}
	}
}

void GameEngine::LayDownProperty(bool& action)
{
	if (_property->GetMaster() != nullptr)
	{
		if (_property->GetMaster()->GetNick() == _player->GetPlayer()->GetNick() &&
			!_property->GetIsLayDown() &&
			(_property->GetIdentificator() == 1 && _property->GetAmountHouses() == 0 ||
				_property->GetIdentificator() == 2))
		{
			_player->LayDownProperty(_property);
			action = true;
		}
	}
}

void GameEngine::BuildHouse(bool& action)
{
	if (_property->GetMaster() != nullptr && _property->GetIdentificator() == 1 &&
		_property->GetAmountHouses() < 5 && _player->GetMoney() >= _property->GetRent()[_property->GetAmountHouses()] &&
		!_property->GetIsLayDown())
	{
		if (_property->GetMaster()->GetNick() == _player->GetNick())
		{
			_player->BuildHouse(_property);
			action = true;
		}
	}
	else if (_player->GetMoney() < _property->GetRent()[_property->GetAmountHouses()])
	{
		NotAnoughtMoney();
	}
}

void GameEngine::DestroyHouse(bool& action)
{
	if (_property->GetMaster() != nullptr && _property->GetIdentificator() == 1 &&
		_property->GetAmountHouses() > 0 && !_property->GetIsLayDown())
	{
		if (_property->GetMaster()->GetNick() == _player->GetNick())
		{
			_player->DestroyHous(_property);
			action = true;
		}
	}
}

void GameEngine::RedeemProperty(bool& action)
{
	if (_property->GetMaster() != nullptr && _property->GetIsLayDown())
	{
		if (_property->GetMaster()->GetNick() == _player->GetNick())
		{
			_player->RedeemProperty(_property);
			action = true;
		}
	}
}

void GameEngine::DeletePlayer(bool& action, int& i)
{
	_playerBase->DeletePlayer(_player);
	_player = nullptr;

	i--;
	action = true;
}

void GameEngine::SkeepTurn(bool& action)
{
	if (_property->GetMaster() != nullptr)
	{
		if (_property->GetMaster()->GetNick() != _player->GetNick())
		{
			if (_property->GetIsLayDown() || _property->GetMaster()->GetInPrison())
			{
				action = true;
			}
		}
		else
		{
			action = true;
		}
	}
	else
	{
		action = true;
	}
}

void GameEngine::ChecingForPrisoners()
{
	for (int i = 0; i < _playerBase->GetAmountPlayer(); i++)
	{
		if (_playerBase->GetPlayerArray()[i].GetInPrison())
		{
			_playerBase->GetPlayerArray()[i].GiveFreedom();
		}
	}
}

void GameEngine::ShowWinner(bool& temp)
{
	ClearScreen();

	MusikEnd();

	for (int i = 0; i < 3; i++)
	{
		for (int i = 10; i < 16; i++)
		{
			_settings.Cursor(28, 8);
			_settings.SetColour(i);
			cout << "Player #" << _playerBase->GetPlayerArray()[0].GetNick() << " is winner!!!";
			Sleep(300);
		}
	}

	_settings.SetColour(Colours::Green);

	Sleep(1000);
	temp = true;
	ClearScreen();
}

void GameEngine::Arest()
{
	_player->Arest();

	ClearScreen();
	_settings.Cursor(0, 0);

	ShowingTurn(_player);
	ShowingPlayer(_player);
}

void GameEngine::MusikStart()
{
	Beep(494, 100);
	Beep(523, 100);
	Beep(587, 100);
}

void GameEngine::MusikEnd()
{
	Beep(494, 500);
	for (int i = 0; i < 2; i++)
		Beep(523, 100);
	Beep(523, 100);
	Beep(880, 500);
}

void GameEngine::Playing()
{
	bool temp = false;

	while (true)
	{
		for (int i = 0; i < _playerBase->GetAmountPlayer(); i++)
		{
			_player = _playerBase->GetPlayerArray()[i].GetPlayer();
			
			Sleep(100);

			_settings.Cursor(0, 0);

			ShowingTurn(_player);

			ShowingPlayer(_player);

			cout << endl;

			ShowingCard();

			if (!_player->GetInPrison())
			{
				ShowingPlayerActrions();

				if (BumCheking(_player))
				{
					break;
				}

				Actions(i);

				if (_player != nullptr)
				{
					_player->GiveSallary(150);
					_player->Tax(50);
				}
			}
			else
			{
				Sleep(1000);
			}

			if (CheckingForLastPlayer())
			{
				ShowWinner(temp);
				break;
			}

			ClearScreen();
		}

		ChecingForPrisoners();

		if (temp)
		{
			break;
		}
	}
}

