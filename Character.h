#include <string>


class Character
{
private:
	std::string name;
	unsigned int HP, DMG;
public:
	Character(std::string characterName, int hitPoints, int damagePoints);
	void setHP(int hitPoints);
	void setDMG(int damagePoints);
	int getHP();
	int getDMG();
	void setName(std::string characterName);
	std::string getName();
};
