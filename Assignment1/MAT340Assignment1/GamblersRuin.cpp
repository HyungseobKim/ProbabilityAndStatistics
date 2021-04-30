#include <iostream>

#include "GamblersRuin.h"

#include "RNG.h"

bool GamblersRuin::Execute()
{
	while (true)
	{
		std::cout << std::endl << "Starting dollar amount: ";

		int start;
		std::cin >> start;

		int end;
		while (true)
		{
			std::cout << "Desired winning dollar amount: ";
			std::cin >> end;

			if (end > start)
				break;

			std::cout << "Error! It must be bigger than starting dollar." << std::endl;
		}

		double p;
		while (true)
		{
			std::cout << "Probability of winning each match: ";
			std::cin >> p;

			if (p >= 0.f && p <= 1.f)
				break;

			std::cout << "Error! It must be between [0, 1]" << std::endl;
		}

		int win = 0;
		for (int i = 0; i < 10000; ++i)
		{
			int curr = start;
			while (curr != 0 && curr != end)
			{
				if (rng->GetRandomDouble(0.0, 1.0) <= p)
					++curr;
				else
					--curr;
			}

			if (curr == end)
			{
				std::cout << "Win! ";
				++win;
			}
			else
				std::cout << "Lose. ";
		}

		std::cout << std::endl << std::endl;
		std::cout << "Number of times the player won the game for the triple (" << start << ", " << end << ", " << p << "): "
			<< win << "/10000 = " << static_cast<double>(win) / 10000.0 << std::endl;
		std::cout << std::endl;

		const int selection = EndMenu();
		if (selection == 2)
			return true;
		else if (selection == 3)
			return false;
	}

	return false;
}