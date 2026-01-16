#include <iostream>

#include "Array.h"
#include "Vector.h"

#include "Player.h"

void CustomContainersTest()
{
    Array <int, 5> myInts(0);

    std::cout << "Array:\n";
    for (std::size_t i = 0; i < myInts.Size(); ++i)
    {
        myInts[i] = i + 1;
        std::cout << "Value at " << i << " is: " << myInts[i] << "\n";
    }

    Vector <int> myVector;

    myVector.Reserve(10);

    std::cout << "\nVector:\n";
    for (std::size_t i = 0; i < 10; ++i)
    {
        myVector.PushBack(i + 1);
        std::cout << "Vector Value at " << i << " is: " << myVector[i] << "\n";
    }

    myVector.Resize(5);

    std::cout << "\nVector Resize:\n";
    for (std::size_t i = 0; i < myVector.Size(); ++i)
    {
        std::cout << "Vector Value at " << i << " is: " << myVector[i] << "\n";
    }
}

void PopulateNames(Vector <std::string>* names)
{
    names->PushBack("Arthur");
    names->PushBack("Lancelot");
    names->PushBack("Gawain");
    names->PushBack("Galahad");
    names->PushBack("Tristan");
    names->PushBack("Percival");
    names->PushBack("Bors");
    names->PushBack("Kay");
    names->PushBack("Bedivere");
    names->PushBack("Geraint");
    names->PushBack("Lamorak");
    names->PushBack("Pelleas");
    names->PushBack("Yvain");
    names->PushBack("Ector");
    names->PushBack("Uther");
    names->PushBack("Mordred");
    names->PushBack("Agravaine");
    names->PushBack("Gaheris");
    names->PushBack("Dagonet");
    names->PushBack("Lionel");
    names->PushBack("Palamedes");
	names->PushBack("Safir");
	names->PushBack("Segwarides");
	names->PushBack("Brunor");
	names->PushBack("Meliodas");
	names->PushBack("Morholt");
	names->PushBack("Elyan");
	names->PushBack("Lucan");
	names->PushBack("Dinadan");
	names->PushBack("Gareth");
	names->PushBack("Hector");
}

void AddPlayer(Vector <Player>* players, Vector <std::string>* names = nullptr)
{
    Player player;

    if (names != nullptr && names->Size() > 0)
    {
        player.SetName(names->operator[](names->Size() - 1));
        names->PopBack();
    }

    player.InitializePlayer();

    players->PushBack(player);
}

float DamageCalculation(Player attacker, Player defender)
{
    //PlayerA(Attack * Stamina) - PlayerB(Defense * Speed) / PlayerB(Health)

    float damage = (attacker.GetStat(Attack) * attacker.GetStat(Stamina)) - (defender.GetStat(Defense) * defender.GetStat(Speed));
    damage /= defender.GetStat(Health);

    return damage;
}

void Fight(Vector <Player> players)
{
    int playerOneIndex = rand() % players.Size();
    int playerTwoIndex = rand() % players.Size();

    while (playerTwoIndex == playerOneIndex)
    {
		playerTwoIndex = rand() % players.Size();
    }

    Player playerA = players[playerOneIndex];
    Player playerB = players[playerTwoIndex];

	 playerA.SetStat(Health, playerA.GetStat(Health) - DamageCalculation(playerA, playerB));
	 playerB.SetStat(Health, playerB.GetStat(Health) - DamageCalculation(playerB, playerA));

     if (playerA.GetStat(Health) > playerB.GetStat(Health))
     {
		 std::cout << playerA.GetName() << " wins against " << playerB.GetName() << "\n";
     }
     else if(playerB.GetStat(Health) > playerA.GetStat(Health))
     {
		 std::cout << playerB.GetName() << " wins against " << playerA.GetName() << "\n";
     }
     else
	 {
		 int toss = rand() % 2;

         if (toss == 0)
         {
             std::cout << playerA.GetName() << " wins against " << playerB.GetName() << " by coin toss\n";
         }
         else
         {
             std::cout << playerB.GetName() << " wins against " << playerA.GetName() << " by coin toss\n";
		 }
	 }
}

int main()
{
    Vector <Player> players;
	Vector <std::string> names;
    
	PopulateNames(&names);

	//Adding and Displaying 10 players
    for (int i = 0; i < 10; i++)
    {
        AddPlayer(&players, &names);
        players[i].DisplayPlayer();
    }
    
	//Removing 6 players
    for (int i = 0; i < 6; i++)
    {
		std::cout << "Removing " << players[players.Size() - 1].GetName() << "\n";
		players.PopBack();
    }

    std::cout << "\n";

    while (players.Size() < 20)
    {
        AddPlayer(&players, &names);
		std::cout << "Added " << players[players.Size()-1].GetName() << "\n";
    }

	Fight(players);
}