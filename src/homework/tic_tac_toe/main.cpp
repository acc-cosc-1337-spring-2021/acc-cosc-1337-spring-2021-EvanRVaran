#include "tic_tac_toe.h"
#include<iostream>
#include<string>

using std::cin; using std::cout;
int main() 
{
	std::string stringInput;
	int intInput;
	bool exitProgram;
	TicTacToeBoard tttB;
	do
	{
		do
		{
			cout << "Who is the first player? Enter either 'X' or 'O': ";
			cin >> stringInput;
			
		}
		while(stringInput != "X" && stringInput != "O");
		tttB.start_game(stringInput);
		do
		{
			cout << "Enter where you would like to mark the board (1-9): ";
			cin >> stringInput;
			
			if(stringInput == "1" || stringInput == "2" || stringInput == "3" || stringInput == "4" || stringInput == "5" || stringInput == "6" || stringInput == "7" || stringInput == "8" || stringInput == "9")
			{
				//in future needs something to check if spot is filled 
				tttB.mark_board(stoi(stringInput));
				cout << "The board currently looks like this: ";
				tttB.display_board();
				cout << " \n And for the next player: \n";
			}
		}
		while(tttB.game_over() == false);
		cout << "Game Over!";
		
		cout << " \nWould you like to play again? (type y for yes and anything else for no): ";
		cin >> stringInput;

		if(stringInput != "y")
		{
			exitProgram = true;
		}
	}
	while(exitProgram == false);

	return 0;
}