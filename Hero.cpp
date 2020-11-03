#include "Hero.h"

Hero::Hero(
		const std::string _name,
		float _maxHP,
		float _DMG,
		float _ACD,
		float _XPToLevelup,
		float _maxHPBonus,
		float _DMGBonus,
		float _ACDBonus)
	: Character(_name, _maxHP, _DMG, _ACD)
{
	XP = 0;
	maxHPBonus = _maxHPBonus;
	DMGBonus = _DMGBonus;
	ACDBonus = _ACDBonus;
	XPToLevelup = _XPToLevelup;
}

Hero Hero::parse(std::string fileName)
{
	JSON characterAttributes = JSON::parseFromFile(fileName);
	return Hero(
		characterAttributes.get<std::string>("name"),
		JSON::RONAF(characterAttributes.get<float>("base_health_points")),
		JSON::RONAF(characterAttributes.get<float>("base_damage")),
		JSON::RONAF(characterAttributes.get<float>("base_attack_cooldown")),
		JSON::RONAF(characterAttributes.get<float>("experience_per_level")),
		JSON::RONAF(characterAttributes.get<float>("health_point_bonus_per_level")),
		JSON::RONAF(characterAttributes.get<float>("damage_bonus_per_level")),
		JSON::RONAF(characterAttributes.get<float>("cooldown_multiplier_per_level")));
}

void Hero::levelup(float levelupXP)
{
	while (levelupXP >= XPToLevelup)
	{
		levelupXP -= XPToLevelup;
		HP = maxHP += maxHPBonus;
		DMG += DMGBonus;
		ACD *= ACDBonus;
	}
}

void Hero::gainXP(float damagePoints)
{
	levelup(XP - int(XP / XPToLevelup) * XPToLevelup + damagePoints);
	XP += damagePoints;
}

void Hero::doHit(Character& victim)
{
	this->gainXP(victim.gotHit(this));
}

const unsigned int Hero::getLevel() const
{
	return int(XP / XPToLevelup) + 1;
}
