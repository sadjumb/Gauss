#include <iostream>
#include "Slau.h"


int main()
{
	
	int n;
	std::cout << "Enter size matrix: ";
	std::cin >> n;
	Slau a(n);
	std::cout << "Enter matrix: " << std::endl;
	a.enter_matrix();
	std::cout << "Enter vector of value: " << std::endl;
	a.set_vov();
	
	a.gauss();
}