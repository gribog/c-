#include <iostream>


int ReadNumber()
{
	int x;
	std::cout << "Enter a number: ";
	std::cin >> x;
	return x;
}

void WriteAnswer(int a, int b)
{
	std::cout << "Sum is " << a + b << std::endl;
}
