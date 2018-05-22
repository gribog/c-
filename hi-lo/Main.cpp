#include <iostream>
#include <random>

int getRandomNumber(int min, int max)
{
	std::random_device rd;
	std::mt19937 mersenne(rd());
	std::uniform_int_distribution<> random_number(min, max);

	return random_number(mersenne);
}

int getUserInput(int count)
{
	while (true)
	{
		std::cout << "Guess #" << count << ": ";
		int input;
		std::cin >> input;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Invalid number. Please try again.\n";
		}
		else
		{
			std::cin.ignore(32767, '\n');
			return input;
		}
			
	}
}

bool playAgain()
{
	char play_again;
	do
	{
		std::cout << "Would you like to play again (y/n)? ";
		std::cin >> play_again;
	} while (play_again != 'y' && play_again != 'n');

	return (play_again == 'y');
}

bool playGame(int maxTries, int secretNumber)
{
	for (int count = 1; count <= maxTries; ++count)
	{
		
		int guess = getUserInput(count);

		if (guess < secretNumber)
			std::cout << "Your guess is too low\n";
		else if (guess > secretNumber)
			std::cout << "Your guess is too high.\n";
		else
			return true;

	}

	return false;

}

int main()
{
	int maxTries = 7;

	do
	{
		int secret = getRandomNumber(0, 100);
		std::cout << "Let's play a game. I'm thinking of a number between 0 and 100. You have " << maxTries << " tries to guess what it is.\n";

		if (playGame(maxTries, secret))
			std::cout << "Correct! You win!\n";
		else 
			std::cout << "Sorry, you loose. The correct answer was " << secret << '\n';


	} while (playAgain());

	std::cout << "Thank you for playing.\n";



	/*while (true)
	{
		int secret = getRandomNumber(0, 100);

		cout << "Let's play a game. I'm thinking of a number. You have 7 tries to guess what it is.\n";
		int tries = 1;
		
		while (tries < 8)
		{
			cout << "Guess #" << tries << ": ";
			int guess;
			cin >> guess;

			if (guess < secret)
			{
				cout << "Your guess is too low\n";
				++tries;
				continue;
			}
			else if (guess > secret)
			{
				cout << "Your guess is too high.\n";
				++tries;
				continue;
			}
			else
			{
				cout << "Correct! You win!\n";
				break;
			}
			
			cout << "Sorry, you loose. The correct answer was " << secret << '\n';

		}

		char play_again;
		do
		{
			cout << "Would you like to play again (y/n)? ";
			cin >> play_again;
		} while (play_again != 'y' && play_again != 'n');

		if (play_again == 'y')
			continue;
		else
		{
			cout << "Thank you for playing.\n";
			break;
		}
	}*/


	return 0;
}