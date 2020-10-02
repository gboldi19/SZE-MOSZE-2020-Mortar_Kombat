#include "Character.h"

class Player : private Character
{
private:
    float XP;
public:
    Player(const std::string characterName, const float healthPoints, const float damagePoints, const float experiencePoints);
    void levelup();    
};
