#include <iostream>

#include "AbsorptionTimes.h"

#include "RNG.h"

bool AbsorptionTimes::Execute()
{
	while (true)
	{
		int n;
		std::cout << "\nDesired number of consecutive heads n: ";
		std::cin >> n;

		while (n < 1)
		{
			std::cout << "\nError! number of consecutive heads must be greater than 0\n";
			std::cin >> n;
		}

		long int flips = 0;

		for (int i = 0; i < 3000; ++i)
		{
			for (int consecutive = 0; consecutive < n; ++flips)
			{
				if (rng->GetRandomInt(0, 1))
					++consecutive;
				else
					consecutive = 0;
			}
		}

		std::cout << "Estimated number of flips: " << flips / 3000.0 << std::endl << std::endl;

		const int selection = EndMenu();
		if (selection == 2)
			return true;
		else if (selection == 3)
			return false;
	}

	return false;
}