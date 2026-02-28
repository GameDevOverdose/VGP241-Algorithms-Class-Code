#pragma once

#include <string>
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
		mStats[(int)Stats::Attack]		= (rand() % 15) + 5;
		mStats[(int)Stats::Speed]		= (rand() % 15) + 5;
		mStats[(int)Stats::AttackCount]	= 1;
	}

	int GetStat(Stats stat) const
	{
		return mStats[(int)stat];
	}

	void SetStat(Stats stat, int value)
	{
		mStats[(int)stat] = value;
	}

	bool isAlive() const
	{
		return mStats[(int)Stats::Health] > 0;
	}

	bool operator>(const PlayerA6& rhs) const
	{
		return mStats[(int)Stats::Speed] > rhs.mStats[(int)Stats::Speed];
	}

private:
	std::string mName;
	Array<int, (int)Stats::Size> mStats;
};