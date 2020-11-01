#include "Hero.h"

Hero::Hero(const std::string characterName, float healthPoints, float damagePoints, float attackCoolDown)
	: Character(characterName, healthPoints, damagePoints, attackCoolDown)
{
	XP = 0;
}

Hero Hero::parse(std::string fileName)
{
  std::map<std::string, std::any> characterAttributes = JSON::parse(fileName, true);
  ruleOutNegativeAnyFloat(characterAttributes["hp"]);
  ruleOutNegativeAnyFloat(characterAttributes["dmg"]);
  ruleOutNegativeAnyFloat(characterAttributes["as"]);
	return Hero(
        std::any_cast<std::string>(characterAttributes["name"]),
        std::any_cast<float>(characterAttributes["hp"]),
        std::any_cast<float>(characterAttributes["dmg"]),
        std::any_cast<float>(characterAttributes["as"]));
}

void Hero::levelup(float levelupXP)
{
	while (levelupXP >= 100)
	{
		levelupXP -= 100;
		HP = maxHP = round(maxHP * 1.1f);
		DMG *= 1.1f;
	}
}

void Hero::gainXP(float damagePoints)
{
	levelup(XP - int(XP / 100) * 100 + damagePoints);
	XP += damagePoints;
}

void Hero::doHit(Character& victim)
{
	this->gainXP(victim.gotHit(this));
}

const unsigned int Hero::getLevel() const
{
	return int(XP / 100);
}
