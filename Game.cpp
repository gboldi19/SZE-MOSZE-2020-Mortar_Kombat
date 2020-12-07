#include "Game.h"

void Game::setMap(Map map)
{
	if (heroUnits.size() + monsterUnits.size() > 0) throw Game::AlreadyHasUnitsException();
	field = map;
}

void Game::putHero(Hero hero, int x, int y)
{
	if (heroUnits.size() > 0) throw Game::AlreadyHasHeroException();
	if (field.get(x, y) == Map::type::Wall) throw Game::OccupiedException();
	heroUnits.push_back(characterUnit(hero, x, y));
}

void Game::putMonster(Monster monster, int x, int y)
{
	if (field.get(x, y) == Map::type::Wall) throw Game::OccupiedException();
	monsterUnits.push_back(characterUnit(monster, x, y));
}

void Game::displayField()
{
	wchar_t* output = L"";
	long maxRowSize = field.getMaxRowSize();
	//top border
	wcscat(output, L"\u2554"); //╔
	output += std::string(maxRowSize * 2 - 2, '═');
	output += '╗';
	output += '\n';

	unsigned int monsterNum, heroNum;
	for (long i = 0; i < field.getRowNum(); i++)
	{
		//left wall
		output += '║';
		long j = 0;
		for (; j < field.getRowSize(i); j++)
		{
			//wall
			if (field.get(i, j) == Map::Wall) output += "██";
			//free or unit
			else
			{
				heroNum = 0;
				for (characterUnit hero : heroUnits)
				{
					if (hero.posx = j && hero.posy == i) heroNum++;
				}
				monsterNum = 0;
				for (characterUnit monster : monsterUnits)
				{
					if (monster.posx = j && monster.posy == i) monsterNum++;
				}
				if (heroNum > 0) output += "┣┫";
				else if (monsterNum == 1) output += "M░";
				else if (monsterNum > 1) output += "MM";
				else output += "░░";
			}
		}
		//rest of the row
		for (; j < maxRowSize; j++) output += "░░";
		//right border
		output += '║';
		output += '\n';
	}

	//bottom border
	output += '╚';
	output += std::string(maxRowSize * 2 - 2, '═');
	output += '╝';

}

void Game::moveHero(std::string input)
{
	if (input == "north" && field.get(heroUnits[0].posx, heroUnits[0].posy - 1) == Map::type::Free)
	{
		heroUnits[0].posy -= 1;
	}
	else if (input == "south" && field.get(heroUnits[0].posx, heroUnits[0].posy + 1) == Map::type::Free)
	{
		heroUnits[0].posy += 1;
	}
	else if (input == "south" && field.get(heroUnits[0].posx + 1, heroUnits[0].posy) == Map::type::Free)
	{
		heroUnits[0].posx += 1;
	}
	else if (input == "west" && field.get(heroUnits[0].posx - 1, heroUnits[0].posy) == Map::type::Free)
	{
		heroUnits[0].posx -= 1;
	}
}

void Game::fightOnPos()
{
	int i = 0;
	for (characterUnit monsterUnit : monsterUnits)
	{
		if (monsterUnit.posx == heroUnits[0].posx && monsterUnit.posy == heroUnits[0].posy)
		{
			heroUnits[0].character.fightTilDeath(monsterUnit.character);
			if (!monsterUnit.character.isAlive()) monsterUnits.erase(monsterUnits.begin() + i);
		}
		i++;
	}
}

void Game::run()
{
	if (!field.mapExists() || heroUnits.size() == 0) throw Game::NotInitializedException();
	std::string input = "";
	do
	{
		displayField();
		std::cin >> input;
		moveHero(input);
		//fightOnPos();
	} while (monsterUnits.size() > 0 && heroUnits.size() > 0);
	std::cout << "the end" << std::endl; //testline !!!!!!!!!!!!!!!!!!!!!!!!!!!
}
