#pragma once
#include "Vector.h"

class Matrix
{
public:
	Matrix()
	{
		size = 0;
	}

	Matrix(const int& _size) : arr(_size)
	{
		size = _size;
		for(int i = 0; i < size; ++i)
		{
			arr[i] = Vector<double>(size);
		}
	}
	Matrix(const Matrix& copy) : arr(copy.size)
	{
		size = copy.size;
		for(int i = 0; i < size; ++i)
		{
			arr[i] = copy.arr[i];
		}
	}
	void print_matrix()
	{
		for (int i = 0; i < size; ++i)
		{
			arr[i].print();
			std::cout << std::endl;
		}
	}
	void set_matrix()
	{
		for (size_t i = 0; i < size; ++i)
		{
			arr[i].set_vector();
		}
	}
	int pos_max(int n, int m)
	{
		double tmp = arr[n][m];
		int pos = n;
		for (int i = n + 1; i < size; ++i)
		{
			if (abs(tmp) < abs(arr[i][m]))
			{
				tmp = arr[i][m];
				pos = i;
			}
		}
		return pos;
	}
	Vector<double>& operator[](const int& index)
	{
		return arr[index];
	}

	Vector<double>& operator[](const int& index) const
	{
		return arr[index];
	}

	void swap(Vector<double>& left, Vector<double>& right)
	{
		Vector<double> c = left;
		left = right;
		right = c;
	}

protected:
	Vector<Vector<double>> arr;
	int size;
};
