#ifndef CHARACTER_H
#define CHARACTER_H

#include<string>

class Character 
{
public:
	Character(std::string characterName, int characterMight, int characterFinesse, int characterWits);
	/*~Character();*/

	int getHealth() const;
	std::string getName() const;
	void healDamage(int healAmount);
	bool isAlive() const;
	void displayStats() const;
	void takeDamage(int damageAmount);

private:
	std::string m_name;
	static constexpr int kStartingHealth = 12;
	int m_currentHealth;
	int m_maximumHealth;
	int m_might;
	int m_finesse;
	int m_wits;
};



#endif
