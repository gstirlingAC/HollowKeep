#include "Character.h"
#include <iostream>
#include <cassert>

int main()
{
	Character player("Aldric", 3, 2, 1);
	Character enemy("Boab", 2, 2, 3);

	enemy.setMaximumHealth(20);
	assert(enemy.getHealth() == 20);
	
	player.displayStats();
	enemy.displayStats();
	assert(player.getAttackPower() == 5);
	assert(player.getDefenceValue() == 3);

	player.setAttackPower(-5);
	assert(player.getAttackPower() == 5);

	player.setDefenceValue(-5);
	assert(player.getDefenceValue() == 3);

	enemy.setAttackPower(6);
	enemy.setDefenceValue(7);
	assert(enemy.getAttackPower() == 6);
	assert(enemy.getDefenceValue() == 7);

	assert(player.attack(enemy) == 0);
	assert(enemy.getHealth() == 20);

	assert(enemy.attack(player) == 3);
	assert(player.getHealth() == 9);

	player.setAttackPower(10);
	assert(player.getAttackPower() == 10);

	player.setDefenceValue(10);
	assert(player.getDefenceValue() == 10);

	enemy.setAttackPower(10);
	assert(enemy.getAttackPower() == 10);

	enemy.setDefenceValue(10);
	assert(enemy.getDefenceValue() == 10);

	assert(player.attack(enemy) == 0);
	assert(enemy.attack(player) == 0);

	player.setAttackPower(30);
	assert(player.getAttackPower() == 30);

	player.healDamage(5);
	assert(player.getHealth() == 12);

	player.healDamage(-5);
	assert(player.getHealth() == 12);

	player.healDamage(50);
	assert(player.getHealth() == 12);

	/*std::cout << "Player attack: " << player.getAttackPower() << "\n";
	std::cout << "Enemy attack: " << enemy.getAttackPower() << "\n";
	std::cout << "Player defence: " << player.getDefenceValue() << "\n";
	std::cout << "Enemy defence: " << enemy.getDefenceValue() << "\n";*/
	assert(player.attack(enemy) == 20);
	assert(enemy.attack(player) == 0);

	/*std::cout << "Player attack: " << player.getAttackPower() << "\n";
	std::cout << "Enemy attack: " << enemy.getAttackPower() << "\n";
	std::cout << "Player defence: " << player.getDefenceValue() << "\n";
	std::cout << "Enemy defence: " << enemy.getDefenceValue() << "\n";*/
	assert(player.attack(enemy) == 0);

	assert(player.attack(player) == 0);
	assert(enemy.isAlive() == false);

	enemy.healDamage(10);
	assert(enemy.getHealth() == 0);

	enemy.setMaximumHealth(40);
	assert(enemy.getHealth() == 40);

	enemy.setDefenceValue(40);
	assert(player.attack(enemy) == 0);


	
	return 0;
}