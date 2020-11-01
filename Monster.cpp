#include "Monster.h"

Monster::Monster(const std::string characterName, float healthPoints, float damagePoints, float attackCoolDown)
	: Character(characterName, healthPoints, damagePoints, attackCoolDown) {}

Monster Monster::parse(std::string fileName)
{
	std::map<std::string, std::any> characterAttributes = JSON::parse(fileName, true);
	ruleOutNegativeAnyFloat(characterAttributes["hp"]);
	ruleOutNegativeAnyFloat(characterAttributes["dmg"]);
	ruleOutNegativeAnyFloat(characterAttributes["as"]);
	return Monster(
		std::any_cast<std::string>(characterAttributes["name"]),
		std::any_cast<float>(characterAttributes["hp"]),
		std::any_cast<float>(characterAttributes["dmg"]),
		std::any_cast<float>(characterAttributes["as"]));
}
