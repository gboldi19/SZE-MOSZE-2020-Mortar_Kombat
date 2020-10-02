#include "Character.h"

Character::Character(const std::string characterName, const float healthPoints, const float damagePoints) : name(characterName), DMG(damagePoints)
{
	HP = healthPoints;
}

Character Character::parseUnit(std::string fileName)
{
	std::ifstream sourceFile(fileName);
	if (sourceFile.good())
	{
        std::ifstream file(fileName);
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

        return Character(characterAttributes[0], stof(characterAttributes[1]), stof(characterAttributes[2]));
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

const float Character::getHP() const
{
	return HP;
}

const float Character::getDMG() const
{
	return DMG;
}

void Character::gotHit(const float damagePoints)
{
    if (float(HP - damagePoints) > 0)
    {
        HP = HP - damagePoints;
    }
    else
    {
        HP = 0;
    }
}
