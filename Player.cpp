#include "Player.h"

Player::Player(const std::string characterName, const float healthPoints, const float damagePoints, const float experiencePoints) : Character(characterName, healthPoints, experiencePoints)
{
    XP = experiencePoints;
}

void Player::levelup()
{
    while (XP >= 100)
    {
        XP -= 100;
        maxHP = round(HP * 1.1);
        DMG *= 1.1;
        HP = maxHP;                
    }
}
