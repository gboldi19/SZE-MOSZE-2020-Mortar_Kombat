#include "Character.h"
#include <iostream>

int main(const int argc, const char** argv) {

    if (argc == 7)
    {
        Character player1 = Character(argv[1], std::stoul(argv[2]), std::stoul(argv[3]));
        Character player2 = Character(argv[4], std::stoul(argv[5]), std::stoul(argv[6]));

        bool firstsTurn = true;
        while (player1.getHP() > 0 && player2.getHP() > 0)
        {
            if (firstsTurn)
            {
                player2.gotHit(player1.getDMG());
            }
            else
            {
                player1.gotHit(player2.getDMG());
            }
            firstsTurn = !firstsTurn;
        }
       if (player1.getHP() == 0)
		{
			std::cout << player2.getName() << " wins. Remaining HP: " << player2.getHP() << std::endl;
		}
		else
		{
			std::cout << player1.getName() << " wins. Remaining HP: " << player1.getHP() << std::endl;
		}
    else
    {
        std::cout << "Incorrect number of arguments!" << std::endl;
    }

    return 0;
}
