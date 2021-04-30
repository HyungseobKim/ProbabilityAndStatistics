#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

#include "Vector.h"

class Vector;

class Matrix
{
public:
	Matrix(int size);

	int Size() const;

	Vector& operator[](unsigned int index);
	const Vector& operator[](unsigned int index) const;

	Matrix& operator*=(const Matrix& matrix);

private:
	const int m_size;
	std::vector<Vector> m_matrix;
};


#endif // !MATRIX_H

