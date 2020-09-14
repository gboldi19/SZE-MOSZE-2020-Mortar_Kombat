#include "Character.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

	if (argc == 7)
    {
		Character player1 = Character(argv[1],atoi(argv[2]),atoi(argv[3]));
		Character player2 = Character(argv[4],atoi(argv[5]),atoi(argv[6]));

		int count = 0;
		while (player1.getHP() > 0 && player2.getHP() > 0)
        {
			cout << player1.getName() << ": HP: " << player1.getHP() << ", DMG: " << player1.getDMG() << endl;
			cout << player2.getName() << ": HP: " << player2.getHP() << ", DMG: " << player2.getDMG() << endl;

			if (count % 2)
            {
				cout << player2.getName() << " -> " << player1.getName() << endl;
				player1.setHP(player1.getHP() - player2.getDMG());
			}
            else
            {
				cout << player1.getName() << " -> " << player2.getName() << endl;
				player2.setHP(player2.getHP() - player1.getDMG());
			}
			count++;
		}

		cout << player1.getName() << ": HP: " << player1.getHP() << ", DMG: " << player1.getDMG() << endl;
		cout << player2.getName() << ": HP: " << player2.getHP() << ", DMG: " << player2.getDMG() << endl;

		if (player1.getHP() == 0)
        {
			cout << player1.getName() << " died. " << player2.getName() << " wins." << endl;
		}
        else
        {
            cout << player2.getName() << " died. " << player1.getName() << " wins." << endl;
            }
        }
    else
    {
		cout << "Incorrect number of arguments!" << endl;
	}

	return 0;
}
