/**
 * @class Character
 * @brief This is a base class representing our entity.
 * Handels their attributes and interactions.
*/

#ifndef CHARACTER_H
#define CHARACTER_H

#include "JSON.h"
#include <string>
#include <fstream>
#include <map>
#include <any>
#include <iostream>

struct Damage
{
	int physical;
	int magical;
	Damage() : physical(0), magical(0) {};
	Damage(int _physical, int _magical) : physical(_physical), magical(_magical) {}
	Damage operator+=(int);
	Damage operator+=(const Damage&);
	Damage operator*=(int);
	Damage operator*=(const Damage&);
};

class Character
{
protected:
	const std::string name; ///< Name of the Character.
	Damage DMG; ///< Different DMG values of different Character.
	float maxHP, HP, ACD, DEF; ///< Maximum health points, health points, damage points and attack cooldown time of the Character, respectively.
	Character(const std::string& _name, float _maxHP, float _physicalDMG, float _magicalDMG, float _ACD, float _DEF); ///< Generic constructor of the class.
	/**
	* @brief Starts hitting procedure.
	* @param The victim Character.
	* Inflicts damage to the victim's health points.
	* Overload available for XP management.
	*/
	virtual void doHit(Character& victim);
public:
	const std::string getName() const; ///< Getter for name.
	const float getHealthPoints() const; ///< Getter for health points.
	const float getMaxHealthPoints() const; ///< Getter for maximum health points.
	const float getPhysicalDamage() const; ///< Getter for physical damage.
	const float getMagicalDamage() const; ///< Getter for magical damage.
	const float getAttackCoolDown() const; ///< Getter for attack cooldown.
	const float getDefense() const; ///< Getter for defense.
	/**
	* @brief Decreases HP by attacker's damage.
	* @brief Calculates the potentialXP from the damage dealt.
	* @param The Character pointer of the attacker.
	* @return The poteintal XP.
	*/
	float gotHit(Character* attacker);
	/**
	* @brief Checks vitals of Character.
	* @return true if alive
	* @return false if dead
	*/
	bool isAlive();
	/**
	* @brief Fight simulation.
	* @param Enemy.
	* Characters hit each other.
	* With every hit an attack cooldown starts.
	* Exits if either dies.
	*/
	void fightTilDeath(Character &enemy);
};

float RONAF(const float& num); //Rule Out Negative Any Float

#endif
