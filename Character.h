#include <string>

using namespace std;

class Character
{
private:
	string name;
	unsigned int HP, DMG;
public:
	Character(string characterName, int hitPoints, int damagePoints);
	void setHP(int hitPoints);
	void setDMG(int damagePoints);
	int getHP();
	int getDMG();
	void setName(string characterName);
	string getName();
};
