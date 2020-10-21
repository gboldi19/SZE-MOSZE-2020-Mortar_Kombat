#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include <math.h>
#include <any>

class Player : public Character
{
private:
	float XP;
    Player(const std::string characterName, float healthPoints, float damagePoints, float attackSpeed);
	void levelup(float levelupXP);
	void gainXP(float damagePoints);
public:
    static Player parseUnit(std::string fileName);
	void doHit(Character& victim);
};

#endif
