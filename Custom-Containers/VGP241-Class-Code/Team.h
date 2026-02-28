#pragma once

#include "PlayerA6.h"
#include "Vector.h"

class Teams
{
public:
	void Initialize(int numPlayers)
	{
		for (int i = 0; i < numPlayers; ++i)
		{
			PlayerA6 player;
			mPlayers.PushBack(player);
		}
	}

	PlayerA6* GetNextBattlingPlayer()
	{
		PlayerA6* player = &mPlayers[0];

		for (int i = 0; i < mPlayers.Size(); i++)
		{
			if (mPlayers[i] > *player && mPlayers[i].GetStat(Stats::AttackCount) == 0)
			{

			}
		}
	}

	void DamagePlayer(PlayerA6* player)
	{
		int randPlayerIndex = rand() % mPlayers.Size();
		int diceRoll = (rand() % 100) + 1;

		mPlayers[randPlayerIndex].SetStat(Stats::Health, mPlayers[randPlayerIndex].GetStat(Stats::Health) - 1);

		if (diceRoll <= 25)
		{

		}

		if (diceRoll <= 10)
		{

		}

		player->SetStat(Stats::AttackCount, 0);
	}

	int GetRemainingPlayers()
	{
		int sum = 0;

		for (int i = 0; i < mPlayers.Size(); ++i)
		{
			if (mPlayers[i].isAlive())
			{
				++sum;
			}
		}

		return sum;
	}

private:
	std::string mName;
	Vector<PlayerA6> mPlayers;
};