#pragma once

#include "CityA8.h"
#include "WeightedGraph.h"

class GPS
{
public:
	GPS();
	void AddCity(const std::string& name, const Vector2& position);
	void AddCitiesToMap();
	void ConnectCities(const CityA8& a, const CityA8& b);
	float FindPath(const CityA8& from, const CityA8& to, Vector<const CityA8*>& pathOutput);

private:
	Vector<CityA8> mCities;
	WeightedGraph<CityA8, float> mCityGraph;
};