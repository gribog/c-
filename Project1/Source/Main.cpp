#include <iostream>
#include <string>
#include <utility>

//void sortNames(std::string *list, int size)
//{
//	for (int iteration = 0; iteration < size -1; ++iteration)
//	{
//		for (int index = 0; index < size - iteration - 1; ++index)
//		{
//			if (*(list + index) > *(list + index + 1))
//				swap(*(list + index), *(list + index + 1));
//		}
//	}
//}

//////////////////////////////////////Students///////////////////////////////////////
/*struct StudentGrades
{
	std::string name;
	int grade;
};

void enterGrade(StudentGrades *inputArray, int index)
{
	std::cout << "Enter name for student #" << index + 1 << ": ";
	std::cin >> (inputArray + index)->name;

	std::cout << "Enter grade for student  #" << index + 1 << ": ";
	std::cin >> (inputArray + index)->grade;

	std::cout << '\n';
}

void sortStudents(StudentGrades *inputArray, int totalStudents)
{
	for (int iteration = 0; iteration < totalStudents - 1; ++iteration)
			{
				for (int index = 0; index < totalStudents - iteration - 1; ++index)
				{
					if (inputArray[index].grade < inputArray[index + 1].grade)
					{
						std::swap((inputArray + index)->grade, (inputArray + index + 1)->grade);
						std::swap((inputArray + index)->name, (inputArray + index + 1)->name);
					}
				}
			}
}*/
///////////////////////////////////////////////////////////////////////////////////////////

void printString(const char *inputString)
{
	int index = 0;
	while (static_cast<int>(inputString[index]) != 0)
	{
		std::cout << inputString[index];
		++index;
	}
	std::cout << '\n';

}

int main()
{
	char testString[] = "Hello, world!";

	printString(testString);

	////////////////////////////////////////Students/////////////////////////////////////////////////
	/*std::cout << "How many students to enter: ";
	int totalStudents;
	std::cin >> totalStudents;

	StudentGrades *ourStudents = new StudentGrades[totalStudents];
	for (int index = 0; index < totalStudents; ++index)
		enterGrade(ourStudents, index);

	sortStudents(ourStudents,totalStudents);

	for (int index = 0; index < totalStudents; ++index)
	{
		std::cout << (ourStudents + index)->name << " got a grade of " << (ourStudents + index)->grade << '\n';
	}


	delete[] ourStudents;
	*/
	/////////////////////////////////////////////////////////////////////////////////////

	//std::cout << "How many names would you like to enter? ";
	//int totalNames;
	//std::cin >> totalNames;

	//std::string *names = new std::string[totalNames];

	//for (int index = 0; index < totalNames; ++index)
	//{
	//	std::cout << "Enter name #" << index + 1 << ": ";
	//	std::cin >> names[index];
	//}

	//sortNames(names, totalNames);

	//std::cout << "\nHere is your sorted list:" << '\n';

	//for (int index = 0; index < totalNames; ++index)
	//{
	//	std::cout << "Name #" << index + 1 << ": " << *(names + index) << '\n';
	//}

	//delete[] names;

	//std::string names[] { "Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly" };

	//std::cout << "Enter a name: ";
	//std::string enteredName;
	//std::cin >> enteredName;
	//bool found = false;

	//for (const auto &name : names)
	//	if (enteredName == name)
	//	{
	//		found = true;
	//		break;
	//	}
	//
	//if (found)
	//	std::cout << enteredName << " was found.\n";
	//else
	//	std::cout << enteredName << " was not found.\n";



	return 0;
}