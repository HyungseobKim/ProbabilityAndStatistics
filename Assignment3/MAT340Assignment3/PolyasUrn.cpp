#include <iostream>
#include <vector>
#include <numeric>

#include "PolyasUrn.h"

#include "RNG.h"

bool PolyasUrn::Execute()
{
	while (true)
	{
		int x;
		std::cout << "\nStarting number of green balls x: ";
		std::cin >> x;

		while (x < 1)
		{
			std::cout << "\nError! number of green balls must be greater than 0\n";
			std::cin >> x;
		}

		int y;
		std::cout << "\nStarting number of orange balls y: ";
		std::cin >> y;

		while (y < 1)
		{
			std::cout << "\nError! number of ogrange balls must be greater than 0\n";
			std::cin >> y;
		}

		std::vector<int> distribution(20, 0);

		for (int i = 0; i < 3000; ++i)
		{
			int green = x;
			int orange = y;

			for (int j = 0; j < 1000; ++j)
			{
				if (rng->GetRandomInt(0, green + orange - 1) < green)
					++green;
				else
					++orange;
			}

			++distribution[20 * green / (green + orange)];
		}

		const double total = std::accumulate(distribution.begin(), distribution.end(), 0);

		std::cout << "Probability dirstribution for the fraction of green balls: [";
		for (int i = 0; i < 19; ++i)
			std::cout << distribution[i] / total << ", ";
		std::cout << distribution[19] / total << "]\n\n";

		const int selection = EndMenu();
		if (selection == 2)
			return true;
		else if (selection == 3)
			return false;
	}

	return false;
}