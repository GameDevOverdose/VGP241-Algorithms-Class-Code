#include "CityA8.h"

CityA8::CityA8()
{

}

CityA8::CityA8(const std::string& name, const Vector2& position)
{
	mName = name;
	mPosition = position;
}

const std::string& CityA8::GetName() const
{
	return mName;
}

const Vector2& CityA8::GetPosition() const
{
	return mPosition;
}