#include "Character.h"
#include <iostream>

int main(int argc, char** argv) {

    if (argc == 7)
    {
        Character player1 = Character(argv[1],std::atoi(argv[2]),std::atoi(argv[3]));
        Character player2 = Character(argv[4],std::atoi(argv[5]),std::atoi(argv[6]));

        int count = 0;
        while (player1.getHP() > 0 && player2.getHP() > 0)
        {
            std::cout << player1.getName() << ": HP: " << player1.getHP() << ", DMG: " << player1.getDMG() << std::endl;
            std::cout << player2.getName() << ": HP: " << player2.getHP() << ", DMG: " << player2.getDMG() << std::endl;

            if (count % 2)
            {
                std::cout << player2.getName() << " -> " << player1.getName() << std::endl;
                player1.setHP(player1.getHP() - player2.getDMG());
            }
            else
            {
                std::cout << player1.getName() << " -> " << player2.getName() << std::endl;
                player2.setHP(player2.getHP() - player1.getDMG());
            }
            count++;
        }

        std::cout << player1.getName() << ": HP: " << player1.getHP() << ", DMG: " << player1.getDMG() << std::endl;
        std::cout << player2.getName() << ": HP: " << player2.getHP() << ", DMG: " << player2.getDMG() << std::endl;

        if (player1.getHP() == 0)
        {
            std::cout << player1.getName() << " died. " << player2.getName() << " wins." << std::endl;
        }
        else
        {
            std::cout << player2.getName() << " died. " << player1.getName() << " wins." << std::endl;
            }
        }
    else
    {
        std::cout << "Incorrect number of arguments!" << std::endl;
    }

    return 0;
}
