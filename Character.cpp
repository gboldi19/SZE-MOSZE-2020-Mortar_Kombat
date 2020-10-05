#include "Character.h"

Character::Character(const std::string characterName, const unsigned int healthPoints, const unsigned int damagePoints) : name(characterName), DMG(damagePoints)
{
	HP = healthPoints;
}

Character Character::parseUnit(std::string fileName)
{
	std::ifstream file(fileName);
	if (file.good())
	{
		std::string characterAttributes[3];
		std::string line;

		file.ignore(14); //starting line and first column skipped
		std::getline(file, line);
		line.resize(line.length() - 2); //'"' and ',' chopped off
		characterAttributes[0] = line;

		file.ignore(9); //first column skipped
		std::getline(file, line);
		line.resize(line.length() - 1); //',' chopped off
		characterAttributes[1] = line;

		file.ignore(9); //first column skipped
		std::getline(file, line);
		characterAttributes[2] = line;

		return Character(characterAttributes[0], stoul(characterAttributes[1]), stoul(characterAttributes[2]));
	}
	else
	{
		throw std::runtime_error("File not found!");
	}
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

void Character::gotHit(const &Character attacker)
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
