#include "Matrix.h"

const size_t DEFAULT_ROW_SIZE = 2;
const size_t DEFAULT_COLUMN_SIZE = 2;
const int DEFAULT_VALUE = 0;

void Matrix::CopyMemberData(const Matrix& matrix)
{
	_rowSize = matrix._rowSize;
	_columnSize = matrix._columnSize;

	container = new int* [_rowSize];

	for (size_t row = 0; row < _rowSize; row++)
	{
		container[row] = new int[_columnSize];
		for (size_t column = 0; column < _columnSize; column++)
			container[row][column] = matrix[row][column];
	}	
}

void Matrix::FreeMemberData()
{
	for (size_t i = 0; i < _rowSize; i++)
		delete[] container[i];
	delete[] container;
	container = nullptr;
	_rowSize = _columnSize = 0;
}
	
Matrix::Matrix():Matrix(DEFAULT_ROW_SIZE, DEFAULT_COLUMN_SIZE) { }

Matrix::Matrix(size_t rowSize, size_t columnSize)
{
	_rowSize = rowSize;
	_columnSize = columnSize;

	container = new int* [rowSize];	
	for (size_t row = 0; row < _rowSize; row++)
	{
		container[row] = new int[_columnSize];
		for (size_t column = 0; column < _columnSize; column++)
			container[row][column] = DEFAULT_VALUE;
	}
}

Matrix::Matrix(int array[], size_t rows, size_t columns) : Matrix(rows, columns)
{
	for (size_t row = 0; row < _rowSize; row++)
		for (size_t column = 0; column < _columnSize; column++)
			container[row][column] = array[row * rows + column];
}

Matrix::Matrix(const Matrix& copy)
{
	CopyMemberData(copy);
}

Matrix& Matrix::operator=(const Matrix& matrix)
{
	if ( *this != matrix)
	{
		FreeMemberData();
		CopyMemberData(matrix);
	}
	return *this;
}

Matrix& Matrix::operator+=(const Matrix& matrix)
{
	for (size_t row = 0; row < _rowSize; row++)
		for (size_t column = 0; column < _columnSize; column++)
			container[row][column] += matrix[row][column];
	return *this;
}

Matrix& Matrix::operator-=(const Matrix& matrix)
{
	for (size_t row = 0; row < _rowSize; row++)
		for (size_t column = 0; column < _columnSize; column++)
			container[row][column] -= matrix[row][column];
	return *this;
}

Matrix& Matrix::operator*=(int scalar)
{
	for (size_t row = 0; row < _rowSize; row++)
		for (size_t column = 0; column < _columnSize; column++)
			container[row][column] *= scalar;
	return *this;
}

Matrix& Matrix::operator*=(const Matrix& matrix)
{
	if (_columnSize != matrix._rowSize)
		return *this;
	Matrix result(_rowSize, matrix._columnSize);
	for (size_t row = 0; row < result._rowSize; row++)
		for (size_t column = 0; column < result._columnSize; column++)
		{
			int sum = 0;
			for (size_t index = 0; index < _columnSize; index++)
				sum += container[row][index] * matrix.container[index][column];
			result[row][column] = sum;
		}
	*this = result;
	return *this;
}

Matrix operator+(const Matrix& lhs, const Matrix& rhs)
{
	Matrix copy(lhs);
	return copy += rhs;
}

Matrix operator-(const Matrix& lhs, const Matrix& rhs)
{
	Matrix copy(lhs);
	return copy -= rhs;
}

Matrix operator*(const Matrix& lhs, int scalar)
{
	Matrix copy(lhs);
	return copy *= scalar;
}

Matrix operator*(int scalar, const Matrix& rhs)
{
	Matrix copy(rhs);
	return copy *= scalar;
}

Matrix operator*(const Matrix& lhs, const Matrix& rhs)
{
	Matrix copy(lhs);
	return copy *= rhs;
}

bool operator==(const Matrix& lhs, const Matrix& rhs)
{
	if (lhs._rowSize != rhs._rowSize || lhs._columnSize != rhs._columnSize)
		return false;
	for (size_t row = 0; row < lhs._rowSize; row++)
		for (size_t column = 0; column < lhs._columnSize; column++)
			if (lhs.container[row][column] != rhs.container[row][column])
				return false;
	return true;
}

bool operator!=(const Matrix& lhs, const Matrix& rhs)
{
	return !(lhs == rhs);
}

const int* Matrix::operator[](int index) const
{
	return container[index];
}

int* Matrix::operator[](int index)
{
	return container[index];
}

std::ostream& operator<<(std::ostream& stream, const Matrix& matrix)
{
	for (size_t row = 0; row < matrix._rowSize; row++)
	{
		stream << "| ";
		for (size_t column = 0; column < matrix._columnSize; column++)
			stream << matrix[row][column] << " | ";
		stream << std::endl;
	}
	return stream;
}

Matrix::~Matrix()
{
	FreeMemberData();
}