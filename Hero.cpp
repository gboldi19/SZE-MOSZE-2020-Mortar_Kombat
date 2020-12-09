#include "Hero.h"

Hero::Hero(
		const std::string _name,
		float _maxHP,
		float _physicalDMG,
		float _magicalDMG,
		float _ACD,
		float _DEF,
		float _XPToLevelup,
		float _maxHPBonus,
		float _DMGBonus,
		float _ACDBonus,
		float _DEFBonus)
	: Character(_name, _maxHP, _physicalDMG, _magicalDMG, _ACD, _DEF)
{
	XP = 0;
	maxHPBonus = _maxHPBonus;
	DMGBonus = _DMGBonus;
	ACDBonus = _ACDBonus;
	XPToLevelup = _XPToLevelup;
	DEFBonus = _DEFBonus;
}

Hero Hero::parse(std::string fileName)
{
	JSON characterAttributes = JSON::parseFromFile(fileName);
	float physicalDamage = (characterAttributes.count("damage") == 0) ? 0 : RONAF(characterAttributes.get<float>("damage"));
	float magicalDamage = (characterAttributes.count("magical-damage") == 0) ? 0 : RONAF(characterAttributes.get<float>("magical-damage"));
	return Hero(
		characterAttributes.get<std::string>("name"),
		RONAF(characterAttributes.get<float>("base_health_points")),
		physicalDamage,
		magicalDamage,
		RONAF(characterAttributes.get<float>("base_attack_cooldown")),
		RONAF(characterAttributes.get<float>("defense")),
		RONAF(characterAttributes.get<float>("experience_per_level")),
		RONAF(characterAttributes.get<float>("health_point_bonus_per_level")),
		RONAF(characterAttributes.get<float>("damage_bonus_per_level")),
		RONAF(characterAttributes.get<float>("cooldown_multiplier_per_level")),
		RONAF(characterAttributes.get<float>("defense_bonus_per_level")));
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
