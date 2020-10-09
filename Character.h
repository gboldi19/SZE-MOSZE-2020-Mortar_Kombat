#include <string>
#include <fstream>

class Character
{
private:
	const std::string name;
protected:
	float maxHP;
	float HP;
	float DMG;
public:
	Character(const std::string characterName, const float healthPoints, const float damagePoints);
	static Character parseUnit(std::string fileName);
	const std::string getName() const;
	const float getHP() const;
	const float getDMG() const;
	void gotHit(Character &attacker);
	template<typename Player>
		void gotHit(Player &attacker);
};
