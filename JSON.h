#ifndef JSON_H
#define JSON_H

#include <map>
#include <string>
#include <any>
#include <fstream>
#include <streambuf>
#include <unordered_set>

class JSON
{
public:
	std::map<std::string, std::any> map;
	JSON(std::map<std::string, std::any> _map) : map(_map) {}

    //INSTRUCTIONS: Provide parseble string (default) or text file path (isFile must be set true)!
    static std::map<std::string, std::any> parse(std::string inputString = "", bool isFile = false);
    //INSTRUCTIONS: Provide parseble stream!
    static std::map<std::string, std::any> parse(std::istream &stream);
	static JSON parseFromFile(std::string fileName);

	const int count(const std::string &key) const { return map.count(key); }
	template <typename T>
		T get(const std::string &key) { return std::any_cast<T>(map[key]); }

	class ParseException : public std::exception {};
};

#endif
