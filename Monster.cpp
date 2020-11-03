#include "Monster.h"

Monster::Monster(const std::string characterName, float healthPoints, float damagePoints, float attackCoolDown)
	: Character(characterName, healthPoints, damagePoints, attackCoolDown) {}

Monster Monster::parse(std::string fileName)
{
	JSON characterAttributes = JSON::parseFromFile(fileName);
	return Monster(
		characterAttributes.get<std::string>("name"),
		JSON::RONAF(characterAttributes.get<float>("health_points")),
		JSON::RONAF(characterAttributes.get<float>("damage")),
		JSON::RONAF(characterAttributes.get<float>("attack_cooldown")));
}
