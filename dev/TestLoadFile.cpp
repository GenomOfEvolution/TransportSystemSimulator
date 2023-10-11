#include "TestLoadFile.h"

struct WrapVector2i
{
	sf::Vector2i v;
};

struct WrapVector2iHasher
{
	bool operator()(const WrapVector2i& vec)const
	{
		return std::hash<int>()(vec.v.x) ^ std::hash<int>()(vec.v.y);
	}
};

bool operator==(const WrapVector2i& pt1, const WrapVector2i& pt2)
{
	return pt1.v.x == pt2.v.x && pt1.v.y == pt2.v.y;
}

std::unordered_map<WrapVector2i, std::string, WrapVector2iHasher> allChunks;

void RenderMap(bool stateLoadUpload)
{
	std::fstream file;
	file.open("DATA.txt");
	if (!file.is_open())
	{
		std::cout << "Can't open data file!\n";
		return;
	}

	if (stateLoadUpload)
	{
		while (!file.eof())
		{
			std::string line;
			std::getline(file, line, ' ');
			sf::Vector2i coords;
			coords.x = std::stoi(line);

			std::getline(file, line, ' ');
			coords.y = std::stoi(line);

			std::getline(file, line, '\n');
			
			allChunks.emplace(WrapVector2i{ coords }, line);
		}
	}
	else
	{

	}
}