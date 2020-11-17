#ifndef MAP_H
#define MAP_H

#include <fstream>
#include <vector>
#include <string>

class Map
{
public:
	enum type { Wall = '#', Free = ' ' };
private:
	std::vector<std::vector<type>> structure;
public:
	Map(std::string filename);
	type get(int x, int y) const;
};

#endif
