#define CATCH_CONFIG_MAIN   //this tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"

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






	

	



	



	
	

	

