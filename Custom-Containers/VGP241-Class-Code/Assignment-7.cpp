#include "Assignment-7.h"
#include "City.h"

void PopulateCity(City& city)
{
	city.AddHouse("E", {30, 120});
	city.AddHouse("F", {100, 110});
	city.AddHouse("G", {150, 130});
	city.AddHouse("K", {200, 120});
	city.AddHouse("D", {60, 80});
	city.AddHouse("H", {160, 90});
	city.AddHouse("A", {20, 40});
	city.AddHouse("B", {50, 20});
	city.AddHouse("C", {90, 40});
	city.AddHouse("I", {140, 60});
	city.AddHouse("L", {220, 70});
	city.AddHouse("M", {240, 50});
	city.AddHouse("J", {180, 30});
}

void Assignment7()
{
	City city;

	PopulateCity(city);

	city.ConnectAllHouses();

	std::cout << "Prims:\n\n";

	float totalDistancePrims = city.GetTotalRoadDistancePrim();
	std::cout << "\nTotal Cost: " << totalDistancePrims * 10 << "$\n\n";

	std::cout << "Kruskal's:\n\n";

	float totalDistanceKruskal = city.GetTotalRoadDistanceKruskal();
	std::cout << "\nTotal Cost: " << totalDistanceKruskal * 10 << "$";

	std::cout << "\n\n";
}