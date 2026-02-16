#include <Windows.h>
#include <Vector>
#include "Texture.h"

Texture::Texture()
{

}

Texture::Texture(const std::string& filePath)
	: mFilePath(filePath)
{

}

Texture::~Texture()
{

}

void Texture::Print()
{
	//std::cout << "Rendering " << mFilePath;
	std::cout << mFilePath;
}

// Was trying to get the entities printed at their positions, but it wasn't working as intended (Plus can't show sorting that way)
void Texture::Print(const int& x, const int& y)
{
	std::vector<std::string> textureLines;
	std::string delimiter = "\n";

	size_t pos = 0;

	while ((pos = mFilePath.find(delimiter)) != std::string::npos)
	{
		textureLines.push_back(mFilePath.substr(0, pos));
		mFilePath.erase(0, pos + delimiter.length());
	}

	textureLines.push_back(mFilePath);

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD position;

	for (int i = 0; i < textureLines.size(); ++i)
	{
		position.X = x;
		position.Y = y + i;

		SetConsoleCursorPosition(hConsole, position);

		std::cout << textureLines[i];
	}
}