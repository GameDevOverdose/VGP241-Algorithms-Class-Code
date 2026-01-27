#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

int Player::playerInitialized = 0;

const void Player::InitializePlayer(std::string name)
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

const std::string Player::GetName() const
{
	return mName;
}

const int Player::GetStat(Stats stat) const
{
	return mStats[(int)stat];
}

const void Player::DisplayPlayer() const
{
	std::cout << "Player Name: " << mName << "\n";
	std::cout << "\tHealth: " <<	mStats[(int)Stats::Health] << "\n";
	std::cout << "\tAttack: " <<	mStats[(int)Stats::Attack] << "\n";
	std::cout << "\tDefense: " <<	mStats[(int)Stats::Defense] << "\n";
	std::cout << "\tStamina: " <<	mStats[(int)Stats::Stamina] << "\n";
	std::cout << "\tSpeed: " <<		mStats[(int)Stats::Speed] << "\n\n";
}

const void Player::SetName(std::string name)
{
	mName = name;
}

const void Player::SetStat(Stats stat, int value)
{
	value = (value < 0) ? 0:value;
	mStats[(int)stat] = value;
}