#include "Monster.h"

Monster::Monster(const std::string _name, float _HP, float _physicalDMG, float _magicalDMG, float _ACD)
	: Character(_name, _HP, _physicalDMG, _magicalDMG, _ACD) {}

Monster Monster::parse(std::string fileName)
{
	JSON characterAttributes = JSON::parseFromFile(fileName);
	return Monster(
		characterAttributes.get<std::string>("name"),
		RONAF(characterAttributes.get<float>("health_points")),
		RONAF(characterAttributes.get<float>("physical_damage")),
		RONAF(characterAttributes.get<float>("magical_damage")),
		RONAF(characterAttributes.get<float>("attack_cooldown")));
}
