#include "Character.h"
#include <iostream>

int main(const int argc, const char* argv[])
{
	try
	{
		if (argc == 3)
		{
			Character player1 = Character::parseUnit(argv[1]);
			Character player2 = Character::parseUnit(argv[2]);

			bool firstPlayersTurn = true;
			while (player1.getHP() > 0 && player2.getHP() > 0)
			{
				if (firstPlayersTurn)
				{
					player2.gotHit(&player1);
				}
				else
				{
					player1.gotHit(&player2);
				}
				firstPlayersTurn = !firstPlayersTurn;
			}


			if (player1.getHP() == 0)
			{
				std::cout << player2.getName() << " wins. Remaining HP: " << player2.getHP() << std::endl;
			}
			else
			{
				std::cout << player1.getName() << " wins. Remaining HP: " << player1.getHP() << std::endl;
			}
		}
		else
		{
			throw std::runtime_error("Incorrect number of arguments!");
		}
		return 0;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error, exiting with: " << e.what() << std::endl;
		return 1;
	}
}
