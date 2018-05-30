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

struct arithmeticStruct
{
	char op;
	arithmeticFcn fcn;
};

static arithmeticStruct arithmeticArray[] { 
	{ '+', add },
	{ '-', substract },
	{ '*', multiply },
	{ '/', divide } 
};

arithmeticFcn getArithmeticFunction(char op)
{
	for (const auto &arith : arithmeticArray)
	{
		if (arith.op == op)
			return arith.fcn;
	}

	return add;
}

int main()
{
	int firstNumber = getInt();
	char mathOperator = getOperator();
	int secondNumber = getInt();

	arithmeticFcn fcn = getArithmeticFunction(mathOperator);

	std::cout << firstNumber << mathOperator << secondNumber << '=' << fcn(firstNumber, secondNumber) << '\n';


	return 0;
}