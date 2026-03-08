#include "ClassCode.h"

#include "Assignment-1.h"
#include "Assignment-2.h"
#include "Assignment-3.h"
#include "Assignment-4.h"
#include "Assignment-5.h"
#include "Assignment-6.h"
#include "Assignment-7.h"

void AssignmentSelector()
{
	int assignmentInput = -1;

	std::cout << "\nHello Darren! Please input the assignment number you'd like to test (1-7): ";
	std::cin >> assignmentInput;
	
	system("cls");

	std::cout << "\n";

	switch (assignmentInput)
	{
	case 1:
		Assignment1();
		break;
	case 2:
		Assignment2();
		break;
	case 3:
		Assignment3();
		break;
	case 4:
		Assignment4();
		break;
	case 5:
		Assignment5();
		break;
	case 6:
		Assignment6();
		break;
	case 7:
		Assignment7();
		break;
	default:
		std::cout << "I'm afraid I haven't done that assignment yet..." << std::endl;
		break;
	}
}

int main()
{
	std::srand(std::time(nullptr));

	//MSTGraphTest();

	//Assignment1();
	//Assignment2();
	//Assignment3();
	//Assignment4();
	//Assignment5();
	//Assignment6();
	//Assignment7();

	//Comment out to disable question selector
	while (true)
	{
		AssignmentSelector();
	}
}