#ifndef JSONPARSER_H
#define JSONPARSER_H

#include "Character.h"
#include <map>
#include <string>
#include <any>
#include <fstream>
#include <streambuf>
#include <unordered_set>

namespace JSONParser
{
    //INSTRUCTIONS: Specify mode = "inclusive" for an allowed character set. Exclusive is default.
    std::string::size_type findNext(std::string &s, char target, std::unordered_set<char> set = {}, std::string mode = "");
    void checkString(std::string& s);
    std::any string2any(std::string& s);
    std::map<std::string, std::any> parseString(std::string& s);

    //INSTRUCTIONS: Provide parseble string (default) or text file path (isFile must be set true)!
    std::map<std::string, std::any> parse(std::string inputString = "", bool isFile = false);
    //INSTRUCTIONS: Provide parseble stream!
    std::map<std::string, std::any> parse(std::istream &stream);
};

#endif
