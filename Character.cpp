#include "Character.h"

Character::Character(const std::string characterName, const unsigned int healthPoints, const unsigned int damagePoints)
{
    name = characterName;
	HP = healthPoints;
	DMG = damagePoints;
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

void Character::gotHit(const unsigned int damagePoints)
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
