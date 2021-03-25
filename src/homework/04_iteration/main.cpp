//write include statements
#include "dna.h"
#include<string>
#include<iostream>
//write using statements
using std::cin; using std::cout;

/*
Write code that prompts user to enter 1 for Get GC Content, 
or 2 for Get DNA Complement.  The program will prompt user for a 
DNA string and call either get gc content or get dna complement
function and display the result. Program runs as long as 
user enters a y or Y.
*/
int main() 
{
	std::string userInput;
	std::string dnaStringAnswer;
	std::string stringInput;
	double dnaDoubleAnswer;
	bool exitProgram = false;
	do
	{
		do
		{
			cout << "Enter a 1 for Get GC content  \nEnter a 2 for Get DNA Complement: ";
			cin >> userInput;
		}
		while(userInput != "1" && userInput != "2");

		cout << "Please enter your DNA string: ";
		cin >> stringInput;
		
		if(userInput == "1")
		{
			dnaDoubleAnswer = get_gc_content(stringInput);
			cout << "Your GC content is " + std::to_string(dnaDoubleAnswer);
		}
		else if(userInput == "2")
		{
			dnaStringAnswer = get_dna_complement(stringInput);
			cout << "Your DNA Complement is " + dnaStringAnswer;
		}
		cout << " \nWould you like to continue? (type y for yes and anything else for no): ";
		cin >> stringInput;

		if(stringInput != "y")
		{
			exitProgram = true;
		}
	}
	while(exitProgram == false);
	return 0;
}