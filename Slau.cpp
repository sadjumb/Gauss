#include "Slau.h"

Slau::Slau()
{
	size = 0;
}

Slau::Slau(const int& _size) : Matrix(_size), vov(_size)
{
	size = _size;
}

Slau::Slau(const Slau& copy) : Matrix(copy.size), vov(copy.vov)
{
	size = copy.size;
	for(int i = 0; i < size; ++i)
	{
		arr[i] = copy[i];
	}
}

Slau::~Slau()
{
	size = 0;
}

void Slau::set_vov()
{
	
	vov.set_vector();
}

void Slau::enter_matrix()
{
	set_matrix();
}

void Slau::print_vov()
{
	vov.print();
}

Vector<double> Slau::get_vov()
{
	return vov;
}

Slau Slau::gauss()
{
	Slau tmp = *this;
	size_t index_max = 0;
	double max = 0;

	for (size_t i = 0; i < size; ++i)
	{
		index_max = tmp.pos_max(i, i);
		max = tmp.arr[index_max][i];
		if (index_max > i)
		{
			tmp.swap(tmp.arr[index_max], tmp.arr[i]);
			tmp.vov.swap(index_max, i);
		}
		index_max = i;
		if (abs(max) != 0)
		{
			tmp.arr[index_max] /= max;
			tmp.vov[index_max] /= max;
			for (size_t j = 0; j < this->size; ++j)
			{
				if (j != index_max)
				{
					tmp.vov[j] -= (tmp.vov[index_max] * tmp.arr[j][i]);
					tmp.arr[j] -= (tmp.arr[index_max] * tmp.arr[j][i]);
				}
			}
		}
	}
	
	bool solution = true;
	for (int i = 0; i < size; ++i)
	{
		if (tmp.arr[i][i] == 0)
		{
			if (tmp.vov[i] == 0)
			{
				std::cout << " > 1 solutions." << std::endl;
			}
			else
			{
				std::cout << "0 solution." << std::endl;
			}
			solution = false;
			break;
		}
	}
	if (solution)
	{
		std::cout << "One solution." << std::endl;
	}
	tmp.print_vov();
	std::cout << std::endl;
	//tmp.print_slau();
	return tmp;
}
