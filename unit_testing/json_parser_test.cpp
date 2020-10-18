#include "../JSONParser.h"
#include <gtest/gtest.h>
#include <map>
#include <string>
#include <fstream>
#include <any>

TEST(jsonParserTest, parsetest)
{
	ASSERT_THROW(JSONParser::parse("none.json", true), std::runtime_error);
    ASSERT_NO_THROW(JSONParser::parse("../units/unit1.json", true));
}

TEST(jsonParserTest, valcheck)
{
	std::map<std::string, std::any> template_inp = JSONParser::parse("{\"string\":\"Stringtype\",\"int\":4,\"float\":1.6}");
	ASSERT_EQ(std::any_cast<std::string>(template_inp["string"]), "Stringtype");
    ASSERT_EQ(std::any_cast<float>(template_inp["int"]), 4);
    ASSERT_EQ(std::any_cast<float>(template_inp["float"]), 1.6f);
}

TEST(jsonParserTest, filetest)
{
	std::ifstream jsonFile;
    jsonFile.open("../unit_testing/missing_comma.json");
	jsonFile.close();
	ASSERT_THROW(JSONParser::parse(jsonFile), std::runtime_error);
}

TEST(jsonParserTest, stringtest)
{
	std::map<std::string, std::any> template_string = JSONParser::parse("{\"name\":\"Kakarott\",\"hp\":380,\"dmg\":20}");
	ASSERT_EQ(std::any_cast<std::string>(template_string["name"]), "Kakarott");
    ASSERT_EQ(std::any_cast<float>(template_string["hp"]), 380);
    ASSERT_EQ(std::any_cast<float>(template_string["dmg"]), 20);
}

TEST(jsonParserTest, missingfile)
{
	std::string not_exists = "../../tobe_or_nottobe_unit_test.json";
	ASSERT_THROW(JSONParser::parse(not_exists, true), std::runtime_error);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}