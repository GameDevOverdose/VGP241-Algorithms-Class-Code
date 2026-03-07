#include "PlayerA6.h"

PlayerA6::PlayerA6()
{
	mStats[(int)Stats::Health] = 100;
	mStats[(int)Stats::Attack] = (rand() % 16) + 5;
	mStats[(int)Stats::Speed] = (rand() % 16) + 5;
	mStats[(int)Stats::AttackCount] = 1;
}

std::string PlayerA6::GetName() const
{
	return mName;
}

int PlayerA6::GetStat(Stats stat) const
{
	return mStats[(int)stat];
}

bool PlayerA6::isAlive() const
{
	return mStats[(int)Stats::Health] > 0;
}

void PlayerA6::SetName(const std::string& name)
{
	mName = name;
}

void PlayerA6::SetStat(Stats stat, int value)
{
	value = std::max(0, value);
	mStats[(int)stat] = value;
}

void PlayerA6::IncrementStat(Stats stat, int value)
{
	if (stat == Stats::Speed)
	{
		mStats[(int)stat] = std::max(1, mStats[(int)stat] + value);
		return;
	}

	mStats[(int)stat] = std::max(0, mStats[(int)stat] + value);
}

void PlayerA6::PrintStats()
{
	if (!isAlive())
	{
		std::cout << std::right << std::setw(24) << " Dead";
		//std::cout << std::right << std::setw(32) << " Dead";
		return;
	}

	// Remove the -1 to also print attack count
	for (int i = 0; i < (int)Stats::Size - 1; ++i)
	{
		switch (i)
		{
		case 0:
			std::cout << "Hth";
			break;
		case 1:
			std::cout << "Atk";
			break;
		case 2:
			std::cout << "Spd";
			break;
		case 3:
			std::cout << "Trn";
			break;
		default:
			break;
		}

		std::cout << " " << std::right << std::setw(2) << GetStat((Stats)i) << "  ";
	}
}