#include "Character.h"
#include "Inventory.h"
#include <iostream>
#include <algorithm>

Character::Character(std::string characterName, int characterMight, int characterFinesse, int characterWits) :
	m_name(characterName),
	m_currentHealth(kStartingHealth),
	m_maximumHealth(kStartingHealth),
	m_might(characterMight),
	m_finesse(characterFinesse),
	m_wits(characterWits),
	m_attackPower(5),
	m_defence(3)
{
}

std::string Character::getName() const
{
	return m_name;
}

int Character::getHealth() const
{
	return m_currentHealth;
}

int Character::getAttackPower() const
{
	return m_attackPower;
}

int Character::getDefenceValue() const
{
	return m_defence;
}

int Character::getMaximumHealth() const
{
	return m_maximumHealth;
}

int Character::attack(Character& target)
{
	if (this == &target)
	{
		std::cout << "Error: A character cannot attack itself.\n";
		return 0;
	}

	if (!isAlive())
	{
		std::cout << m_name << " is dead and cannot attack!\n";
		return 0;
	}

	if (!target.isAlive())
	{
		std::cout << target.getName() << " is already dead!\n";
		return 0;
	}

	int damage = std::max(0, m_attackPower - target.getDefenceValue());
	std::cout << m_name << " attacks " << target.getName() << "!\n";
	target.takeDamage(damage);

	return damage;
}

void Character::setMaximumHealth(int value)
{
	if (value < 0)
		std::cout << "Error: Negative numbers not allowed.\n";
	else
	{
		m_maximumHealth = value;
		m_currentHealth = m_maximumHealth;
	}
}

void Character::setAttackPower(int value)
{
	if (value < 0)
		std::cout << "Error: Negative numbers not allowed.\n";
	else
		m_attackPower = value;
		
}

void Character::setDefenceValue(int value)
{
	if (value < 0)
		std::cout << "Error: Negative numbers not allowed.\n";
	else
		m_defence = value;
}

void Character::healDamage(int healAmount)
{
	if (healAmount < 0)
	{
		std::cout << "Error: Negative numbers not allowed.\n";
	}
	else
	{
		if (!isAlive()) 
		{
			std::cout << m_name << " has died and cannot be healed.\n";
			m_currentHealth = 0;
		}
		else
		{
			int healingNeeded = m_maximumHealth - m_currentHealth;
			int actualHealing = std::min(healAmount, healingNeeded);
			int wastedHealing = healAmount - actualHealing;

			m_currentHealth += actualHealing;

			std::cout << m_name << " has healed with " << actualHealing << " points.\n";
			std::cout << m_name << " now has " << m_currentHealth << " health.\n\n";

			std::cout << "Overhealing (wasted): " << wastedHealing << " health points.\n\n";
		}
	}
}

void Character::displayStats() const
{
	std::cout << "Name: " << m_name << "\n";
	std::cout << "Health: " << m_currentHealth << "\n";
	std::cout << "\n=== Stats ===\n";
	std::cout << "Might: " << m_might << "\n";
	std::cout << "Finesse: " << m_finesse << "\n";
	std::cout << "Wits: " << m_wits << "\n";
	std::cout << "Attack: " << m_attackPower << "\n";
	std::cout << "Defence: " << m_defence << "\n";
	std::cout << "\n";
}

void Character::takeDamage(int damageAmount)
{
	if (damageAmount < 0)
	{
		std::cout << "Error: Negative numbers not allowed.\n\n";
	}
	else
	{
		std::cout << m_name << " takes " << damageAmount << " damage.\n\n";
		m_currentHealth -= damageAmount;
	}
	
		
	if (!isAlive())
	{
		m_currentHealth = 0;
		std::cout << m_name << " has taken too much damage and has died.\n\n";
	}
}

bool Character::isAlive() const
{
	return m_currentHealth > 0;
}




