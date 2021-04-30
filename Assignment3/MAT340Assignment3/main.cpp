#include <iostream>

#include "GamblersRuin2.h"
#include "AbsorptionTimes.h"
#include "PolyasUrn.h"
#include "RandomWalk.h"

int main()
{
	Problem* problems[4];

	GamblersRuin2 g;
	AbsorptionTimes a;
	PolyasUrn p;
	RandomWalk r;

	problems[0] = &g;
	problems[1] = &a;
	problems[2] = &p;
	problems[3] = &r;

	std::cout << "Name: Hyungseob Kim" << std::endl
		<< "Course: MAT 340" << std::endl
		<< "Semester: Spring 2021" << std::endl << std::endl;

	while (true)
	{
		int selection;

		while (true)
		{
			std::cout << "1. Gambler's Ruin 2" << std::endl
				<< "2. Absorption Times" << std::endl
				<< "3. Polya's Urn" << std::endl
				<< "4. Random Walk" << std::endl
				<< "5. Quit program." << std::endl
				<< "Selection: ";

			std::cin >> selection;

			if (selection >= 1 && selection <= 4)
				break;
			else if (selection == 5)
				return 0;

			std::cout << "Error! Please choose again." << std::endl << std::endl;
		}

		if (problems[selection - 1]->Execute() == false)
			return 0;

		std::cout << std::endl;
	}

	return 0;
}