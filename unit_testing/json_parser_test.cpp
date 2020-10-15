#include "JSONParser.h"

#include <gtest/gtest.h>

std::map<std::string, std::any> expectedMap;
expectedMap.insert(std::pair<std::string, std::any> ("name", "Kakarott"));
expectedMap.insert(std::pair<std::string, std::any> ("hp", 380));
expectedMap.insert(std::pair<std::string, std::any> ("dmg", 20));

TEST(jsonParserTest, iostream)
{    
    std::ifstream jsonFile;
    jsonFile.open("units/unit1.json");
    std::map<std::string, std::any> outputMap = JSONParser::parse(jsonFile);
    jsonFile.close();
    for (auto i : expectedMap)
    {
        ASSERT_EQ(outputMap[i.first], i.second);
    }
}

TEST(jsonParserTest, filename)
{   
    outputMap = JSONParser::parse("units/unit1.json", true);
    for (auto i : expectedMap)
    {
        ASSERT_EQ(outputMap[i.first], i.second);
    }
}

TEST(jsonParserTest, string)
{
    std::ifstream jsonFile;
    jsonFile.open("units/unit1.json");
    std::string line;
    std::string jsonString = "";
    while (getline(jsonFile,line)) jsonString += line;
    jsonFile.close();
    outputMap = JSONParser::parse(jsonString);
    for (auto e : expectedMap)
    {
        ASSERT_EQ(outputMap[e.first],e.second);
    }
}

TEST(jsonParserTest, bad_json)
{
    const std::string expectedError = "Incorrect value in file!";
    std::ifstream jsonFile;
    jsonFile.open("unit_testing/missing_comma.json");
    try
    {
        JSONParser::parse(jsonFile);
        jsonFile.close();
    }
    catch(std::string e)
    {
        ASSERT_EQ(e, expectedError);
    }
    
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}