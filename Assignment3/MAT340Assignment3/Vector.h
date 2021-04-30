#ifndef VECTOR_H
#define VECTOR_H

#include <vector>

#include "Matrix.h"

class Matrix;

class Vector
{
public:
	Vector(int size);

	int Size() const;
	
	double& operator[](unsigned int index);
	const double& operator[](unsigned int index) const;

	Vector operator*(const Matrix& matrix) const;
	Vector& operator=(const Vector& vector);

private:
	const int m_size;
	std::vector<double> m_vector;
};

#endif // !VECTOR_H