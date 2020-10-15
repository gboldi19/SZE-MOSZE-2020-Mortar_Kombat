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
#include <string>
#include <fstream>

class Character
{
protected:
	const std::string name;
	unsigned int HP;
	const unsigned int DMG;
    const float AS;
    const unsigned int getDMG() const;
    const float getAS() const;
    void gotHit(const Character &attacker);
public:
    /**
     *The Character constructor.
     *It creates the Character object from the given parameters.
     *@param The Character's Name
     *@param The Character's Health Points
     *@param The Character's Damage points
     *@param The Character's Attack Speed
     */
	Character(const std::string characterName, const unsigned int healthPoints, const unsigned int damagePoints, const double attackSpeed);
    /**
    *It parses JSON object to Character.
    *@param File name 
    *@throw throw std::runtime_error("File not found!");
    *@return to the Character constructor
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
	const unsigned int getHP() const;
    /**
    *This function 'plays the game' between the two players.
    *@param player1
    *@param player2
    *@return the winner player
    */
    static Character* Fight (Character &player1, Character &player2);

};

#endif
