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
	long getRowNum();
	long getRowSize(int rowNum);
	long getMaxRowSize();
	type get(int x, int y) const;
	class WrongIndexException : public std::exception {};
	bool mapExists() { return structure.size() > 0; }
};

#endif
