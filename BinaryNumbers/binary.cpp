#include <iostream>
#include <cmath>

using namespace std;

bool isGreaterThanPow2(int input, int power)
{
	return input >= pow(2, power);
}

//int main()
//{
//	cout << "Enter a number between 0 and 255: ";
//	int number;
//	cin >> number;
//	for (int i = 7; i >= 0; --i)
//	{
//		cout << isGreaterThanPow2(number, i);
//		number -= isGreaterThanPow2(number, i)*pow(2, i);
//	}
//	cout << '\n';
//
//	return 0;
//}