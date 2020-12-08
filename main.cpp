/**
 * @file main.cpp
*/

#include <iostream>
#include <map>
#include <string>
#include <filesystem>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <list>

#include "JSON.h"
#include "Hero.h"
#include "Monster.h"
#include "Game.h"

const std::map<int,std::string> error_messages = {
    { 1 , "Bad number of arguments. Only a single scenario file should be provided." },
    { 2 , "The provided scenario file is not accessible." },
    { 3 , "The provided scenario file is invalid." },
    { 4 , "JSON parsing error." }
};

void bad_exit(int exitcode){ ///< function to write error messages
    std::cerr 
        << (error_messages.count(exitcode) ? error_messages.at(exitcode) : "Unknown error")
        << std::endl;
    exit(exitcode);
}

/**
 * @brief Initializes a Hero and some Monster objects.
 * @brief Hero fights the monsters one by one until death.
 * @arg scenario file path
 * Prints to screen.
*/
int main(int argc, char** argv){
    if (argc != 2) bad_exit(1);
    if (!std::filesystem::exists(argv[1])) bad_exit(2);

    std::string hero_file;
    std::list<std::string> monster_files;
    try {
        JSON scenario = JSON::parseFromFile(argv[1]); 
        if (!(scenario.count("hero")&&scenario.count("monsters"))) bad_exit(3);
        else {
            hero_file=scenario.get<std::string>("hero");
            std::istringstream monsters(scenario.get<std::string>("monsters"));
            std::copy(std::istream_iterator<std::string>(monsters),
                std::istream_iterator<std::string>(),
                std::back_inserter(monster_files));
        }
    } catch (const JSON::ParseException& e) {bad_exit(4);}

    try { 
        Hero hero{Hero::parse(hero_file)};
        std::list<Monster> monsters;
        for (const auto& monster_file : monster_files)
            monsters.push_back(Monster::parse(monster_file));        
        
        Game game = Game("maps/map1.csv");
        game.putHero(hero, 2, 5);
        for (const auto& monster : monsters) 
        {
            game.putMonster(monster, 3,5);
        }
        game.run();
        std::cout << (hero.isAlive() ? "The hero won." : "The hero died.") << std::endl;
    } catch (const JSON::ParseException& e) {bad_exit(4);}
    return 0;
}
