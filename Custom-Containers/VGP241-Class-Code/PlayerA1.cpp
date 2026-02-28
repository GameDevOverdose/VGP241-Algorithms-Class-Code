#include "PlayerA1.h"

PlayerA1::PlayerA1()
{
}

PlayerA1::~PlayerA1()
{
}

int PlayerA1::playerInitialized = 0;

const void PlayerA1::InitializePlayer(std::string name)
{
	if(!name.empty())
	{
		mName = name;
	}
	else
	{
		playerInitialized++;
		mName = "Hero " + std::to_string(playerInitialized);
	}

	mStats[(int)Stats::Health] = 100;
	mStats[(int)Stats::Attack] = (rand() % 5) + 1;
	mStats[(int)Stats::Defense] = (rand() % 5) + 1;
	mStats[(int)Stats::Stamina] = (rand() % 5) + 1;
	mStats[(int)Stats::Speed] = (rand() % 5) + 1;
}

const std::string PlayerA1::GetName() const
{
	return mName;
}

const int PlayerA1::GetStat(Stats stat) const
{
	return mStats[(int)stat];
}

const void PlayerA1::DisplayPlayer() const
{
	std::cout << "Player Name: " << mName << "\n";
	std::cout << "\tHealth: " <<	mStats[(int)Stats::Health] << "\n";
	std::cout << "\tAttack: " <<	mStats[(int)Stats::Attack] << "\n";
	std::cout << "\tDefense: " <<	mStats[(int)Stats::Defense] << "\n";
	std::cout << "\tStamina: " <<	mStats[(int)Stats::Stamina] << "\n";
	std::cout << "\tSpeed: " <<		mStats[(int)Stats::Speed] << "\n\n";
}

const void PlayerA1::SetName(std::string name)
{
	mName = name;
}

const void PlayerA1::SetStat(Stats stat, int value)
{
	value = (value < 0) ? 0:value;
	mStats[(int)stat] = value;
}