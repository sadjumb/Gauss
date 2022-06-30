#pragma once
#include "Matrix.h"

class Slau : Matrix
{
public:
	Slau();
	Slau(const int& _size);
	Slau(const Slau& copy);
	~Slau();
	
	void set_vov();
	void enter_matrix();
	//void set_size(const size_t& size);
	
	void print_vov();
	Vector<double> get_vov();
	Slau gauss();

private:
	Vector<double> vov;
};

