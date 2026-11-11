#include "Character.h"
#include "Battle.h"
#include "Inventory.h"
#include "Potion.h"
#include <iostream>
#include <cassert>

int main()
{
	// Test 1: Verify using the potion at index 0 restores health, reduces the inventory count 
	{
		Character player("Aldric", 3, 2, 1);

		std::cout << "HEALTH: " << player.getHealth() << "\n\n";

		player.takeDamage(6);

		Inventory inventory(3);

		Potion potion("Small Healing", 5);
		Potion potion2("Large Healing", 10);
		Potion potion3("Full Healing", 20);
		inventory.addPotion(potion);
		inventory.addPotion(potion2);
		inventory.addPotion(potion3);

		bool potionUsed = inventory.usePotion(0, player);

		assert(potionUsed);

		assert(inventory.getPotionCount() == 2);
		assert(player.getHealth() == 11);
	}

	{
		// Test 2: Is the potion consumed when character has full health
		Character player("Aldric", 3, 2, 1);

		std::cout << "HEALTH: " << player.getHealth() << "\n\n";

		Inventory inventory(3);

		Potion potion("Small Healing", 5);
		Potion potion2("Large Healing", 10);
		Potion potion3("Full Healing", 20);
		inventory.addPotion(potion);
		inventory.addPotion(potion2);
		inventory.addPotion(potion3);

		bool potionUsed = inventory.usePotion(0, player);

		assert(!potionUsed);

		assert(inventory.getPotionCount() == 3);
		assert(player.getHealth() == 12);
	}

	{
		// Test 3: Try requesting an invalid index
		Character player("Aldric", 3, 2, 1);

		player.takeDamage(4);

		std::cout << "HEALTH: " << player.getHealth() << "\n\n";

		Inventory inventory(3);

		Potion potion("Small Healing", 5);
		Potion potion2("Large Healing", 10);
		Potion potion3("Full Healing", 20);
		inventory.addPotion(potion);
		inventory.addPotion(potion2);
		inventory.addPotion(potion3);

		bool potionUsed = inventory.usePotion(5, player);

		assert(!potionUsed);

		assert(inventory.getPotionCount() == 3);
		assert(player.getHealth() == 8);
	}

	{
		// Test 4: Request potion from empty inventory
		Character player("Aldric", 3, 2, 1);

		player.takeDamage(3);

		std::cout << "HEALTH: " << player.getHealth() << "\n\n";

		Inventory inventory(3);

		bool potionUsed = inventory.usePotion(0, player);

		assert(!potionUsed);

		assert(inventory.getPotionCount() == 0);
		assert(player.getHealth() == 9);
	}

	{
		// Test 5: Does the inventory adhere to its maximum capacity?
		Inventory inventory(2);

		Potion potion("Small Healing", 5);
		Potion potion2("Large Healing", 10);
		Potion potion3("Full Healing", 20);

		bool firstAdded = inventory.addPotion(potion);
		bool secondAdded = inventory.addPotion(potion2);
		bool thirdAdded = inventory.addPotion(potion3);

		assert(firstAdded);
		assert(secondAdded);
		assert(!thirdAdded);

		assert(inventory.getPotionCount() == 2);
		assert(inventory.getCapacity() == 2);
	}

	{
		// Test 6: Does addPotion() reject potions with invalid values?
		Inventory inventory(3);

		Potion potion("Small Healing", -5);
		Potion potion2("Large Healing", 0);
		Potion potion3("Full Healing", 1);

		bool firstAdded = inventory.addPotion(potion);
		bool secondAdded = inventory.addPotion(potion2);
		bool thirdAdded = inventory.addPotion(potion3);

		assert(!firstAdded);
		assert(!secondAdded);
		assert(thirdAdded);

		assert(inventory.getPotionCount() == 1);
	}

	{
		// Test 7: Is it possible to heal beyond maximum health?
		Character player("Aldric", 3, 2, 1);
		player.takeDamage(3);

		assert(player.getHealth() == 9);

		Inventory inventory(1);

		Potion potion("Small Healing", 10);

		bool firstAdded = inventory.addPotion(potion);
		bool usedPotion = inventory.usePotion(0, player);

		assert(firstAdded);
		assert(usedPotion);
		assert(inventory.getPotionCount() == 0);
		assert(player.getHealth() == 12);
	}

	{
		// Test 8: Does usePotion() reject healing a defeated player?
		Character player("Aldric", 3, 2, 1);
		player.takeDamage(13);

		assert(!player.isAlive());

		Inventory inventory(1);

		Potion potion("Small Healing", 15);

		bool firstAdded = inventory.addPotion(potion);
		bool usedPotion = inventory.usePotion(0, player);

		assert(firstAdded);
		assert(!usedPotion);
		assert(inventory.getPotionCount() == 1);
	}

	{
		// Test 9: Is std::vector::erase() shifting elements to fill the gap as expected?
		Character player("Aldric", 3, 2, 1);
		player.setMaximumHealth(40);
		player.takeDamage(30);

		assert(player.getHealth() == 10);

		Inventory inventory(3);

		Potion potion("Small Healing", 5);
		Potion potion2("Large Healing", 10);
		Potion potion3("Full Healing", 15);

		bool firstAdded = inventory.addPotion(potion);
		bool secondAdded = inventory.addPotion(potion2);
		bool thirdAdded = inventory.addPotion(potion3);
		
		assert(firstAdded);
		assert(secondAdded);
		assert(thirdAdded);
		assert(inventory.getPotionCount() == 3);

		bool usedPotion = inventory.usePotion(1, player);

		assert(usedPotion);
		assert(player.getHealth() == 20);
		assert(inventory.getPotionCount() == 2);

		usedPotion = inventory.usePotion(1, player);

		assert(usedPotion);
		assert(player.getHealth() == 35);
		assert(inventory.getPotionCount() == 1);
	}

	{
		// Test 10: zero-capacity inventory
		Inventory inventory(0);
		Inventory inventory2(1);

		assert(inventory.getCapacity() == 0);
		assert(inventory2.getCapacity() == 1);

		Potion potion("Small Healing", 5);
		
		bool addedToFirst = inventory.addPotion(potion);
		assert(!addedToFirst);
		assert(inventory.getPotionCount() == 0);

		bool addedToSecond = inventory2.addPotion(potion);
		assert(addedToSecond);
		assert(inventory2.getPotionCount() == 1);
		
		assert(inventory.getPotionCount() == 0);
	}

	return 0;
}
