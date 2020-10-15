#include "Character.h"

Character::Character(const std::string characterName, const unsigned int healthPoints, const unsigned int damagePoints, const double attackSpeed) : name(characterName), DMG(damagePoints), AS(attackSpeed)
{
	HP = healthPoints;
}

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
        line.resize(line.length() - 1); //',' chopped off
		characterAttributes[2] = line;

        file.ignore(9); //first column skipped
		std::getline(file, line);
        characterAttributes[3]=line;


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
