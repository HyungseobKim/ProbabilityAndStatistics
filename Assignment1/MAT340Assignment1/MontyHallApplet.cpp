#include <iostream>

#include "MontyHallApplet.h"

#include "RNG.h"

bool MontyHallApplet::Execute()
{
	while (true)
	{
		const int car = rng->GetRandomInt(1, 3);

		std::cout << std::endl << "Choose door [1, 2, 3]" << std::endl
			<< "Selection: ";

		int selection;
		std::cin >> selection;

		bool win = (car == selection);

		std::cout << std::endl << "Door ";
		if (win)
			std::cout << (car + rng->GetRandomInt(1, 2)) % 3;
		else
			std::cout << 6 - car - selection;
		std::cout << " opened." << std::endl;

		std::cout << "Would you switch?" << std::endl;
		
		while (true)
		{
			std::cout << "1. Stay" << std::endl
				<< "2. Switch" << std::endl
				<< "Selection: ";

			std::cin >> selection;

			if (selection == 1)
				break;
			else if (selection == 2)
			{
				win = !win;
				break;
			}

			std::cout << "Error! Please choose again." << std::endl << std::endl;
		}

		std::cout << std::endl;
		if (win)
			std::cout << "You win!";
		else
			std::cout << "You lose :(";
		std::cout << std::endl << std::endl;

		selection = EndMenu();
		if (selection == 2)
			return true;
		else if (selection == 3)
			return false;
	}

	return false;
}