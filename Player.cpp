#include "Player.h"
#include <any>

Player::Player(const std::string characterName, float healthPoints, float damagePoints, float attackSpeed)
	: Character(characterName, healthPoints, damagePoints, attackSpeed)
{
	XP = 0;
}

Player Player::parseUnit(std::string fileName)
{
  std::map<std::string, std::any> characterAttributes = JSONParser::parse(fileName, true);
  ruleOutNegativeAnyFloat(characterAttributes["hp"]);
  ruleOutNegativeAnyFloat(characterAttributes["dmg"]);
  ruleOutNegativeAnyFloat(characterAttributes["as"]);
	return Player(
        std::any_cast<std::string>(characterAttributes["name"]),
        std::any_cast<float>(characterAttributes["hp"]),
        std::any_cast<float>(characterAttributes["dmg"]),
        std::any_cast<float>(characterAttributes["as"]));
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

void Player::doHit(Character& victim)
{
	this->gainXP(victim.gotHit(this));
}
