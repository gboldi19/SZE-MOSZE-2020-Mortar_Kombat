#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <fstream>

class Character
{
protected:
	const std::string name;
	float maxHP, HP, DMG;
	const float getDMG() const;
	static std::string* parseUnit(const std::string &fileName);
	Character(const std::string* characterAttributes);
public:
	static Character CharacterFromFile(const std::string &fileName);
	const std::string getName() const;
	//getHP() is public (and getDMG() is not) because main() uses HP in ostream 
	const float getHP() const;
	//gotHit() exists to inflict damage on the parameter of doHit()
	float gotHit(Character* attacker);
	//doHit() is the default attacking method
	//doHit() utalizes gotHit() on the victim
	//doHit() utalizes gainXP() on 'this' if type is Player
	//override is in Player.h
	virtual void doHit(Character& victim);
};

#endif
