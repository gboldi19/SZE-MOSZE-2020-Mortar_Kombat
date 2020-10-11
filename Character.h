#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <fstream>

class Character
{
protected:
	const std::string name;
	float maxHP, HP;
	const float DMG;
	const float getDMG() const;
	static std::string* parseUnit(const std::string fileName);
	Character(const std::string* characterAttributes);
public:
	static Character CharacterFromFile(const std::string fileName);
	const std::string getName() const;
	const float getHP() const;
	float gotHit(Character* attacker);
	virtual void doHit(Character& victim);
};

#endif
