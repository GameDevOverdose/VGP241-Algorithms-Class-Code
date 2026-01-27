#include "ClassCode.h"

#include "Assignment-1.h"
#include "Assignment-2.h"
#include "Assignment-3.h"

void AssignmentSelector()
{
	int assignmentInput = -1;

	std::cout << "\nHello Darren! Please input the assignment number you'd like to test (1-3): ";
	std::cin >> assignmentInput;

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
	default:
		std::cout << "I'm afraid I haven't done that assignment yet..." << std::endl;
		break;
	}
}

int main()
{
	//Assignment1();
	//Assignment2();
	//Assignment3();

	//Comment out to disable question selector
	while (true)
	{
		AssignmentSelector();
	}
}