#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Correlation.h"

bool Correlation::Execute()
{
	std::ifstream file("Data.txt", std::ifstream::in);
	if (file.is_open() == false)
	{
		std::cout << "\nThere must be file name Data.txt\n";
		return true;
	}
	
	double value;
	std::vector<std::vector<double>> data(4);

	double total[4] = {0,0,0,0};
	double standard_deviation[4] = {0,0,0,0};

	std::vector<std::string> names(4);
	for (int i = 0; i < 4; ++i)
		file >> names[i];

	while (!file.eof())
	{
		for (int i = 0; i < 4; ++i)
		{
			file >> value;

			total[i] += value;
			standard_deviation[i] += value * value;
			data[i].push_back(value);
		}
	}

	const double size = data[0].size();

	double mean[4];
	for (int i = 0; i < 4; ++i)
		mean[i] = total[i] / size;

	for (int i = 0; i < 4; ++i)
		standard_deviation[i] = std::sqrt(standard_deviation[i]/size - mean[i]*mean[i]);

	double numerator[3] = {0,0,0};
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < 3; ++j)
			numerator[j] += (data[j][i] - mean[j]) * (data[3][i] - mean[3]);
	}

	std::ofstream result("Result.txt");
	result << "Name: Hyungseob Kim\n\n";
	
	result << "Mean\n";
	result << names[0] << ": " << mean[0] << std::endl;
	result << names[1] << ": " << mean[1] << std::endl;
	result << names[2] << ": " << mean[2] << std::endl;
	result << names[3] << ": " << mean[3] << std::endl << std::endl;

	result << "Standard Deviation\n";
	result << names[0] << ": " << standard_deviation[0] << std::endl;
	result << names[1] << ": " << standard_deviation[1] << std::endl;
	result << names[2] << ": " << standard_deviation[2] << std::endl;
	result << names[3] << ": " << standard_deviation[3] << std::endl << std::endl;

	result << "Correlation Coefficient\n";
	result << "(" << names[0] << ", " << names[3] << "): " << numerator[0]/((size - 1) * standard_deviation[0] * standard_deviation[3]) << std::endl;
	result << "(" << names[1] << ", " << names[3] << "): " << numerator[1] / ((size - 1) * standard_deviation[1] * standard_deviation[3]) << std::endl;
	result << "(" << names[2] << ", " << names[3] << "): " << numerator[2] / ((size - 1) * standard_deviation[2] * standard_deviation[3]) << std::endl;

	std::cout << "\nResult is saved on file Result.txt\n\n";

	return true;
}