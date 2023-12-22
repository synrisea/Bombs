#include <vector>
#include <string>
#include <fstream>
#include <iostream>

struct Bomb
{
	int x;
	int y;
	int radius;
};

std::vector<std::string> line;


int getFromFile(const std::string& filename, std::vector<Bomb>& bombsArr)
{
	std::ifstream bombs(filename);

	if (bombs.is_open())
	{
		std::string tempStr;

		for (int i = 0; getline(bombs, tempStr); i++)
		{
			line.push_back(tempStr);
		}
	}

	bombs.close();

	Bomb b;
	std::string tmpStr;

	for (int i = 0; i != line.size(); i++)
	{
		int counter = 0;

		for (int j = 0; j != line[i].size(); j++)
		{
			if (line[i][j] <= '9' && line[i][j] >= '0')
			{
				tmpStr.push_back(line[i][j]);
			}
			else
			{
				try
				{
					if (tmpStr.empty())
					{
						throw std::range_error("");
					}
				}

				catch (std::range_error)
				{
					std::cout << "\n\n----Invalid Input----\n\n";
					return 1;
				}

				if (counter == 0)
				{
					b.x = stoi(tmpStr);
				}
				else if (counter == 1)
				{
					b.y = stoi(tmpStr);
				}
				else if (counter == 2)
				{
					b.radius = stoi(tmpStr);
				}
				else
				{
					break;
				}

				tmpStr.clear();
				counter++;
			}
		}
		try
		{
			if (counter != 2)
			{
				throw std::range_error("");
			}
		}

		catch (std::range_error)
		{
			std::cout << "\n\n----Invalid Input----\n\n";
			return 1;
		}

		bombsArr.push_back(b);
	}
	return 0;
}