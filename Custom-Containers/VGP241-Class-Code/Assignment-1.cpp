#include "Assignment-1.h"

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

    player.InitializePlayer();

    if (names != nullptr && names->Size() > 0)
    {
        player.SetName(names->operator[](names->Size() - 1));
        names->PopBack();
    }

    players->PushBack(player);
}

float FightScoreCalculation(const Player& attacker, const Player& defender)
{
    //PlayerA(Attack * Stamina) - PlayerB(Defense * Speed) / PlayerB(Health) (Old Calc)

    /*float score = (attacker.GetStat(Attack) * attacker.GetStat(Stamina)) - (defender.GetStat(Defense) * defender.GetStat(Speed));
    score /= defender.GetStat(Health);*/

    //playerBHealth - ((playerADamage * playerAStamina) - (playerBDefense * playerBSpeed)) (New Calc)

    float score = defender.GetStat(Stats::Health) - ((attacker.GetStat(Stats::Attack) * attacker.GetStat(Stats::Stamina)) - (defender.GetStat(Stats::Defense) * defender.GetStat(Stats::Speed)));

    return score;
}

void Fight(Vector <Player>* players)
{
    int playerOneIndex = rand() % players->Size();
    int playerTwoIndex = rand() % players->Size();

    while (playerTwoIndex == playerOneIndex)
    {
        playerTwoIndex = rand() % players->Size();
    }

    Player playerA = players->operator[](playerOneIndex);
    Player playerB = players->operator[](playerTwoIndex);

    float playerAScore = FightScoreCalculation(playerA, playerB);
    float playerBScore = FightScoreCalculation(playerB, playerA);

    if (playerAScore > playerBScore)
    {
        std::cout << playerA.GetName() << " wins against " << playerB.GetName() << "\n";
    }
    else if (playerBScore > playerAScore)
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

void Assignment1()
{
    Vector <Player> players;
    Vector <std::string> names;

    PopulateNames(&names);

    int playersToAdd = 10;
    int totalPlayersToAdd = 20;
    int playersToRemove = 6;

    //Adding and Displaying 10 players
    for (int i = 0; i < playersToAdd; i++)
    {
        AddPlayer(&players, &names);
        players[i].DisplayPlayer();
    }

    std::cout << "Removing: ";

    //Removing 6 players
    for (int i = 0; i < playersToRemove; i++)
    {
        i != playersToRemove - 1 ? std::cout << players[players.Size() - 1].GetName() << ", " : std::cout << players[players.Size() - 1].GetName() << "\n\n";
        players.PopBack();
    }

    //Adding until we have 20 players
    while (players.Size() < totalPlayersToAdd)
    {
        AddPlayer(&players, &names);
        std::cout << "Added " << players[players.Size() - 1].GetName() << "\n";
    }

    std::cout << "\n";

    Fight(&players);
}