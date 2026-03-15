#include "CityA7.h"

void CityA7::AddHouse(const std::string& name, const Vector2& position)
{
	for (int i = 0; i < mHouses.Size(); ++i)
	{
		if (mHouses[i].GetName() == name && mHouses[i].GetPosition() == position)
		{
			return;
		}
	}

	mHouses.PushBack({ name, position });
	mHousesGraph.AddItem(&mHouses[mHouses.Size() - 1]);
}

void CityA7::ConnectAllHouses()
{
	for (std::size_t i = 0; i < mHouses.Size() - 1; ++i)
	{
		for (std::size_t j = i + 1; j < mHouses.Size(); ++j)
		{
			float distance = mHouses[i].GetPosition().Distance(mHouses[j].GetPosition());

			mHousesGraph.AddEdge(i, j, distance);
			mHouseEdgesGraph.AddEdge(i, j, distance);
		}
	}

	mHousesGraph.GenerateMST(0);
	mHouseEdgesGraph.GenerateMST();
}

float CityA7::GetTotalRoadDistancePrim()
{
	const Vector<MSTGraph<House, float>::Edge>& mstEdges = mHousesGraph.GetMST();
	float totalWeight = 0;

	std::cout << "Links: ";

	for (std::size_t i = 0; i < mstEdges.Size(); ++i)
	{
		std::cout << mHouses[mstEdges[i].fromIndex].GetName() << "-" << mHouses[mstEdges[i].toIndex].GetName() << " ";
		totalWeight += mstEdges[i].weight;
	}

	return totalWeight;
}

float CityA7::GetTotalRoadDistanceKruskal()
{
	const Vector<MSTGraphK<float>::Edge> mstEdgesK = mHouseEdgesGraph.GetMST();
	float totalWeight = 0;

	std::cout << "Links: ";

	for (std::size_t i = 0; i < mstEdgesK.Size(); ++i)
	{
		std::cout << mHouses[mstEdgesK[i].fromNode].GetName() << "-" << mHouses[mstEdgesK[i].toNode].GetName() << " ";
		totalWeight += mstEdgesK[i].weight;
	}

	return totalWeight;
}