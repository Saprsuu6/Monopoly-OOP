#include "Header.h"

void Player::Coppy(const Player& player)
{
	_nickName = player._nickName;
	_money = player._money;
	_amountRailway = player._amountRailway;
	_amountProperty = player._amountProperty;
	_inPrison = player._inPrison;
	_property = new Property * [player._amountProperty];
	for (int i = 0; i < player._amountProperty; i++)
	{
		_property[i] = player._property[i];
	}
}

Player::Player(const string& nick)
{
	SetNick(nick);
	_money = 1000;
}

Player::~Player()
{
	delete[] _property;
}

void Player::PayRent(Player* player, const int sum)
{
	player->GiveSallary(sum);
	_money -= sum;
}

void Player::BuildHouse(Property* property)
{
	property->BuildHouse();
	int amount_house = property->GetAmountHouses();
	int sum = property->GetRent()[amount_house + 1] * 2;
	_money -= sum;
}

void Player::DestroyHous(Property* property)
{
	property->DestroyHouse();
	int amount_house = property->GetAmountHouses();
	int sum = property->GetRent()[amount_house] / 2;
	_money += sum;
}

void Player::LayDownProperty(Property* property)
{
	property->LayDown();
	_money += property->GetCollateralValue();
}

void Player::RedeemProperty(Property* property)
{
	property->Redeem();
}

void Player::Arest()
{
	if (!_inPrison)
	{
		_inPrison = true;
	}
}

void Player::GiveFreedom()
{
	if (_inPrison)
	{
		_inPrison = false;
	}
}

void Player::Tax(const int tax)
{
	if (tax > 0)
	{
		_money -= tax;
	}
}

void Player::SetAmountRailways(const int amount)
{
	_amountRailway = amount;
}

int Player::AmountProperty() const
{
	return _amountProperty;
}

int Player::AmountRailway() const
{
	return _amountRailway;
}

void Player::SetNick(const string& nick)
{
	if (nick.find_first_not_of("AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz123456789 ")
		&& nick != " " && nick.size() != 0)
	{
		_nickName = nick;
	}
}

void Player::GiveSallary(const int sallary)
{
	if (_money > 0)
	{
		_money += sallary;
	}
}

void Player::SetProperty(Property* property)
{
	Property** temp = new Property * [_amountProperty + 1];

	for (int i = 0; i < _amountProperty; i++)
	{
		temp[i] = _property[i];
	}

	temp[_amountProperty] = property;
	_property = temp;
	temp = nullptr;

	_amountProperty++;

	if (property->GetIdentificator() == 2)
	{
		_amountRailway++;
	}

	_money -= property->GetPrice();
}

const string& Player::GetNick() const
{
	return _nickName;
}

bool Player::GetInPrison() const
{
	return _inPrison;
}

int Player::GetMoney() const
{
	return _money;
}

Player* Player::GetPlayer()
{
	return this;
}

Property** Player::GetPropertyArr() const
{
	return _property;
}

const Player* Player::operator=(const Player& player)
{
	if (this != &player)
	{
		if (this != nullptr)
		{
			this->~Player();
		}
		Coppy(player);
	}

	return this;
}