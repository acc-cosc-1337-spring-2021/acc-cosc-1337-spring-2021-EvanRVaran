#include "tic_tac_toe_manager.h"
#include<iostream>
#include<string>
using std::cin; using std::cout;

int main() 
{
	std::string stringInput;
	bool exitProgram;
	TicTacToeBoard tttB;
	TicTacToeManager tttM;
	int number_O_Wins = 0;
	int number_X_Wins = 0;
	int number_ties = 0;

	do
	{
		do
		{
			cout << "Who is the first player? Enter either 'X' or 'O': ";
			cin >> stringInput;
		}

		while(stringInput != "X" && stringInput != "O");
		tttB.start_game(stringInput);

		while(tttB.game_over() == false)
		{
			cin >> tttB;
		}
		cout << " \n Game Over! \n";

		std::string winner = tttB.get_winner();
		tttM.save_game(tttB);
		tttM.get_winner_totals(number_O_Wins,number_X_Wins,number_ties);

		if (winner != "C")
		{
			cout << "The winner is: " + winner;
		}
		else
		{
			cout <<"The game is a tie!";
		}

		cout << "\nThe total wins are currently: " + std::to_string(number_X_Wins) + " for X, " + std::to_string(number_O_Wins) + " for O, and " + std::to_string(number_ties) + " ties. \n";
		cout << "\nWould you like to play again? (type y for yes and anything else for no): ";
		
		cin >> stringInput;
		if(stringInput != "y")
		{
			exitProgram = true;
		}

	}
	while(exitProgram == false);
	cout << tttM;
	return 0;
}