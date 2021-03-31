#pragma once
class Player
{
private:
	string _nickName;
	int _money = 0;
	int _amountProperty = 0;
	int _amountRailway = 0;
	bool _inPrison = false;
	Property** _property = nullptr;

	void Coppy(const Player& player);
public:
	Player() = default;
	Player(const string& nick);
	~Player();

	void SetNick(const string& nick);
	void GiveSallary(const int sallary);
	void SetProperty(Property* property);
	void PayRent(Player* player, const int sum);
	void BuildHouse(Property* property);
	void DestroyHous(Property* property);
	void LayDownProperty(Property* property);
	void RedeemProperty(Property* property);
	void Arest();
	void GiveFreedom();
	void Tax(const int tax);
	void SetAmountRailways(const int amount);

	int AmountProperty() const;
	int AmountRailway() const;
	const string& GetNick() const;
	bool GetInPrison() const;
	int GetMoney() const;
	Player* GetPlayer();
	Property** GetPropertyArr() const;

	const Player* operator = (const Player& player);
};
