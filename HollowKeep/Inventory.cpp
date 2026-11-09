#include "Inventory.h"

Inventory::Inventory(std::size_t capacity) : m_capacity(capacity) {}

bool Inventory::addPotion(const Potion& potion)
{
	if (m_potions.size() >= m_capacity)
	{
		return false;
	}

	if (potion.healingAmount <= 0)
	{
		return false;
	}

	m_potions.push_back(potion);

    return true;
}

bool Inventory::usePotion(std::size_t index, Character& target)
{
	if (index >= m_potions.size())
	{
		return false;
	}

	if (!target.isAlive())
	{
		return false;
	}

	if (target.getHealth() >= target.getMaximumHealth())
	{
		return false;
	}

	int healing = m_potions[index].healingAmount;

	return healing;
}

std::size_t Inventory::getPotionCount() const
{
	return m_potions.size();
}

std::size_t Inventory::getCapacity() const
{
	return m_capacity;
}

