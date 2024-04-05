#pragma once
class Player
{
private:
	int xp;
	int money;

public:
	Player();

	int GetXP();
	int GetMoney();
	void AddXP(int amount);
	void AddMoney(int amount);
};

