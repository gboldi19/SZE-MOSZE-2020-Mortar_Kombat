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
			Character character = Character::CharacterFromFile(argv[1]);
			Player player = Player::PlayerFromFile(argv[2]);

			bool firstPlayersTurn = true;
			while (character.getHP() > 0 && player.getHP() > 0)
			{
				if (firstPlayersTurn)
				{
				    character.doHit(player);
				}
				else
				{
				    player.doHit(character);
				}
				firstPlayersTurn = !firstPlayersTurn;
			}

			if (character.getHP() == 0)
			{
				std::cout << player.getName() << " wins. Remaining HP: " << player.getHP() << std::endl;
			}
			else
			{
				std::cout << character.getName() << " wins. Remaining HP: " << character.getHP() << std::endl;
			}
			return 0;
		}
		catch (const std::exception& e)
		{
			std::cerr << "Error, exiting with: " << e.what() << std::endl;
			return 1;
		}
	}
}
