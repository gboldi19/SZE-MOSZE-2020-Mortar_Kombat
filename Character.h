/**
 * @class Character
 * 
 * @brief This class is the spine of our game, links together the varaiable parts. 
 * 
 * @author Mortar_Kombat
 * 
*/

#ifndef CHARACTER_H
#define CHARACTER_H

#include "JSON.h"
#include <string>
#include <fstream>
#include <map>
#include <any>

class Character
{
protected:
	const std::string name;
	float maxHP, HP, DMG, ACD;
	Character(const std::string _name, float _maxHP, float _DMG, float _ACD);
	virtual void doHit(Character& victim);
public:
    /**
    *
    *@return Character's name
    */
	const std::string getName() const;
    /**
    *@return Character's Health Points
    */
	const float getHealthPoints() const;
	const float getMaxHealthPoints() const;
	const float getDamage() const;
	const float getAttackCoolDown() const;
	/**
	*Calculates the potentialXP from the damage dealt.
	*@param The function's argument is the attacker's pointer.
	*@return Returns the poteintalXP.
	*/
    float gotHit(Character* attacker);
	bool isAlive();
	void fightTilDeath(Character &enemy);
};

#endif
