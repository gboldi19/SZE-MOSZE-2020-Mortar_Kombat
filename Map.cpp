#include "map.h"

Map::Map(std::string filename)
{
	std::ifstream file(filename);
	if (file.good())
	{
		std::vector<Map::type> row;
		std::string line;
		while (getline(file, line))
		{
			row.clear();
			for (char c : line)
			{
				if (c == '#') row.push_back(Map::type::Wall);
				else if (c == ' ') row.push_back(Map::type::Free);
			}
			structure.push_back(row);
		}
	}
	else
	{
		throw std::runtime_error("Unable to open map file!");
	}
}

long Map::getRowNum()
{
	return structure.size();
}

long Map::getRowSize(int rowNum)
{
	return structure[rowNum].size();
}

long Map::getMaxRowSize()
{
	long max = 0;
	for (std::vector<type> row : structure)
	{
		if (max < row.size()) max = row.size();
	}
	return max;
}

Map::type Map::get(int x, int y) const
{
	if (int(structure.size()) >= x)
	{
		if (int(structure[x].size()) >= y)
		{
			return structure[x][y];
		}
	}
	throw Map::WrongIndexException();
}
