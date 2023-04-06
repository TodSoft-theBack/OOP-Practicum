#pragma once
#include <iostream>

class Matrix
{
	private:
		int** container;
		size_t _rowSize;
		size_t _columnSize;
		void CopyMemberData(const Matrix& matrix);
		void FreeMemberData();
	public:
		Matrix();
		Matrix(size_t rowSize, size_t columnSize);
		Matrix(const Matrix& copy);
		Matrix(int array[], size_t rows, size_t columns);
		Matrix& operator=(const Matrix& matrix);
		Matrix& operator+=(const Matrix& matrix);
		Matrix& operator-=(const Matrix& matrix);
		Matrix& operator*=(int scalar);
		Matrix& operator*=(const Matrix& matrix);

		friend Matrix operator+(const Matrix& lhs, const Matrix& rhs);
		friend Matrix operator-(const Matrix& lhs, const Matrix& rhs);
		friend Matrix operator*(const Matrix& lhs, int scalar);
		friend Matrix operator*(int scalar, const Matrix& rhs);
		friend Matrix operator*(const Matrix& lhs, const Matrix& rhs);

		friend bool operator==(const Matrix& lhs, const Matrix& rhs);
		friend bool operator!=(const Matrix& lhs, const Matrix& rhs);

		friend std::ostream& operator<<(std::ostream& stream, const Matrix& matrix);

		const int* operator[](int index) const;
		int* operator[](int index);

		~Matrix();
};

