#ifndef Hero_H
#define Hero_H

#include "Character.h"

class Hero : public Character
{
private:
	float XP, maxHPBonus, DMGBonus, ACDBonus, XPToLevelup;
    Hero(const std::string _name, float _HP, float _DMG, float _ACD, float _XPToLevelup, float _maxHPBonus, float _DMGBonus, float _ACDBonus);
	void levelup(float levelupXP);
	void gainXP(float damagePoints);
public:
    static Hero parse(std::string fileName);
	void doHit(Character& victim);
	/**
	 @return the Hero's current level.
	 */
	const unsigned int getLevel() const;
};

#endif
