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
#include "JSONParser.h"
#include "Character.h"
#include <string>
#include <fstream>
#include <map>
#include <any>

class Character
{
protected:
	const std::string name;
	float maxHP, HP, DMG, AS;
  Character(const std::string characterName, float healthPoints, float damagePoints, float attackSpeed);
  const float getDMG() const;
  const float getAS() const;
  virtual void doHit(Character& victim);
public:
    /**
     *This function calls th parseUnit function.
     *@param The reference for the name of the file which contains the character attributes.
	 *@return The name of the file which contains the character attributes.
     */
	static Character parseUnit(std::string fileName);
    /**
    *
    *@return Character's name
    */
	const std::string getName() const;
    /**
    *@return Character's Health Points
    */
	const float getHP() const;
	/**
	*Calculates the potentialXP from the damage dealt.
	*@param The function's argument is the attacker's pointer.
	*@return Returns the poteintalXP.
	*/
    float gotHit(Character* attacker);
    /**
    *This function 'plays the game' between the two players.
    *@param player1
    *@param player2
    *@return the winner player
    */
    static Character* Fight (Character &player1, Character &player2);

};

void ruleOutNegativeAnyFloat(std::any& num);

#endif
