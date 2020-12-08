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
	std::wstring output = L"";
	unsigned long maxRowSize = field.getMaxRowSize();
	//top border
	output += L'\u2554'; //top left corner
	output += std::wstring(maxRowSize * 2 - 2, L'\u2550'); //horizontal line
	output += L'\u2557'; //top right corner
	output += '\n';

	unsigned int monsterNum, heroNum;
	for (unsigned long i = 0; i < field.getRowNum(); i++)
	{
		//left wall
		output += L'\u2551'; //vertical corner
		unsigned long j = 0;
		for (; j < field.getRowSize(i); j++)
		{
			//wall
			if (field.get(i, j) == Map::Wall) output += (L'\u2588' + L'\u2588'); //wall
			//free or unit
			else
			{
				heroNum = 0;
				for (characterUnit hero : heroUnits)
				{
					if (hero.posx == j && hero.posy == i) heroNum++;
				}
				monsterNum = 0;
				for (characterUnit monster : monsterUnits)
				{
					if (monster.posx == j && monster.posy == i) monsterNum++;
				}
				if (heroNum > 0) output += L'\u2523' + L'\u252B'; //H character
				else if (monsterNum == 1) output += ('M' + L'\u2591'); //M + free
				else if (monsterNum > 1) output += ('M' + 'M'); //M characters
				else output += (L'\u2591' + L'\u2591'); //free
			}
		}
		//rest of the row
		for (; j < maxRowSize; j++) output += (L'\u2591' + L'\u2591'); //wall
		//right border
		output += L'\u2551'; //vertical line
		output += '\n';
	}

	//bottom border
	output += L'\u255A'; //bottom left corner
	output += std::wstring(maxRowSize * 2 - 2, L'\u2550'); //horizontal line
	output += L'\u255D'; //bottom right corner

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
	for (characterUnit monsterUnit : monsterUnits)
	{
		if (monsterUnit.posx == heroUnits[0].posx && monsterUnit.posy == heroUnits[0].posy)
		{
			heroUnits[0].character.fightTilDeath(monsterUnit.character);
			if (!monsterUnit.character.isAlive()) monsterUnits.pop_front(); //may require iterator instead of pop_front() !!!!!!!!!!!!!!!!!!!!!!!!!
		}
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
		fightOnPos();
	} while (monsterUnits.size() > 0 && heroUnits.size() > 0);
}
