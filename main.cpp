#include "Character.h"
#include "Words.h"
#include <iostream>

using namespace std;

int main() {
	string inputString;
	getline(cin, inputString);
	Words inputVector = Words(inputString);

	if (inputVector.getWord(0) == "./a.out")
    {
		Character player1 = Character(
			inputVector.getWord(1),
			stoi(inputVector.getWord(2)),
			stoi(inputVector.getWord(3)));
		Character player2 = Character(
			inputVector.getWord(4),
			stoi(inputVector.getWord(5)),
			stoi(inputVector.getWord(6)));

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
		cout << "Unknown mode!" << endl;
	}

	return 0;
}
