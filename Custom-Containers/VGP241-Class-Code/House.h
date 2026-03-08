#pragma once

#include <string>
#include "Vector2.h"

class House
{
public:
	House();
	House(const std::string& name, const Vector2& position);

	const std::string& GetName() const;
	const Vector2& GetPosition() const;

private:
	std::string mName;
	Vector2 mPosition;
};