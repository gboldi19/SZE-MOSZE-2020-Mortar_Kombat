#include "Hero.h"

Hero::Hero(
		const std::string _name,
		float _maxHP,
		float _DMG,
		float _ACD,
		float _XPtoLevelup,
		float _maxHPBonus,
		float _DMGBonus,
		float _ACDBonus)
	: Character(_name, _maxHP, _DMG, _ACD)
{
	XP = 0;
	maxHPBonus = _maxHPBonus;
	DMGBonus = _DMGBonus;
	ACDBonus = _ACDBonus;
	XPtoLevelup = _XPtoLevelup;
}

Hero Hero::parse(std::string fileName)
{
	std::map<std::string, std::any> characterAttributes = JSON::parse(fileName, true);
	JSON::ruleOutNegativeAnyFloat(characterAttributes["base_health_points"]);
	JSON::ruleOutNegativeAnyFloat(characterAttributes["base_damage"]);
	JSON::ruleOutNegativeAnyFloat(characterAttributes["base_attack_cooldown"]);
	JSON::ruleOutNegativeAnyFloat(characterAttributes["experience_per_level"]);
	JSON::ruleOutNegativeAnyFloat(characterAttributes["health_point_bonus_per_level"]);
	JSON::ruleOutNegativeAnyFloat(characterAttributes["damage_bonus_per_level"]);
	JSON::ruleOutNegativeAnyFloat(characterAttributes["cooldown_multiplier_per_level"]);
	return Hero(
        std::any_cast<std::string>(characterAttributes["name"]),
        std::any_cast<float>(characterAttributes["base_health_points"]),
        std::any_cast<float>(characterAttributes["base_damage"]),
        std::any_cast<float>(characterAttributes["base_attack_cooldown"]),
		std::any_cast<float>(characterAttributes["experience_per_level"]),
		std::any_cast<float>(characterAttributes["health_point_bonus_per_level"]),
		std::any_cast<float>(characterAttributes["damage_bonus_per_level"]),
		std::any_cast<float>(characterAttributes["cooldown_multiplier_per_level"]));
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
