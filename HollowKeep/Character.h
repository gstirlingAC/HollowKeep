#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>

class Character 
{
public:
	Character(std::string characterName, int characterMight, int characterFinesse, int characterWits);
	/*~Character();*/

	std::string getName() const;
	int getHealth() const;
	int getAttackPower() const;
	int getDefenceValue() const;
	int getMaximumHealth() const;

	int attack(Character& target);

	void setMaximumHealth(int value);
	void setAttackPower(int value);
	void setDefenceValue(int value);

	void healDamage(int healAmount);
	void displayStats() const;
	void takeDamage(int damageAmount);

	bool isAlive() const;

private:
	std::string m_name;
	
	static constexpr int kStartingHealth = 12;

	int m_currentHealth;
	int m_maximumHealth;

	int m_might;
	int m_finesse;
	int m_wits;

	int m_attackPower;
	int m_defence;
};



#endif
