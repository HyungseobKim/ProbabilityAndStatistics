#include <iostream>

#include "MontyHallSimulation.h"

#include "RNG.h"

bool MontyHallSimulation::Execute()
{
	while (true)
	{
		std::cout << std::endl << "Total number of doors: ";

		int n;
		std::cin >> n;

		int c;
		while (true)
		{
			std::cout << "Total number of cars [1, n-2]: ";
			std::cin >> c;

			if (c >= 1 && c <= n - 2)
				break;
			
			std::cout << "Error! Please choose again." << std::endl;
		}

		int closed;
		while (true)
		{
			std::cout << "Number of doors to be opened [1, n-c-1]: ";
			std::cin >> closed;

			if (closed >= 1 && closed <= n - c - 1)
				break;

			std::cout << "Error! Please choose again." << std::endl;
		}
		closed = n - closed;

		int win = 0;
		for (int i = 0; i < 1000; ++i)
		{
			int player = rng->GetRandomInt(1, n);

			if (player <= c)
				player = rng->GetRandomInt(2, closed);
			else
				player = rng->GetRandomInt(1, closed - 1);

			if (player <= c)
			{
				std::cout << "Win! ";
				++win;
			}
			else
				std::cout << "Lose. ";
		}

		std::cout << std::endl << std::endl;
		std::cout << "Probability that the player wins the car for the triple (" << n << ", " << c << ", " << n - closed << "): "
			<< win << "/1000 = " << static_cast<double>(win) / 1000.0 << std::endl;
		std::cout << std::endl;

		const int selection = EndMenu();
		if (selection == 2)
			return true;
		else if (selection == 3)
			return false;
	}

	return false;
}