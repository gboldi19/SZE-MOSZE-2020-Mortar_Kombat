#include "Character.h"

Character::Character(string characterName, int healthPoints, int damagePoints)
{
	setName(characterName);
	setHP(healthPoints);
	setDMG(damagePoints);
}

void Character::setName(string characterName)
{
	name = characterName;
}

string Character::getName()
{
	return name;
}

void Character::setHP(int healthPoints)
{
    if (healthPoints > 0)
    {
        HP = healthPoints;
    }
    else
    {
        HP = 0;
    }
}

void Character::setDMG(int damagePoints)
{
	DMG = damagePoints;
}

int Character::getHP()
{
	return HP;
}

int Character::getDMG()
{
	return DMG;
}
