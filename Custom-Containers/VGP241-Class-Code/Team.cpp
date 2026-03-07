#include "Team.h"

void Team::Initialize(int numPlayers)
{
	for (int i = 0; i < numPlayers; ++i)
	{
		PlayerA6 player;
		mPlayers.PushBack(player);
	}
}

PlayerA6* Team::GetNextBattlingPlayer()
{
	PlayerA6* player = &mPlayers[0];

	if (!player->isAlive() || player->GetStat(Stats::AttackCount) == 0 || player->GetStat(Stats::Speed) == 0)
	{
		return nullptr;
	}

	return player;
}

void Team::DamagePlayer(PlayerA6* player)
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

		// clamp it to 1, dont reduce it below 1
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

int Team::GetRemainingPlayers()
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

void Team::OrderPlayers()
{
	Globals::IntroSort(mPlayers.Begin(), mPlayers.End(), [](const PlayerA6& a, const PlayerA6& b)
		{
			int aSpeed = 0;
			int bSpeed = 0;

			if (a.GetStat(Stats::AttackCount) > 0 && a.isAlive())
			{
				aSpeed = a.GetStat(Stats::Speed);
			}

			if (b.GetStat(Stats::AttackCount) > 0 && b.isAlive())
			{
				bSpeed = b.GetStat(Stats::Speed);
			}

			// if both speeds are 0, then just compare their normal speeds
			if (aSpeed == 0 && bSpeed == 0)
			{
				aSpeed = a.GetStat(Stats::Speed);
				bSpeed = b.GetStat(Stats::Speed);
			}

			return aSpeed > bSpeed;
		});
}

void Team::StartTurn()
{
	for (int i = 0; i < mPlayers.Size(); ++i)
	{
		mPlayers[i].SetStat(Stats::AttackCount, 1);
	}

	OrderPlayers();
}

void Team::EndMatch()
{
	for (int i = 0; i < mPlayers.Size(); ++i)
	{
		mPlayers[i].SetStat(Stats::AttackCount, 0);
	}

	OrderPlayers();
}

void Team::PrintPlayerStats(int playerIndex)
{
	mPlayers[playerIndex].PrintStats();
}

Vector<PlayerA6>& Team::GetPlayers()
{
	return mPlayers;
}