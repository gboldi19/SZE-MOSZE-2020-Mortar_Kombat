#include "Character.h"

Character::Character(string characterName, int healthPoints, int damagePoints)
{
    name = characterName;
	HP = healthPoints;
	DMG = damagePoints;
}

string Character::getName()
{
	return name;
}

int Character::getHP()
{
	return HP;
}

int Character::getDMG()
{
	return DMG;
}

void Character::gotHit(int damagePoints)
{
    if (int(HP - damagePoints) > 0)
    {
        HP = HP - damagePoints;
    }
    else
    {
        HP = 0;
    }
}
