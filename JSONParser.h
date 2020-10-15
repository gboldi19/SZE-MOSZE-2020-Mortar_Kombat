#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <map>
#include <string>
#include <any>
#include <fstream>
#include <streambuf>
#include <unordered_set>

class JSONParser
{
public:
    //INSTRUCTIONS: Provide parseble string (default) or text file path (isFile must be set true)!
    static std::map<std::string, std::any> parse(std::string inputString = "", bool isFile = false);
    //INSTRUCTIONS: Provide parseble stream!
    static std::map<std::string, std::any> parse(std::istream &stream);
};

#endif
