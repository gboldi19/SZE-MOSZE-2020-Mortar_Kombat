/**
 * @class Monster
 * @brief This is a subclass representing the enemies.
*/

#ifndef MONSTER_H
#define MONSTER_H

#include "Character.h"

class Monster : public Character
{
public:
    Monster(const std::string characterName, float healthPoints, float damagePoints, float attackCoolDown);
    /**
    * @brief Monster construction.
    * @param Path to file containing the attributes.
    * @return Monster with defined parameters.
    */
    static Monster parse(std::string fileName);
};

#endif
