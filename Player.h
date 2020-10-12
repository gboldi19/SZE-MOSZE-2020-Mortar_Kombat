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
	Player(const std::string* characterAttributes);
public:
	static Player PlayerFromFile(const std::string &fileName);
	void doHit(Character& victim);
};

#endif
