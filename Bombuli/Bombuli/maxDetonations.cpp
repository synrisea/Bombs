#include <vector>
#include <unordered_set>

struct Bomb
{
	int x;
	int y;
	int radius;
};

bool isInsideBombRadius(const Bomb& bomb, int pointX, int pointY)
{
	int distanceSquared = (pointX - bomb.x) * (pointX - bomb.x) + (pointY - bomb.y) * (pointY - bomb.y);
	int radiusSquared = bomb.radius * bomb.radius;

	return distanceSquared <= radiusSquared;
}

int countExplosions(std::vector<Bomb>& bombs, std::unordered_set<int>& visited, int bombIndex)
{
	visited.insert(bombIndex);
	int explosions = 1;

	for (int i = 0; i < bombs.size(); ++i)
	{
		if (i != bombIndex && visited.find(i) == visited.end() && isInsideBombRadius(bombs[bombIndex], bombs[i].x, bombs[i].y))
		{
			explosions += countExplosions(bombs, visited, i);
		}
	}

	return explosions;
}

void findMaxExplosions(std::vector<Bomb>& bombs, int& maxExplosions, int& maxExplosionsBombIndex)
{
	maxExplosions = 0;
	maxExplosionsBombIndex = -1;

	for (int i = 0; i < bombs.size(); ++i)
	{
		std::unordered_set<int> visited;
		int explosions = countExplosions(bombs, visited, i);

		if (explosions > maxExplosions)
		{
			maxExplosions = explosions;
			maxExplosionsBombIndex = i;
		}
	}
}