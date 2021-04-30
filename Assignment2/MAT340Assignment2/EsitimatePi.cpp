#include <iostream>

#include "EstimatePi.h"

#include "RNG.h"

bool EstimatePi::Execute()
{
	int N;

	while (true)
	{
		std::cout << "\nTotal number of points to plot: ";
		std::cin >> N;

		int insideCircle = 0;
		for (int i = 0; i < N; ++i)
		{
			const double x = rng->GetRandomDouble(-1, 1);
			const double y = rng->GetRandomDouble(-1, 1);

			if (x * x + y * y < 1)
				++insideCircle;
		}

		std::cout << "\nEstimated pi = " << static_cast<double>(insideCircle) / static_cast<double>(N) * 4.0 << std::endl;

		const int selection = EndMenu();
		if (selection == 2)
			return true;
		else if (selection == 3)
			return false;
	}

	return false;
}