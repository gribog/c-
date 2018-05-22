#include <iostream>
#include "constants.h"

using namespace std;

void printDistance(int second, double height)
{
	if (height > 0.0)
	{
		cout << "At " << second << " seconds, the ball is at height: " << height << " meters" << '\n';
	}
	else
	{
		cout << "At " << second << " seconds, the ball is on the ground." << '\n';
	}
	
}

double calculateHeight(double initial, double fallen)
{
	if (initial > fallen)
	{
		return initial - fallen;
	}
	else
	{
		return 0;
	}
}

int main()
{
	cout << "Enter the initial height of the tower in meters: ";
	double towerHeight{ 0.0 };
	cin >> towerHeight;
	int sec = 0;
	double distanceFallen{ 0.0 };
	do
	{
		distanceFallen = myConstants::gravity  * sec * sec / 2;
		printDistance(sec, calculateHeight(towerHeight, distanceFallen));
		++sec;

	} while (distanceFallen<towerHeight);

	return 0;
}