#ifndef INVENTORY_H
#define INVENTORY_H
#include <vector>
#include "Potion.h"
#include "Character.h"

class Inventory
{
public:
	Inventory(std::size_t capacity);
	bool addPotion(const Potion& potion);
	bool usePotion(std::size_t index, Character& target);
	std::size_t getPotionCount() const;
	std::size_t getCapacity() const;
private:
	std::vector<Potion> m_potions;
	std::size_t m_capacity;
};

#endif
