#ifndef BATTLE_H
#define BATTLE_H

#include "Character.h"

enum class BattleOutcome
{
	INPROGRESS,
	FIRSTCHARACTERWON,
	SECONDCHARACTERWON,
	DRAW
};

class Battle 
{
public:
	Battle(Character& player, Character& enemy);

	BattleOutcome getBattleOutcome() const;
	int getRoundNumber() const;
	int performTurn();


private:
	Character& m_player;
	Character& m_enemy;

	int m_playerDamage;

	int m_currentRound;
	int m_currentTurn;

	BattleOutcome m_encounterOutcome;

};

#endif
