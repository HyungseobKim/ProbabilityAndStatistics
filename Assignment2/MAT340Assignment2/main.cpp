#include <iostream>

#include "EstimatePi.h"
#include "ConfidenceIntervals.h"
#include "Correlation.h"

int main()
{
	Problem* problems[4];

	EstimatePi pi;
	ConfidenceIntervals ci;
	Correlation cr;

	problems[0] = &pi;
	problems[1] = &ci;
	problems[2] = &cr;

	std::cout << "Name: Hyungseob Kim" << std::endl
		<< "Course: MAT 340" << std::endl
		<< "Semester: Spring 2021" << std::endl << std::endl;

	while (true)
	{
		int selection;

		while (true)
		{
			std::cout << "1. Estimate Pi" << std::endl
				<< "2. Confidence Intervals" << std::endl
				<< "3. Correlation" << std::endl
				<< "4. Quit program." << std::endl
				<< "Selection: ";

			std::cin >> selection;

			if (selection >= 1 && selection <= 3)
				break;
			else if (selection == 4)
				return 0;

			std::cout << "Error! Please choose again." << std::endl << std::endl;
		}

		if (problems[selection - 1]->Execute() == false)
			return 0;

		std::cout << std::endl;
	}

	return 0;
}