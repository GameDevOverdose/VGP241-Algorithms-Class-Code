#include "House.h"

House::House()
{

}

House::House(const std::string& name, const Vector2& position)
{
	mName = name;
	mPosition = position;
}

const std::string& House::GetName() const
{
	return mName;
}

const Vector2& House::GetPosition() const
{
	return mPosition;
}