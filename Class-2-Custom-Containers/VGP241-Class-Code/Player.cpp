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

	mStats[Health] = 100;
	mStats[Attack] = (rand() % 5) + 1;
	mStats[Defense] = (rand() % 5) + 1;
	mStats[Stamina] = (rand() % 5) + 1;
	mStats[Speed] = (rand() % 5) + 1;
}

const std::string Player::GetName() const
{
	return mName;
}

const int Player::GetStat(Stats stat) const
{
	return mStats[stat];
}

const void Player::DisplayPlayer() const
{
	std::cout << "Player Name: " << mName << "\n";
	std::cout << "\tHealth: " << mStats[Health] << "\n";
	std::cout << "\tAttack: " << mStats[Attack] << "\n";
	std::cout << "\tDefense: " << mStats[Defense] << "\n";
	std::cout << "\tStamina: " << mStats[Stamina] << "\n";
	std::cout << "\tSpeed: " << mStats[Speed] << "\n\n";
}

const void Player::SetName(std::string name)
{
	mName = name;
}

const void Player::SetStat(Stats stat, int value)
{
	value = (value < 0) ? 0:value;
	mStats[stat] = value;
}