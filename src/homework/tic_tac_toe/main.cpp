#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include<iostream>
#include<string>
#include <memory>
using std::unique_ptr; using std::make_unique;
using std::cin; using std::cout;

int main() 
{
	std::string stringInput;
	bool exitProgram;
	unique_ptr<TicTacToeBoard> tB;
	TicTacToeManager tttM;
	int number_O_Wins = 0;
	int number_X_Wins = 0;
	int number_ties = 0;


	do
	{
		do
		{
			cout <<"Play 3x3 tictactoe or 4x4 type 3 for 3x3 and 4 for 4x4: \n";
			cin >> stringInput;
			if (stringInput == "3")
			{
				tB= make_unique<TicTacToe3>();
			}
			if (stringInput == "4")
			{
				tB= make_unique<TicTacToe4>();
			}
		
		}
		while (stringInput != "3" && stringInput != "4");
		
		do
		{
			cout << "Who is the first player? Enter either 'X' or 'O': ";
			cin >> stringInput;
		}

		while(stringInput != "X" && stringInput != "O");
		tB->start_game(stringInput);

		while(tB->game_over() == false)
		{
			cin >> *tB;
		}
		cout << " \nGame Over! \n";

		std::string winner = tB->get_winner();
		tttM.save_game(tB);
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