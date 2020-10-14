#include "Character.h"

Character::Character(const std::string characterName, const unsigned int healthPoints, const unsigned int damagePoints)
    : name(characterName), DMG(damagePoints)
{
	HP = healthPoints;
}

void ruleOutNegativeAnyFloat(std::any& num)
{
    if (std::any_cast<float>(num) < 0)
    {
        throw std::runtime_error("Negative numeric value is not acceptable here!");
    }
}

Character Character::parseUnit(std::string fileName)
{
    std::map<std::string, std::any> characterAttributes = JSONParser::parse(fileName, true);
    ruleOutNegativeAnyFloat(characterAttributes["hp"]);
    ruleOutNegativeAnyFloat(characterAttributes["dmg"]);
	return Character(
        std::any_cast<std::string>(characterAttributes["name"]),
        static_cast<unsigned int>(std::any_cast<float>(characterAttributes["hp"])),
        static_cast<unsigned int>(std::any_cast<float>(characterAttributes["dmg"])));
}

const std::string Character::getName() const
{
	return name;
}

const unsigned int Character::getHP() const
{
	return HP;
}

const unsigned int Character::getDMG() const
{
	return DMG;
}

void Character::gotHit(const Character &attacker)
{
	if (int(HP - attacker.getDMG()) > 0)
	{
		HP = HP - attacker.getDMG();
	}
	else
	{
		HP = 0;
	}
}
