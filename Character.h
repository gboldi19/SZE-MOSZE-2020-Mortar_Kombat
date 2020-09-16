#include <string>

class Character
{
private:
	std::string name;
	unsigned int HP;
    unsigned int DMG;
public:
	Character(const std::string characterName, const unsigned int healthPoints, const unsigned int damagePoints);
    const std::string getName() const;
	const unsigned int getHP() const;
	const unsigned int getDMG() const;
    void gotHit(const unsigned int damagePoints);
};
