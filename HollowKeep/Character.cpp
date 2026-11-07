#include "Character.h"
#include <iostream>
#include <algorithm>

Character::Character(std::string characterName, int characterMight, int characterFinesse, int characterWits) 
	: 
	m_name(characterName), 
	m_currentHealth(kStartingHealth),
	m_maximumHealth(kStartingHealth),
	m_might(characterMight), 
	m_finesse(characterFinesse),
	m_wits(characterWits)
{}

int Character::getHealth() const
{
	return m_currentHealth;
}

std::string Character::getName() const
{
	return m_name;
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
			int finalHealth = std::min(m_currentHealth + healAmount, m_maximumHealth);
			int actualHealing = finalHealth - m_currentHealth;
			int wastedHealing = healAmount - actualHealing;

			m_currentHealth = finalHealth;

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
	std::cout << "\n";
}

void Character::takeDamage(int damageAmount)
{
	if (damageAmount < 0)
	{
		std::cout << "Error: Negative numbers not allowed.\n";
	}
	else
	{
		std::cout << m_name << " takes " << damageAmount << " damage.\n";
		m_currentHealth -= damageAmount;
	}
	
		
	if (!isAlive())
	{
		m_currentHealth = 0;
		std::cout << m_name << " has taken too much damage and has died.\n";
	}
}

bool Character::isAlive() const
{
	return m_currentHealth > 0;
}




