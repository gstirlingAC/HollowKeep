#include "Character.h"
#include <iostream>
#include <cassert>

int main()
{
	Character hero("Aldric", 3, 2, 1);

	// Initial health
	assert(hero.getHealth() == 12);

	// Normal damage
	hero.takeDamage(5);
	assert(hero.getHealth() == 7);

	// Normal healing
	hero.healDamage(3);
	assert(hero.getHealth() == 10);

	// Negative damage
	hero.takeDamage(-5);
	assert(hero.getHealth() == 10);

	// Excessive healing
	hero.healDamage(10);
	assert(hero.getHealth() == 12);

	// Negative healing
	hero.healDamage(-6);
	assert(hero.getHealth() == 12);

	// Excessive damage
	hero.takeDamage(20);
	/*std::cout << "Is Alive? " << std::boolalpha << hero.isAlive() << ".\n";*/
	assert(!hero.isAlive());
	assert(hero.getHealth() == 0);

	// Healing after death
	hero.healDamage(5);
	assert(hero.getHealth() == 0);
	
	return 0;
}