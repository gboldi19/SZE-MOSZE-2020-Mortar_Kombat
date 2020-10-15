#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <map>
#include <string>
#include <any>
#include <fstream>
#include <streambuf>
#include <unordered_set>

namespace JSONParser
{
    //INSTRUCTIONS: Specify mode = "inclusive" for an allowed character set. Exclusive is default.
    static std::string::size_type findNext(std::string &s, char target, std::unordered_set<char> set = {}, std::string mode = "");
    static void checkString(std::string& s);
    static std::any string2any(std::string& s);
    static std::map<std::string, std::any> parseString(std::string& s);

    //INSTRUCTIONS: Provide parseble string (default) or text file path (isFile must be set true)!
    static std::map<std::string, std::any> parse(std::string inputString = "", bool isFile = false);
    //INSTRUCTIONS: Provide parseble stream!
    static std::map<std::string, std::any> parse(std::istream &stream);
};

#endif
