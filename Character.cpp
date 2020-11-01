#include "Character.h"

void ruleOutNegativeAnyFloat(std::any& num)
{
	if (std::any_cast<float>(num) < 0)
	{
		throw std::runtime_error("Negative numeric value is not acceptable here!");
	}
}


Character::Character(const std::string characterName, float healthPoints, float damagePoints, float attackCoolDown)
: name(characterName)
{
	HP = maxHP = healthPoints;
	DMG = damagePoints;
	ACD = attackCoolDown;
}

Character Character::parse(std::string fileName)
{
	std::map<std::string, std::any> characterAttributes = JSON::parse(fileName, true);
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

const float Character::getHealthPoints() const
{
	return HP;
}

const float Character::getMaxHealthPoints() const
{
	return maxHP;
}

const float Character::getDamage() const
{
	return DMG;
}

const float Character::getAttackCoolDown() const
{
    return ACD;
}


float Character::gotHit(Character* attacker)
{
	float potentialXP = attacker->getDamage();
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

bool Character::isAlive()
{
	return HP > 0;
}

void Character::fightTilDeath(Character &enemy)
{
    float ACDTimer1 = 0, ACDTimer2 = 0;

    while (enemy.getHealthPoints() > 0 && HP > 0)
    {
        if (ACDTimer1 <= ACDTimer2)
        {
			enemy.doHit(*this);
            ACDTimer1 += enemy.getAttackCoolDown();
        }
        else
        {
			this->doHit(enemy);
            ACDTimer2 += ACD;
        }
    }
}
