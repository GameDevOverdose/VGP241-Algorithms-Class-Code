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
	PlayerA6();

	std::string GetName() const;

	int GetStat(Stats stat) const;
	bool isAlive() const;

	void SetName(const std::string& name);
	void SetStat(Stats stat, int value);
	void IncrementStat(Stats stat, int value);

	void PrintStats();

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

private:
	std::string mName;
	Array<int, (int)Stats::Size> mStats;
};