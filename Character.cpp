#include "Character.h"

Damage Damage::operator+=(int rhs)
{
	this->physical += rhs; this->magical += rhs;
	return *this;
}

Damage Damage::operator+=(const Damage& rhs)
{
	this->physical += rhs.physical; this->magical += rhs.magical;
	return *this;
}

Damage Damage::operator*=(int rhs)
{
	this->physical *= rhs; this->magical *= rhs;
	return *this;
}

Damage Damage::operator*=(const Damage& rhs)
{
	this->physical *= rhs.physical; this->magical *= rhs.magical;
	return *this;
}

Character::Character(const std::string& _name, float _maxHP, float _physicalDMG, float _magicalDMG, float _ACD, float _DEF)
: name(_name)
{
	HP = maxHP = _maxHP;
	DMG.physical = _physicalDMG;
	DMG.magical = _magicalDMG;
	ACD = _ACD;
	DEF = _DEF;
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

const float Character::getPhysicalDamage() const
{
	return DMG.physical;
}

const float Character::getMagicalDamage() const
{
	return DMG.magical;
}

const float Character::getAttackCoolDown() const
{
    return ACD;
}

const float Character::getDefense() const
{
	return DEF;
}

float Character::gotHit(Character* attacker)
{
	float potentialXP = (attacker->getPhysicalDamage() - DEF > 0) ? attacker->getPhysicalDamage() - DEF + attacker->getMagicalDamage() : attacker->getMagicalDamage();
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
			this->doHit(enemy);
			ACDTimer1 += ACD;
        }
        else
        {
			enemy.doHit(*this);
			ACDTimer2 += enemy.getAttackCoolDown();
        }
    }
}

float RONAF(const float& num)
{
	if (num < 0)
	{
		throw std::runtime_error("Negative numeric value is not acceptable here!");
	}
	return num;
}

