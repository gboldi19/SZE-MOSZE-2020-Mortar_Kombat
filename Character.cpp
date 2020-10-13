#include "Character.h"

Character::Character(const std::string characterName, const unsigned int healthPoints, const unsigned int damagePoints, const double attackSpeed) : name(characterName), DMG(damagePoints), AS(attackSpeed)
{
	HP = healthPoints;
}

Character Character::parseUnit(std::string fileName)
{
	std::ifstream file(fileName);
	if (file.good())
	{
		std::string characterAttributes[4];
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
        line.resize(line.length() - 1); //',' chopped off
		characterAttributes[2] = line;

        file.ignore(9); //first column skipped
		std::getline(file, line);
        characterAttributes[3]=line;

		return Character(characterAttributes[0], stoul(characterAttributes[1]), stoul(characterAttributes[2]), stoul(characterAttributes[3]));
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

const float Character::getAS() const
{
    return AS;
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

Character* Character::Fight (Character &player1, Character &player2)
{
    float ASTimer1 = 0;
    float ASTimer2 = 0;

    while (player1.getHP() > 0 && player2.getHP() > 0)
    {
        if (ASTimer1 <= ASTimer2)
        {
            player2.gotHit(player1);
            ASTimer1 += player1.getAS();
        }
        else
        {
            player1.gotHit(player2);
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
