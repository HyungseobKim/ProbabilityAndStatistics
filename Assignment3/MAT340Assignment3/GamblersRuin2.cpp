#include <iostream>

#include "GamblersRuin2.h"

#include "Vector.h"
#include "Matrix.h"

bool GamblersRuin2::Execute()
{
	while (true)
	{
		int a;
		std::cout << "\nStarting dollar amount $a: ";
		std::cin >> a;

		while (a < 0)
		{
			std::cout << "\nError! starting dollar must be greater or equal than 0\n";
			std::cin >> a;
		}

		int b;
		std::cout << "\nDesired winning dollar amount where to stop $b: ";
		std::cin >> b;

		while (b < a)
		{
			std::cout << "\nError! winning dollar must be greater or equal than a\n";
			std::cin >> b;
		}

		double p;
		std::cout << "\nProbability of winning each match, p: ";
		std::cin >> p;

		while (p < 0 || p > 1)
		{
			std::cout << "\nError! probability must be 0 <= p <= 1\n";
			std::cin >> p;
		}

		int n;
		std::cout << "\nNumber of matches to play n: ";
		std::cin >> n;

		while (n < 1)
		{
			std::cout << "\nError! Number of matches must be greater than 0\n";
			std::cin >> n;
		}

		Vector vector(b+1);
		vector[a] = 1.0;

		Matrix matrix(b+1);
		matrix[0][0] = 1.0;
		matrix[b][b] = 1.0;
		for (int i = 1; i < b; ++i)
		{
			auto& row = matrix[i];

			row[i - 1] = 1 - p;
			row[i + 1] = p;
		}

		Matrix matrix_at_n(matrix);
		for (int i = 0; i < n - 1; ++i)
			matrix_at_n *= matrix;

		vector = vector * matrix_at_n;
		std::cout << "\nResult: [";
		for (int i = 0; i < b; ++i)
			std::cout << vector[i] << ", ";

		std::cout << vector[b] << "]\n";

		const int selection = EndMenu();
		if (selection == 2)
			return true;
		else if (selection == 3)
			return false;
	}

	return false;
}