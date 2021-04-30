#include <iostream>

#include "Problem.h"

#include "RNG.h"

Problem::Problem()
	: rng(RNG::GetInstance())
{
}

int Problem::EndMenu() const
{
	while (true)
	{
		std::cout << "1. Try again" << std::endl
			<< "2. Back to main menu" << std::endl
			<< "3. Quit program" << std::endl
			<< "Selection: ";

		int selection;
		std::cin >> selection;

		if (selection > 0 && selection <= 3)
			return selection;

		std::cout << std::endl << "Error! Please choose again." << std::endl << std::endl;
	}

	return 0;
}