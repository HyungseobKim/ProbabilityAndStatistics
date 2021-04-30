#include <iostream>

#include "CouponCollector.h"
#include "MontyHallApplet.h"
#include "MontyHallSimulation.h"
#include "GamblersRuin.h"

int main()
{
	Problem* problems[4];

	CouponCollector c;
	MontyHallApplet m_a;
	MontyHallSimulation m_s;
	GamblersRuin g;

	problems[0] = &c;
	problems[1] = &m_a;
	problems[2] = &m_s;
	problems[3] = &g;

	std::cout << "Name: Hyungseob Kim" << std::endl
		<< "Course: MAT 340" << std::endl
		<< "Semester: Spring 2021" << std::endl << std::endl;

	while (true)
	{
		int selection;

		while (true)
		{
			std::cout << "1. Coupon Collector Problem" << std::endl
				<< "2. Montey Hall Problem Applet" << std::endl
				<< "3. Mony Hall Problem Simulation" << std::endl
				<< "4. Gambler's Ruin Problem" << std::endl
				<< "5. Quit program" << std::endl
				<< "Selection: ";

			std::cin >> selection;

			if (selection > 0 && selection <= 4)
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