#pragma once

#include "PlayerA6.h"
#include "Vector.h"
#include "Globals.h"

class Team
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

		for (int i = 0; i < mPlayers.Size(); ++i)
		{
			if (mPlayers[i].GetStat(Stats::AttackCount) != 0 && mPlayers[i] >= *player)
			{
				player = &mPlayers[i];
			}
		}

		if (player->GetStat(Stats::AttackCount) == 0)
		{
			return nullptr;
		}

		return player;
	}

	void DamagePlayer(PlayerA6* player)
	{
		if (player == nullptr || !player->isAlive() || GetRemainingPlayers() == 0)
		{
			return;
		}

		int playerAttackedIndex = rand() % mPlayers.Size();
		int diceRoll = (rand() % 100) + 1;

		while (!mPlayers[playerAttackedIndex].isAlive())
		{
			playerAttackedIndex = rand() % mPlayers.Size();
		}

		std::cout << "\n > ";

		std::cout << player->GetName() << " has attacked " << mPlayers[playerAttackedIndex].GetName();
		mPlayers[playerAttackedIndex].IncrementStat(Stats::Health, -player->GetStat(Stats::Attack));

		//std::cout << "\n";

		if (diceRoll <= 25)
		{
			int speedDebuff = 10;

			std::cout << "\n\t" << mPlayers[playerAttackedIndex].GetName() << "'s speed has decreased by " << speedDebuff;
			mPlayers[playerAttackedIndex].IncrementStat(Stats::Speed, -speedDebuff);

			if (diceRoll <= 10)
			{
				int speedBuff = 5;

				std::cout << "\n\t" << player->GetName() << "'s speed has increased by " << speedBuff;
				player->IncrementStat(Stats::Speed, speedBuff);
			}

			std::cout << "\n";
		}

		player->SetStat(Stats::AttackCount, 0);
	}

	int GetRemainingPlayers()
	{
		int remainingPlayers = 0;

		for (int i = 0; i < mPlayers.Size(); ++i)
		{
			if (mPlayers[i].isAlive())
			{
				++remainingPlayers;
			}
		}

		return remainingPlayers;
	}

	void OrderPlayers()
	{
		Globals::IntroSort(mPlayers.Begin(), mPlayers.End(), [](const PlayerA6& a, const PlayerA6& b)
			{
				//if (a.GetStat(Stats::AttackCount) == 0 || !a.isAlive())
				//{
				//	return true;
				//}
				//
				//if (b.GetStat(Stats::AttackCount) == 0 || !b.isAlive())
				//{
				//	return false;
				//}

				return a.GetStat(Stats::Speed) < b.GetStat(Stats::Speed);
			});
	}

	void StartTurn()
	{
		for (int i = 0; i < mPlayers.Size(); ++i)
		{
			mPlayers[i].SetStat(Stats::AttackCount, 1);
		}

		OrderPlayers();
	}

	void PrintPlayerStats(int playerIndex)
	{
		mPlayers[playerIndex].PrintStats();
	}

	Vector<PlayerA6>& GetPlayers()
	{
		return mPlayers;
	}

private:
	std::string mName;
	Vector<PlayerA6> mPlayers;
};