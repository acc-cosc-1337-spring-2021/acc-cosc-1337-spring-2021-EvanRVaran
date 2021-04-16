#define CATCH_CONFIG_MAIN   //this tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
//#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"

TEST_CASE("Verify Test Configuration") 
{
 	REQUIRE(true == true);
}

TEST_CASE("Test first player set to X") 
{
 	TicTacToeBoard tB;
 	tB.start_game("X");
 	REQUIRE(tB.get_player() == "X");

}
TEST_CASE("Test first player set to 0") 
{
 	TicTacToeBoard tB;
 	tB.start_game("O");
 	REQUIRE(tB.get_player() == "O");
}

TEST_CASE("Test to see if game ends in tie") 
{
 	TicTacToeBoard tB;
 	tB.start_game("X");
	tB.mark_board(1);
	tB.mark_board(2);
	tB.mark_board(3);
	tB.mark_board(4);
	tB.mark_board(6);
	tB.mark_board(5);
	tB.mark_board(7);
	tB.mark_board(9);
	tB.mark_board(8);
 	tB.game_over();
 	REQUIRE(tB.get_winner() == "C");
}

TEST_CASE("Test win by first column") 
{
 	TicTacToeBoard tB;
 	tB.start_game("X");
 	tB.mark_board(1);
 	tB.mark_board(3);
 	tB.mark_board(4);
 	tB.mark_board(6);
 	tB.mark_board(7);
 	REQUIRE(tB.game_over() == true);

}

TEST_CASE("Test win by second column") 
{
	TicTacToeBoard tB = TicTacToeBoard();
	tB.start_game("X");
	tB.mark_board(2);
	tB.mark_board(3);
	tB.mark_board(5);
	tB.mark_board(6);
	tB.mark_board(8);
	REQUIRE(tB.game_over() == true);

}

TEST_CASE("Test win by third column") 
{
 	TicTacToeBoard tB;
 	tB.start_game("X");
 	tB.mark_board(3);
 	tB.mark_board(2);
 	tB.mark_board(6);
 	tB.mark_board(4);
 	tB.mark_board(9);
 	REQUIRE(tB.game_over() == true);
}
TEST_CASE("Test win by first row") 
{
 	TicTacToeBoard tB;
 	tB.start_game("X");
 	tB.mark_board(1);
 	tB.mark_board(8);
 	tB.mark_board(2);
 	tB.mark_board(6);
 	tB.mark_board(3);
 	REQUIRE(tB.game_over() == true);

}

TEST_CASE("Test win by second row") 
{
 	TicTacToeBoard tB;
 	tB.start_game("X");
 	tB.mark_board(4);
 	tB.mark_board(3);
 	tB.mark_board(5);
 	tB.mark_board(2);
 	tB.mark_board(6);
 	REQUIRE(tB.game_over() == true);
}

TEST_CASE("Test win by third row") 
{
 	TicTacToeBoard tB;
 	tB.start_game("X");
 	tB.mark_board(7);
 	tB.mark_board(3);
 	tB.mark_board(8);
 	tB.mark_board(6);
 	tB.mark_board(9);
 	REQUIRE(tB.game_over() == true);

}

TEST_CASE("Test win diagonally from top left") 
{
 	TicTacToeBoard tB;
 	tB.start_game("X");
 	tB.mark_board(1);
 	tB.mark_board(3);
 	tB.mark_board(5);
 	tB.mark_board(6);
 	tB.mark_board(9);
 	REQUIRE(tB.game_over() == true);

}

TEST_CASE("Test win diagonally from bottom left") 
{
 	TicTacToeBoard tB;
 	tB.start_game("X");
 	tB.mark_board(7);
 	tB.mark_board(2);
 	tB.mark_board(5);
 	tB.mark_board(6);
 	tB.mark_board(3);
 	REQUIRE(tB.game_over() == true);
}

TEST_CASE("Test TicTacToe manager winner total function") 
{
	TicTacToeManager tttM;
 	TicTacToeBoard xWin;
 	xWin.start_game("X");
 	xWin.mark_board(7);
 	xWin.mark_board(2);
 	xWin.mark_board(5);
 	xWin.mark_board(6);
 	xWin.mark_board(3);
 	xWin.game_over();
	tttM.save_game(xWin);

	TicTacToeBoard oWin;
 	oWin.start_game("O");
 	oWin.mark_board(7);
 	oWin.mark_board(2);
 	oWin.mark_board(5);
 	oWin.mark_board(6);
 	oWin.mark_board(3);
 	oWin.game_over();
	tttM.save_game(oWin);

	TicTacToeBoard tie;
 	tie.start_game("X");
	tie.mark_board(1);
	tie.mark_board(2);
	tie.mark_board(3);
	tie.mark_board(4);
	tie.mark_board(6);
	tie.mark_board(5);
	tie.mark_board(7);
	tie.mark_board(9);
	tie.mark_board(8);
 	tie.game_over();
 	
	tttM.save_game(tie);

	int number_O_Wins = 0;
	int number_X_Wins = 0;
	int number_ties = 0;
	tttM.get_winner_totals(number_O_Wins,number_X_Wins,number_ties);

	REQUIRE(number_X_Wins == 1);
	REQUIRE(number_O_Wins == 1);
	REQUIRE(number_ties == 1);
}






	

	



	



	
	

	

