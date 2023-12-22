#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include "maxDetonations.h"
#include "getBombs.h"
#include <gtest/gtest.h>

//
//TEST(BombTest, Test1)
//{
//	std::string bomb1 = "bombs.txt";
//	std::vector<Bomb> bombsArr;
//
//	getFromFile(bomb1,bombsArr);
//
//	int maxExplosions;
//	int maxExplosionsBombIndex;
//
//	findMaxExplosions(bombsArr, maxExplosions, maxExplosionsBombIndex);
//
//	ASSERT_EQ(4, maxExplosions);
//	ASSERT_EQ(0, maxExplosionsBombIndex);
//}
//
//int main(int argc, char** argv)
//{
//	testing::InitGoogleTest(&argc, argv);
//	return RUN_ALL_TESTS();
//}

int main()
{
	std::vector<Bomb> bombsArr;

	getFromFile("bombs.txt", bombsArr);

	int max, maxIndex;

	findMaxExplosions(bombsArr, max, maxIndex);

	std::cout << max << " " << maxIndex;
}