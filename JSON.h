#ifndef JSON_H
#define JSON_H

#include <map>
#include <string>
#include <fstream>
#include <streambuf>
#include <unordered_set>
#include <variant>
#include <vector>

class JSON
{
public:
    typedef std::vector<std::variant<std::string, float, bool, std::nullptr_t>> list;
    typedef std::variant<std::string, list, float, bool, std::nullptr_t> var;
private:
	std::map<std::string, var> map;
	JSON(std::map<std::string, var> _map) : map(_map) {}
public:
    /**
	* @brief String or file parse.
	* @param String to parse or path to file.
    * @param Bool indicating whether or not the string is a path to file.
	* @return Map containing the keys and their values.
    * INSTRUCTIONS: Provide parseble string (default) or text file path (isFile must be set true)!
	*/
    static std::map<std::string, var> parse(std::string inputString = "", bool isFile = false);
    /**
	* @brief Stream parse.
	* @param Stream to parse.
	* @return Map containing the keys and their values.
	*/
    static std::map<std::string, var> parse(std::istream &stream);
    /**
	* @brief File parse to own map.
	* @param Path to file.
	* @return JSON with defined map.
	*/
	static JSON parseFromFile(std::string fileName);
    /**
	* @brief Key counter in own map.
	* @param Key to count.
	* @return Number of occurrences.
	*/
	const int count(const std::string &key) const { return map.count(key); }
    /**
	* @brief Getter for own map.
    * @tparam Format to return in.
	* @param Key of the value to return.
	* @return Value of the provided key.
	*/

	template <typename T>
		T get(const std::string &key) { return std::get<T>(map[key]); }

	class ParseException : public std::exception {}; ///< Class member for exception handling.
};

#endif
