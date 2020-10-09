#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include <math.h>

class Player : public Character
{
private:
	float XP;
	void levelup(float levelupXP);
	void gainXP(float damagePoints);
public:
	Player(const std::string characterName, const float healthPoints, const float damagePoints);
	float getXP() { return XP; } //testing purposes
};

#endif
