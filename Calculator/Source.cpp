#include <iostream>

int getInt()
{
	std::cout << "Enter integer number: ";
	int x;
	std::cin >> x;
	return x;
}

char getOperator()
{
	char op;
	do
	{
		std::cout << "Enter math operator (+, -, *, /): ";
		std::cin >> op;
	} while (op != '+' && op != '-' && op != '*' && op != '/');
	return op;
}

int add(int x, int y)
{
	return x + y;
}

int substract(int x, int y)
{
	return x - y;
}

int multiply(int x, int y)
{
	return x * y;
}

int divide(int x, int y)
{
	return x / y;
}

typedef int (*arithmeticFcn)(int, int);

arithmeticFcn getArithmeticFunction(char op)
{
	switch (op)
	{
	case '+': return int(*add)(int, int);
	}

}

int main()
{
	int firstNumber = getInt();
	char mathOperator = getOperator();
	int secondNumber = getInt();

	return 0;
}