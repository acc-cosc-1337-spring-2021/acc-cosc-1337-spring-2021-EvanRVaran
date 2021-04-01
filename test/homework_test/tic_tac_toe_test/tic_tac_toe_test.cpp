#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}
TEST_CASE("Test game over if 9 slots are selected", "test tic tac toe board") 
{
	TicTacToeBoard tB;
	tB.start_game("X");
	for(int i = 1; i < 10; i ++)
	{
		tB.mark_board(i);
	}
}

