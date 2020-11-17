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

Map::type Map::get(int x, int y) const
{
	if (structure.size() >= x)
	{
		if (structure[x].size() >= y)
		{
			return structure[x][y];
		}
	}
	throw std::runtime_error("Out of range!");
	//will be Map::WrongIndexException later
}
