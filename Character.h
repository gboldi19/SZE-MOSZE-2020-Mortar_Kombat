#include "JSONParser.h"
#include <string>
#include <fstream>
#include <map>
#include <any>

class Character
{
private:
	const std::string name;
	unsigned int HP;
	const unsigned int DMG;
public:
	Character(const std::string characterName, const unsigned int healthPoints, const unsigned int damagePoints);
	static Character parseUnit(std::string fileName);
	const std::string getName() const;
	const unsigned int getHP() const;
	const unsigned int getDMG() const;
	void gotHit(const Character &attacker);
};