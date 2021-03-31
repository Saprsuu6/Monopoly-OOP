#pragma once

enum Keys {
	One = 49, Two = 50, Three = 51, Four = 52,
	Five = 53, Six = 54, Seven = 55, Eight = 56,
	Nine = 57, ESC = 27
};

class GameEngine
{
	static GameEngine* instance;
private:
	View _show;
	ConsoleSettings _settings;
	PlayerBase* _playerBase = nullptr;
	PropertyBase* _propertyBase = nullptr;
	Property* _property = nullptr;
	Player* _player = nullptr;

	void Rules();
	void NotAnoughtMoney();
	void ClearScreen();
	void Menu();
	void SetPlayers();
	void ShowingTurn(Player* player);
	void ShowingPlayer(Player* player);
	void ShowingCard();
	void ShowingPlayerActrions();
	void ChekingForTheSameNick(const string& nick);
	bool BumCheking(Player* player);
	bool CheckingForLastPlayer();
	void Actions(int& i);

	void TextDeal();
	void ShowPlayersToDeal(bool& action);
	void ShowPlayerStreets(Player* player);
	bool ShowMyStreets(const int propertyIndex, Player* player);
	bool Deal(const int myPropertyIndex, const int PropertyIndex, Player* player);
	int Select();

	void ChekForAmountPlayers();
	void Buying(bool& action);
	void PayRent(bool& action);
	void LayDownProperty(bool& action);
	void BuildHouse(bool& action);
	void DestroyHouse(bool& action);
	void RedeemProperty(bool& action);
	void DeletePlayer(bool& action, int& i);
	void SkeepTurn(bool& action);
	void ChecingForPrisoners();
	void ShowWinner(bool& temp);
	void Arest();

	GameEngine() = default;
public:
	~GameEngine();

	void MusikStart();
	void MusikEnd();
	void Load();
	bool StartMenu();
	void Playing();

	static GameEngine* GetInstance();
};

