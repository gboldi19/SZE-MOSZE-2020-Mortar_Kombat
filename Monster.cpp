#include "Monster.h"

Monster::Monster(const std::string characterName, float healthPoints, float damagePoints, float attackCoolDown)
	: Character(characterName, healthPoints, damagePoints, attackCoolDown) {}

Monster Monster::parse(std::string fileName)
{
	std::map<std::string, std::any> characterAttributes = JSON::parse(fileName, true);
	JSON::ruleOutNegativeAnyFloat(characterAttributes["health_points"]);
	JSON::ruleOutNegativeAnyFloat(characterAttributes["damage"]);
	JSON::ruleOutNegativeAnyFloat(characterAttributes["attack_cooldown"]);
	return Monster(
		std::any_cast<std::string>(characterAttributes["name"]),
		std::any_cast<float>(characterAttributes["health_points"]),
		std::any_cast<float>(characterAttributes["damage"]),
		std::any_cast<float>(characterAttributes["attack_cooldown"]));
}
