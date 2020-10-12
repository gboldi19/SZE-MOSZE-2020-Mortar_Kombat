#include "Character.h"

std::string* Character::parseUnit(const std::string &fileName)
{
	std::ifstream file(fileName);
	if (file.good())
	{
		static std::string characterAttributes[3];
		std::string line;

		file.ignore(14); //starting line and first column skipped
		std::getline(file, line);
		line.resize(line.length() - 2); //'"' and ',' chopped off
		characterAttributes[0] = line;

		file.ignore(9); //first column skipped
		std::getline(file, line);
		line.resize(line.length() - 1); //',' chopped off
		characterAttributes[1] = line;

		file.ignore(10); //first column skipped
		std::getline(file, line);
		characterAttributes[2] = line;

		return characterAttributes;
	}
	else
	{
		throw std::runtime_error("File not found!");
		return NULL;
	}
}

Character::Character(const std::string* characterAttributes)
	: name(characterAttributes[0]), DMG(stof(characterAttributes[2]))
{
	HP = maxHP = stof(characterAttributes[1]);
}

Character Character::CharacterFromFile(const std::string &fileName)
{
	return Character(parseUnit(fileName));
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
