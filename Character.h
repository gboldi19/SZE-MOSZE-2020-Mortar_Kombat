#include <string>

using namespace std;

class Character
{
private:
	string name;
	unsigned int HP, DMG;
public:
	Character(string characterName, int healthPoints, int damagePoints);
    string getName();
	int getHP();
	int getDMG();
    void gotHit(int damagePoints);
};
