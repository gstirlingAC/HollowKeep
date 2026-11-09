#include "Battle.h"

Battle::Battle(Character& player, Character& enemy) : 
	m_player(player), 
	m_enemy(enemy), 
	m_playerDamage(0),
	m_currentRound(1), 
	m_currentTurn(0), 
	m_encounterOutcome(BattleOutcome::INPROGRESS) 
{
	if (m_player.isAlive() && !m_enemy.isAlive())
	{
		m_encounterOutcome = BattleOutcome::FIRSTCHARACTERWON;
	}

	if (!m_player.isAlive() && m_enemy.isAlive())
	{
		m_encounterOutcome = BattleOutcome::SECONDCHARACTERWON;
	}

	if (!m_player.isAlive() && !m_enemy.isAlive())
	{
		m_encounterOutcome = BattleOutcome::DRAW;
	}
}

BattleOutcome Battle::getBattleOutcome() const
{
	return m_encounterOutcome;
}

int Battle::performTurn()
{
	int damage = 0;

	if (!m_player.isAlive() && !m_enemy.isAlive())
	{
		m_encounterOutcome = BattleOutcome::DRAW;
	}
	else if (m_player.isAlive() && !m_enemy.isAlive())
	{
		m_encounterOutcome = BattleOutcome::FIRSTCHARACTERWON;
	}
	else if (!m_player.isAlive() && m_enemy.isAlive())
	{
		m_encounterOutcome = BattleOutcome::SECONDCHARACTERWON;
	}

	if ((m_player.isAlive() && m_enemy.isAlive()) && m_encounterOutcome == BattleOutcome::INPROGRESS)
	{
		if (m_currentTurn == 0) 
		{
			damage = m_player.attack(m_enemy);

			if (!m_enemy.isAlive())
			{
				m_encounterOutcome = BattleOutcome::FIRSTCHARACTERWON;
			}

			m_playerDamage = damage;
		}
		else
		{
			damage = m_enemy.attack(m_player);

			if (m_playerDamage == 0 && damage == 0)
			{
				m_encounterOutcome = BattleOutcome::DRAW;
			}

			if (!m_player.isAlive())
			{
				m_encounterOutcome = BattleOutcome::SECONDCHARACTERWON;
			}


			m_currentRound++;
		}

		if (m_encounterOutcome == BattleOutcome::INPROGRESS)
		{
			m_currentTurn = (m_currentTurn + 1) % 2;
		}
	}

	return damage;
}

int Battle::getRoundNumber() const
{
	return m_currentRound;
}


