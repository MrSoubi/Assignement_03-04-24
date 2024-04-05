#include "pch.h"
#include "Player.h"

Player::Player()
{
	xp = 0;
	money = 0;
}

int Player::GetXP()
{
	return xp;
}

int Player::GetMoney()
{
	return money;
}

void Player::AddXP(int amount)
{
	xp += amount;
}

void Player::AddMoney(int amount)
{
	money += amount;
}
