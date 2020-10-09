#include "Character.h"
#include <math.h>

class Player : public Character
{
private:
	float XP;
	void levelup(float levelupXP);
public:
	Player(const std::string characterName, const float healthPoints, const float damagePoints, const float experiencePoints);
	void gainXP(float damagePoints);
};
