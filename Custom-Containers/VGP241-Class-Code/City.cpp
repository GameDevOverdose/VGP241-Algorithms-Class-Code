#include "City.h"

void City::AddHouse(const std::string& name, const Vector2& position)
{
	for (int i = 0; i < mHouses.Size(); ++i)
	{
		// duplicating because can't make a version of == operator where the lhs is const
		Vector2 housePosition = mHouses[i].GetPosition();

		if (mHouses[i].GetName() == name && housePosition == position)
		{
			return;
		}
	}

	mHouses.PushBack({ name, position });
	mHousesGraph.AddItem(&mHouses[mHouses.Size() - 1]);
}

void City::ConnectAllHouses()
{
	for (std::size_t i = 0; i < mHouses.Size(); ++i)
	{
		for (std::size_t j = 0; j < mHouses.Size(); ++j)
		{
			if (i != j)
			{
				float distance = mHouses[i].GetPosition().Distance(mHouses[j].GetPosition());

				mHousesGraph.AddEdge(i, j, distance);
				mHouseEdgesGraph.AddEdge(i, j, distance);
			}
		}
	}

	mHousesGraph.GenerateMST(0);
	mHouseEdgesGraph.GenerateMST();
}

float City::GetTotalRoadDistancePrim()
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

float City::GetTotalRoadDistanceKruskal()
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