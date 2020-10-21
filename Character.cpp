#include "Character.h"
#include <any>

Character::Character(const std::string characterName, float healthPoints, float damagePoints, float attackSpeed)
: name(characterName)
{
	HP = maxHP = healthPoints;
    DMG = damagePoints;
    AS = attackSpeed;
}

Character Character::parseUnit(std::string fileName)
{
    std::map<std::string, std::any> characterAttributes = JSONParser::parse(fileName, true);
    ruleOutNegativeAnyFloat(characterAttributes["hp"]);
    ruleOutNegativeAnyFloat(characterAttributes["dmg"]);
    ruleOutNegativeAnyFloat(characterAttributes["as"]);
	return Character(
        std::any_cast<std::string>(characterAttributes["name"]),
        std::any_cast<float>(characterAttributes["hp"]),
        std::any_cast<float>(characterAttributes["dmg"]),
        std::any_cast<float>(characterAttributes["as"]));
}

const std::string Character::getName() const
{
	return name;
}

const float Character::getHP() const
{
	return HP;
}

const float Character::getDMG() const
{
	return DMG;
}

const float Character::getAS() const
{
    return AS;
}


float Character::gotHit(Character* attacker)
{
	float potentialXP = attacker->getDMG();
	if (HP - potentialXP > 0)
	{
		HP -= potentialXP;
		return potentialXP;
	}
	else
	{
		potentialXP = HP;
		HP = 0;
		return potentialXP;
	}
}

void Character::doHit(Character& victim)
{
	victim.gotHit(this);
}

Character* Character::Fight(Character &player1, Character &player2)
{
    float ASTimer1 = 0, ASTimer2 = 0;

    while (player1.getHP() > 0 && player2.getHP() > 0)
    {
        if (ASTimer1 <= ASTimer2)
        {
            player2.doHit(player2);
            ASTimer1 += player1.getAS();
        }
        else
        {
            player1.doHit(player1);
            ASTimer2 += player2.getAS();
        }
    }

    if (player1.getHP() == 0) 
    {
        return &player2;
    }
    else
    {
        return &player1;
    }
}

void ruleOutNegativeAnyFloat(std::any& num)
{
    if (std::any_cast<float>(num) < 0)
    {
        throw std::runtime_error("Negative numeric value is not acceptable here!");
    }
}
