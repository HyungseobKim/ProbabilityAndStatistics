#include <iostream>
#include <cmath>

#include "ConfidenceIntervals.h"

#include "RNG.h"

bool ConfidenceIntervals::Execute()
{
	while (true)
	{
		double p;
		std::cout << "\nThe probability of success in a Bernoulli trial: ";
		std::cin >> p;

		while (p < 0.0 || p > 1.0)
		{
			std::cout << "\nError! probability must be [0, 1]";
			std::cin >> p;
		}

		const double standard_deviation = std::sqrt(p * (1 - p)) / 100.0;
		const double min = p - 2 * standard_deviation;
		const double max = p + 2 * standard_deviation;

		int insideInterval = 0;
		for (int i = 0; i < 100; ++i)
		{
			double success = 0;
			for (int j = 0; j < 10000; ++j)
			{
				if (rng->GetRandomDouble(0, 1) <= p)
					++success;
			}

			const double proportion = success / 10000.0;
			if (proportion >= min && proportion <= max)
			{
				++insideInterval;
				std::cout << "Success! ";
			}
			else
				std::cout << "Fail. ";
		}

		std::cout << "\nThe number of times p was in the 95% confidence interval: " << insideInterval << std::endl;

		const int selection = EndMenu();
		if (selection == 2)
			return true;
		else if (selection == 3)
			return false;
	}

	return false;
}