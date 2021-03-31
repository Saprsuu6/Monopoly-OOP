#pragma once
class PlayerBase
{
	static PlayerBase* instance;
private:
	Player* _playerArray = nullptr;
	int _amountPlayers = 0;

	PlayerBase() = default;
public:
	PlayerBase(const PlayerBase& base) = delete;
	PlayerBase(PlayerBase&& base) = delete;
	~PlayerBase();

	void SetPlayer(const Player& player);
	void ResetStreets(Player* player);
	void DeletePlayer(Player* player);
    Player* GetPlayerArray();
	int GetAmountPlayer();

	const PlayerBase* operator = (const PlayerBase& base) = delete;
	const PlayerBase* operator = (PlayerBase&& base) = delete;

	static PlayerBase* GetInstance();
};

