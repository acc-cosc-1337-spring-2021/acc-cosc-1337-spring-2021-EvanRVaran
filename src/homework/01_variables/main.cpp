//write include statements
#include <iostream>
#include "variables.h"
#include <string>
//write namespace using statement for cout
using std::cout; using std::cin;

/*
Call multiply_numbers with 10 and 10 parameter values and display function result
*/
int main()
{
	double meal_amount , tip_rate , tip_amount , tax_amount , total;
	cout << "Meal Amount: ";
	cin >> meal_amount;
	tax_amount = get_sales_tax(meal_amount);
	cout << "Tip Rate: ";
	cin >> tip_rate;
	tip_amount = get_tip_amount(meal_amount , tip_rate);
	total = tip_amount + tax_amount + meal_amount;
	cout << "Meal Amount: " + std::to_string(meal_amount) + "\n";
	cout << "Sales Tax: " + std::to_string(tax_amount) + "\n";
	cout << "Tip Amount: " + std::to_string(tip_amount) + "\n";
	cout << "Total: " + std::to_string(total) + "\n";


	return 0;
}
