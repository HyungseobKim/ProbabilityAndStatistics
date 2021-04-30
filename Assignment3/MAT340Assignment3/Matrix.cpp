#include <cassert>

#include "Matrix.h"

Matrix::Matrix(int size)
	: m_size(size)
{
	for (int i = 0; i < size; ++i)
		m_matrix.push_back(Vector(size));
}

int Matrix::Size() const
{
	return m_size;
}

Vector& Matrix::operator[](unsigned int index)
{
	return m_matrix[index];
}

const Vector& Matrix::operator[](unsigned int index) const
{
	return m_matrix[index];
}

Matrix& Matrix::operator*=(const Matrix& matrix)
{
	assert(m_size == matrix.Size());

	for (int i = 0; i < m_size; ++i)
		m_matrix[i] = m_matrix[i] * matrix;

	return *this;
}