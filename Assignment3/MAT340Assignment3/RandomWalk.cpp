#include <iostream>
#include <vector>
#include <algorithm>

#include "RandomWalk.h"

#include "RNG.h"

bool RandomWalk::Execute()
{
	while (true)
	{
		int d;
		std::cout << "\nDimension d: ";
		std::cin >> d;

		while (d < 1)
		{
			std::cout << "\nError! dimension must be greater than 0\n";
			std::cin >> d;
		}

		int n;
		std::cout << "\nNumber of steps n: ";
		std::cin >> n;

		while (n < 100)
		{
			std::cout << "\nError! number of steps must be greater or equl than 100\n";
			std::cin >> n;
		}

		double average = 0;
		const int max = (2 * d) - 1;

		for (int i = 0; i < 3000; ++i)
		{
			std::vector<double> position(d, 0);

			for (int j = 0; j < n; ++j)
			{
				const int rand = rng->GetRandomInt(0, max);
				if (rand % 2)
					++position[rand / 2];
				else
					--position[rand / 2];
			}

			double distance = 0;
			std::for_each(position.begin(), position.end(), [&](const double& value) {
				distance += value * value;
			});
			average += sqrt(distance);
		}

		std::cout << "\nEstimated distance: " << average/3000.0 << std::endl << std::endl;

		const int selection = EndMenu();
		if (selection == 2)
			return true;
		else if (selection == 3)
			return false;
	}

	return false;
}