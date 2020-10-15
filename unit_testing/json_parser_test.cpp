#include "../JSONParser.h"

#include <gtest/gtest.h>


TEST(jsonParserTest, test_iostream)
{
    std::map<std::string, std::any> outputMap; 
    std::map<std::string, std::any> expectedMap{
        {"name"}, {"Kakarott"},
        {"hp"}, {380},
        {"dmg"}, {20}};                     
    std::ifstream jsonFile;
    jsonFile.open("./units/unit1.json");
    outputMap = JSONParser::parse(jsonFile);
    jsonFile.close();
    for (auto e : expectedMap)
    {
        ASSERT_EQ(outputMap[e.first],e.second);
    }
}

TEST(jsonParserTest, test_filename)
{
    std::map<std::string, std::any> outputMap; 
    std::map<std::string, std::any> expectedMap{
        {"name"}, {"Kakarott"},
        {"hp"}, {380},
        {"dmg"}, {20}};
    std::string fname = "./units/unit2.json";
    outputMap = JSONParser::parse(fname, true);
    for (auto e : expectedMap)
    {
        ASSERT_EQ(outputMap[e.first],e.second);
    }
}

TEST(jsonParserTest, test_string)
{
    std::map<std::string, std::any> outputMap; 
    std::map<std::string, std::any> expectedMap{
        {"name"}, {"Kakarott"},
        {"hp"}, {380},
        {"dmg"}, {20}};          
    std::string fname = "./units/unit3.json";
    std::ifstream jsonFile;
    jsonFile.open(fname);
    std::string line;
    std::string jsonToString = "";
    while(getline(jsonFile,line)) jsonToString += line;
    jsonFile.close();
    outputMap = JSONParser::parse(jsonFile);
    for (auto e : expectedMap)
    {
        ASSERT_EQ(outputMap[e.first],e.second);
    }
}

TEST(jsonParserTest, wrongJsonFile)
{
    const std::string expectedError = "Error in file: incorrect value.";
    const std::string fname = "unit_testing/missing_comma.json";
    std::ifstream jsonFile;
    jsonFile.open(fname);
    try
    {
        JSONParser::parse(jsonFile);
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