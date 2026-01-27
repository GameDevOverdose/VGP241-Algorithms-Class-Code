#pragma once

#include <string>
#include <iostream>

#include "Array.h"
#include "Vector.h"

enum class Stats
{
	Health = 0,
	Attack,
	Defense,
	Stamina,
	Speed
};

class Player
{
public:
	Player();
	~Player();

	const void InitializePlayer(std::string name = "");

	const std::string GetName() const;
	const int GetStat(Stats stat) const;
	const void DisplayPlayer() const;

	const void SetName(std::string name);
	const void SetStat(Stats stat, int value);

private:
	std::string mName;
	Array<int, 5> mStats;

	static int playerInitialized;
};