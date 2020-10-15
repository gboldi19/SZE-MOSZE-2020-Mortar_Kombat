/**
 * @file main.cpp
 *
 *
 * @author Mortar_Kombat
 *  
 *  - Geiger Boldizsár
 *  - Rakonczai Róbert
 *  - Tóth Balázs
 *
 * @brief This file contains the main function.
 *
 * 
*/

#include "Character.h"
#include "Player.h"
#include <iostream>

int main(const int argc, const char* argv[])
{
	if (argc != 3)
    {
        std::cerr << "Error, exiting with: " << "Incorrect number of arguments!" << std::endl;
        return 1;
    }
    else
    {
        try
        {
            Character player1 = Character::parseUnit(argv[1]);
            Character player2 = Character::parseUnit(argv[2]);

            Character* winner = Character::Fight(player1, player2);

            std::cout << winner->getName() << " wins. Remaining HP: " << winner->getHP() << std::endl;
            return 0;
        }
        catch (const std::exception& e)
	    {
            std::cerr << "Error, exiting with: " << e.what() << std::endl;
            return 1;
	    }
    }

}
