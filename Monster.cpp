#include "Monster.h"

Monster::Monster(const std::string _name, float _HP, float _physicalDMG, float _magicalDMG, float _ACD, float _DEF)
	: Character(_name, _HP, _physicalDMG, _magicalDMG, _ACD, _DEF) {}

Monster Monster::parse(std::string fileName)
{
	JSON characterAttributes = JSON::parseFromFile(fileName);
	float physicalDamage = (characterAttributes.count("damage") == 0) ? 0 : RONAF(characterAttributes.get<float>("damage"));
	float magicalDamage = (characterAttributes.count("magical-damage") == 0) ? 0 : RONAF(characterAttributes.get<float>("magical-damage"));
	float defense = (characterAttributes.count("defense") == 0) ? 0 : RONAF(characterAttributes.get<float>("defense"));
	return Monster(
		characterAttributes.get<std::string>("name"),
		RONAF(characterAttributes.get<float>("health_points")),
		physicalDamage,
		magicalDamage,
		RONAF(characterAttributes.get<float>("attack_cooldown")),
		defense);
}
