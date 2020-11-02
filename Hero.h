/**
 * @class Hero
 * @brief This is a subclass representing the main character.
 * Contains level up management.
*/

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
	void doHit(Character& victim);
public:
	/**
	* @brief Hero construction.
	* @param Path to file containing the attributes.
	* @return Hero with defined parameters.
	*/
    static Hero parse(std::string fileName);
	const unsigned int getLevel() const; ///< Getter for level.
};

#endif
