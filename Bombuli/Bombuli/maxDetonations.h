#pragma once

#include <unordered_set>

struct Bomb
{
	int x;
	int y;
	int radius;
};

bool isInsideBombRadius(const Bomb& bomb, int pointX, int pointY);
int countExplosions(std::vector<Bomb>& bombs, std::unordered_set<int>& visited, int bombIndex);
void findMaxExplosions(std::vector<Bomb>& bombs, int& maxExplosions, int& maxExplosionsBombIndex);