#pragma once

#include "PlayerA6.h"
#include "Vector.h"
#include "Globals.h"

class Team
{
public:
	void Initialize(int numPlayers);

	PlayerA6* GetNextBattlingPlayer();

	void DamagePlayer(PlayerA6* player);

	int GetRemainingPlayers();

	void OrderPlayers();

	void StartTurn();
	void EndMatch();

	void PrintPlayerStats(int playerIndex);

	Vector<PlayerA6>& GetPlayers();

private:
	std::string mName;
	Vector<PlayerA6> mPlayers;
};