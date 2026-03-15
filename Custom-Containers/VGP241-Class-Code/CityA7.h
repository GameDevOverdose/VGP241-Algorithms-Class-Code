#pragma once

#include <iostream>

#include "Vector.h"
#include "House.h"
#include "MSTGraph.h"
#include "MSTGraphK.h"

class CityA7
{
public:
	void AddHouse(const std::string& name, const Vector2& position);

	void ConnectAllHouses();

	float GetTotalRoadDistancePrim();
	float GetTotalRoadDistanceKruskal();

private:
	Vector<House> mHouses;
	MSTGraph<House, float> mHousesGraph;
	MSTGraphK<float> mHouseEdgesGraph;
};