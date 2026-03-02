#include "Assignment-6.h"
#include "Team.h"

void PrintStats(Team& teamA, Team& teamB, int playerAmount)
{
	Vector<PlayerA6> teamAPlayers = teamA.GetPlayers();
	Vector<PlayerA6> teamBPlayers = teamB.GetPlayers();

	std::cout << "---------------------------------------------------------------------------------------\n";

	for (int i = 0; i < playerAmount; ++i)
	{
		std::cout << std::right << std::setw(8) << teamAPlayers[i].GetName() << "| ";
		teamA.PrintPlayerStats(i);

		std::cout << std::right << std::setw(10) << teamBPlayers[i].GetName() << "| ";
		teamB.PrintPlayerStats(i);

		std::cout << "\n";
	}

	std::cout << "---------------------------------------------------------------------------------------\n";
}

void PopulateNames(Vector<std::string>& names)
{
	names.PushBack("Blaze");
	names.PushBack("Shadow");
	names.PushBack("Viper");
	names.PushBack("Titan");
	names.PushBack("Rogue");
	names.PushBack("Phantom");
	names.PushBack("Crusher");
	names.PushBack("Fury");
	names.PushBack("Havoc");
	names.PushBack("Reaper");
	names.PushBack("Storm");
	names.PushBack("Venom");
	names.PushBack("Raptor");
	names.PushBack("Inferno");
	names.PushBack("Ghost");
	names.PushBack("Onyx");
	names.PushBack("Nova");
	names.PushBack("Blitz");
	names.PushBack("Drake");
	names.PushBack("Wolf");
}


void PopulateNamesA(Vector<std::string>& names)
{
	names.Clear();

	names.PushBack("A");
	names.PushBack("B");
	names.PushBack("C");
	names.PushBack("D");
	names.PushBack("E");
	names.PushBack("F");
	names.PushBack("G");
	names.PushBack("H");
	names.PushBack("I");
	names.PushBack("J");
}


void PopulateNamesB(Vector<std::string>& names)
{
	names.Clear();

	names.PushBack("1");
	names.PushBack("2");
	names.PushBack("3");
	names.PushBack("4");
	names.PushBack("5");
	names.PushBack("6");
	names.PushBack("7");
	names.PushBack("8");
	names.PushBack("9");
	names.PushBack("10");
}

std::string GetRandomName(Vector<std::string>& names)
{
	//int randIndex = rand() % names.Size();
	std::string name = names[names.Size() - 1];
	names.PopBack();

	return name;
}

void Assignment6()
{
	Vector<std::string> playerNames;

	Team teamA;
	Team teamB;

	std::string input;

	const int playerAmount = 10;

	teamA.Initialize(playerAmount);
	teamB.Initialize(playerAmount);

	PopulateNamesA(playerNames);
	for (int i = 0; i < playerAmount; i++)
	{
		teamA.GetPlayers()[i].SetName(GetRandomName(playerNames));
	}

	PopulateNamesB(playerNames);
	for (int i = 0; i < playerAmount; i++)
	{
		teamB.GetPlayers()[i].SetName(GetRandomName(playerNames));
	}

	while (teamA.GetRemainingPlayers() != 0 && teamB.GetRemainingPlayers() != 0)
	{
		// if you want to print before the turn
		PrintStats(teamA, teamB, playerAmount);

		teamA.StartTurn();
		teamB.StartTurn();

		for (int i = 0; i < playerAmount; i++)
		{
			teamB.DamagePlayer(teamA.GetNextBattlingPlayer());
			teamA.DamagePlayer(teamB.GetNextBattlingPlayer());

			teamA.OrderPlayers();
			teamB.OrderPlayers();
		}

		// if you want to print after the turn
		//std::cout << "\n\n";
		//PrintStats(teamA, teamB, playerAmount);

		std::cout << "\n\n------------";
		std::cout << "\nContinue: ";
		std::cin >> input;
		system("cls");
	}

	if (teamA.GetRemainingPlayers() != 0)
	{
		std::cout << "\n\t\tTeam A Wins!\n";
	}
	else if (teamB.GetRemainingPlayers() != 0)
	{
		std::cout << "\t\t\t\t\t\t\tTeam B Wins!\n";
	}

	PrintStats(teamA, teamB, playerAmount);
}