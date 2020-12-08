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
	Map() {};
	Map(std::string filename);
	unsigned long getRowNum();
	unsigned long getRowSize(int rowNum);
	unsigned long getMaxRowSize();
	type get(int x, int y) const;
	class WrongIndexException : public std::exception {};
	bool mapExists() { return structure.size() > 0; }
};

#endif
