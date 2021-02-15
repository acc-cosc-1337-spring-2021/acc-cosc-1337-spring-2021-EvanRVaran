//Write the include statement for decisions.h here
#include<iostream>
#include<string>
#include "decision.h"
//Write namespace using statements for cout and cin
using std::cin; using std::cout;

int main() 
{
	int grade;
	std::string letterGrade;
	cout << "Enter a number grade: ";
	cin >> grade;

	letterGrade = get_letter_grade_using_if(grade);
	cout << "Letter grade using if: " + letterGrade + "\n";
	letterGrade = get_letter_grade_using_switch(grade);
	cout << "Letter grade using switch: " + letterGrade;
	return 0;
}

