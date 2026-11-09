#include "Character.h"
#include "Battle.h"
#include <iostream>
#include <cassert>

int main()
{
	// Test 1: Alternating turns and their returned damage
	{
		Character player("Aldric", 3, 2, 1);
		Character enemy("Boab", 2, 2, 3);

		Battle battle(player, enemy);

		player.setMaximumHealth(10);
		enemy.setMaximumHealth(10);

		int damage = battle.performTurn();
		damage = battle.performTurn();

		assert(damage == 2);
		assert(player.getHealth() == 8);
		assert(enemy.getHealth() == 8);
	}

	// Test 2: Player Dead
	{
		Character player("Aldric", 3, 2, 1);
		Character enemy("Boab", 2, 2, 3);

		Battle battle(player, enemy);

		player.setMaximumHealth(0);
		enemy.setMaximumHealth(10);

		player.displayStats();
		enemy.displayStats();

		int damage = battle.performTurn();

		std::cout << "Damage: " << damage << "\n";

		assert(damage == 0);
		assert(battle.getBattleOutcome() == BattleOutcome::SECONDCHARACTERWON);
	}

	// Test 3: Enemy Dead
	{
		Character player("Aldric", 3, 2, 1);
		Character enemy("Boab", 2, 2, 3);

		Battle battle(player, enemy);

		player.setMaximumHealth(10);
		enemy.setMaximumHealth(0);

		int damage = battle.performTurn();

		assert(damage == 0);
		assert(battle.getBattleOutcome() == BattleOutcome::FIRSTCHARACTERWON);
	}

	// Test 4: Draw
	{
		Character player("Aldric", 3, 2, 1);
		Character enemy("Boab", 2, 2, 3);

		Battle battle(player, enemy);

		player.setMaximumHealth(0);
		enemy.setMaximumHealth(0);

		int damage = battle.performTurn();

		assert(damage == 0);
		assert(battle.getBattleOutcome() == BattleOutcome::DRAW);
	}


	return 0;
}