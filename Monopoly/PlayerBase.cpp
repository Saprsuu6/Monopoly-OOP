#include "Header.h"

PlayerBase* PlayerBase::instance = nullptr;

PlayerBase* PlayerBase::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new PlayerBase;
		instance->_playerArray = new Player[instance->GetAmountPlayer()];
	}
	return instance;
}

PlayerBase::~PlayerBase()
{
	delete[] _playerArray;
}

void PlayerBase::SetPlayer(const Player& player)
{
	Player* array = new Player[_amountPlayers + 1];

	for (int i = 0; i < _amountPlayers; i++)
	{
		array[i] = _playerArray[i];
	}

	this->~PlayerBase();

	array[_amountPlayers] = player;
	_playerArray = array;
	array = nullptr;

	_amountPlayers++;
}

void PlayerBase::ResetStreets(Player* player)
{
	int size = player->AmountProperty();

	for (int i = 0; i < size; i++)
	{
		player->GetPropertyArr()[i]->SetMaster(nullptr);

		player->GetPropertyArr()[i]->Redeem();
		player->GetPropertyArr()[i]->ResetAmountOfHouses();
	}
}

void PlayerBase::DeletePlayer(Player* player)
{
	bool temp = false;
	Player* array = new Player[_amountPlayers - 1];

	ResetStreets(player);

	for (int i = 0; i < _amountPlayers - 1; i++)
	{
		if (_playerArray[i].GetNick() == player->GetNick())
		{
			temp = true;
		}
		if (!temp)
		{
			array[i] = _playerArray[i];
		}
		else
		{
			array[i] = _playerArray[i + 1];
		}
	}

	player->~Player();

	_playerArray = array;
	array = nullptr;

	_amountPlayers--;
}

Player* PlayerBase::GetPlayerArray()
{
	return _playerArray;
}

int PlayerBase::GetAmountPlayer()
{
	return _amountPlayers;
}
