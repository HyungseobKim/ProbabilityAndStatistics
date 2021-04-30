#include <cassert>
#include "Vector.h"

Vector::Vector(int size)
	: m_size(size), m_vector(std::vector<double>(size, 0))
{}

int Vector::Size() const
{
	return m_size;
}

double& Vector::operator[](unsigned int index)
{
	return m_vector[index];
}

const double& Vector::operator[](unsigned int index) const
{
	return m_vector[index];
}

Vector Vector::operator*(const Matrix& matrix) const
{
	assert(m_size == matrix.Size());

	Vector result(m_size);

	for (int i = 0; i < m_size; ++i)
	{
		const auto& curr = m_vector[i];
		const auto& row = matrix[i];

		for (int j = 0; j < m_size; ++j)
			result[j] += (curr * row[j]);
	}

	return result;
}

Vector& Vector::operator=(const Vector& vector)
{
	assert(m_size == vector.m_size);

	m_vector = vector.m_vector;
	return *this;
}