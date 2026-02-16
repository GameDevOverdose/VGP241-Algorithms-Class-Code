#pragma once

#include <iostream>
#include <string>

class Texture
{
public:
	Texture();

	Texture(const std::string& filePath);

	~Texture();

	void Print();

	void Print(const int& x, const int& y);

private:
	std::string mFilePath;
};