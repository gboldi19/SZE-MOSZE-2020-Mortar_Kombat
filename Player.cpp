#include "Player.h"

Player::Player(const std::string* characterAttributes)
	: Character(characterAttributes)
{
	XP = 0;
}

void Player::levelup(float levelupXP)
{
	while (levelupXP >= 100)
	{
		levelupXP -= 100;
		HP = maxHP = round(maxHP * 1.1f);
		DMG *= 1.1f;
	}
}

void Player::gainXP(float damagePoints)
{
	levelup(XP - int(XP / 100) * 100 + damagePoints);
	XP += damagePoints;
}

Player Player::PlayerFromFile(const std::string &fileName)
{
	return Player(parseUnit(fileName));
}

void Player::doHit(Character& victim)
{
	this->gainXP(victim.gotHit(this));
}
