#pragma once

#include <string>
#include <iostream>
#include <iomanip>

#include "Array.h"

enum class Stats
{
	Health = 0,
	Attack,
	Speed,
	AttackCount,
	Size
};

class PlayerA6
{
public:
	PlayerA6()
	{
		mStats[(int)Stats::Health]		= 100;
		mStats[(int)Stats::Attack]		= (rand() % 16) + 5;
		mStats[(int)Stats::Speed]		= (rand() % 16) + 5;
		mStats[(int)Stats::AttackCount]	= 1;
	}

	std::string GetName() const
	{
		return mName;
	}

	int GetStat(Stats stat) const
	{
		return mStats[(int)stat];
	}

	void SetName(const std::string& name)
	{
		mName = name;
	}

	void SetStat(Stats stat, int value)
	{
		value = std::max(0, value);
		mStats[(int)stat] = value;
	}

	void IncrementStat(Stats stat, int value)
	{
		mStats[(int)stat] = std::max(0, mStats[(int)stat] + value);
	}

	bool isAlive() const
	{
		return mStats[(int)Stats::Health] > 0;
	}

	bool operator>(const PlayerA6& rhs) const
	{
		return mStats[(int)Stats::Speed] > rhs.mStats[(int)Stats::Speed];
	}

	bool operator>=(const PlayerA6& rhs) const
	{
		return mStats[(int)Stats::Speed] >= rhs.mStats[(int)Stats::Speed];
	}

	bool operator<(const PlayerA6& rhs) const
	{
		return mStats[(int)Stats::Speed] < rhs.mStats[(int)Stats::Speed];
	}

	bool operator<=(const PlayerA6& rhs) const
	{
		return mStats[(int)Stats::Speed] <= rhs.mStats[(int)Stats::Speed];
	}

	void PrintStats()
	{
		if (!isAlive())
		{
			std::cout << std::right << std::setw(24) << " Dead";
			return;
		}

		// Remove the -1 and uncomment the turn part to also print attack count
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
			//case 3:
			//	std::cout << "Trn";
			//	break;
			default:
				break;
			}

			std::cout << " " << std::right << std::setw(2) << GetStat((Stats)i) << "  ";
		}
	}

private:
	std::string mName;
	Array<int, (int)Stats::Size> mStats;
};