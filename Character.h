#include <string>

using namespace std;

class Character
{
private:
	string name;
	unsigned int HP, DMG;
public:
	Character(string characterName, int healthPoints, int damagePoints);
	void setHP(int healthPoints);
	void setDMG(int damagePoints);
	int getHP();
	int getDMG();
	void setName(string characterName);
	string getName();
};
