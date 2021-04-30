#include <iostream>

#include "CouponCollector.h"

#include "RNG.h"

bool CouponCollector::Execute()
{
	int types;

	while(true)
	{
		std::cout << std::endl << "Total number of coupons types: ";
		std::cin >> types;

		bool* coupons = new bool[types];
		int result = 0;

		for (int i = 0; i < 1000; ++i)
		{
			for (int j = 0; j < types; ++j)
				coupons[j] = false;

			int remain = types;
			int collected = 0;

			while (remain > 0)
			{
				const int coupon = rng->GetRandomInt(0, types-1);

				if (!coupons[coupon])
				{
					coupons[coupon] = true;
					--remain;
				}

				++collected;
			}
			
			std::cout << collected << " coupons colleted. ";
			result += collected;
		}

		std::cout << std::endl;
		std::cout << "Average number of trials needed to complete a coupon set is: " << result << "/1000 = " << static_cast<double>(result) / 1000.0 << std::endl;
		std::cout << std::endl;

		const int selection = EndMenu();
		if (selection == 2)
			return true;
		else if (selection == 3)
			return false;
	}

	return false;
}