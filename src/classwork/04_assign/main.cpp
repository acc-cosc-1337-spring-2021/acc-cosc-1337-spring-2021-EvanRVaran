//write includes statements
#include<iostream>
#include<string>
#include "loops.h"
//write using statements for cin and cout
using std::cin; using std::cout;

/*
Use a do while loop to prompt the user for 
a number, call the factorial function, and display the number's
factorial.  Also, loop continues as long as user wants to.
*/
int main() 
{
	int input = 0;
	int factorialAnswer;
	std::string stringInput;
	bool exitProgram = false;
	do
	{
		do
		{
			cout << "Please Enter a number with a minimum value of 1 and maximum value of 10: \n";
			cin >> input;
		}
		while(input > 10 || input < 1);

		factorialAnswer = factorial(input);
		cout << "The factorial of "+ std::to_string(input) + " is " + std::to_string(factorialAnswer);
		cout << " Would you like to continue? (type y for yes and anything else for no): ";
		cin >> stringInput;
		if(stringInput != "y")
		{
			exitProgram = true;
		}
	}
	while(exitProgram == false);
	return 0;
}