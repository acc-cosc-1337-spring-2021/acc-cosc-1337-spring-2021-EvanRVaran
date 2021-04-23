#define CATCH_CONFIG_MAIN   //this tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include <memory>
using std::unique_ptr; using std::make_unique;
#include <string>
using std::cin; using std::cout;

TEST_CASE("Verify Test Configuration") 
{
 	REQUIRE(true == true);
}

TEST_CASE("Test first player set to X") 
{

 	unique_ptr<TicTacToeBoard> tB = make_unique<TicTacToe3>();
	tB->start_game("X");
	REQUIRE(tB->get_player() == "X");
}

TEST_CASE("Test first player set to 0") 
{
 	unique_ptr<TicTacToeBoard> tB = make_unique<TicTacToe3>();
 	tB->start_game("O");
 	REQUIRE(tB->get_player() == "O");
}

TEST_CASE("Test to see if game ends in tie") 
{
 	unique_ptr<TicTacToeBoard> tB = make_unique<TicTacToe3>();
 	tB->start_game("X");
	tB->mark_board(1);
	REQUIRE(tB->game_over() == false);
	tB->mark_board(2);
	REQUIRE(tB->game_over() == false);
	tB->mark_board(3);
	REQUIRE(tB->game_over() == false);
	tB->mark_board(4);
	REQUIRE(tB->game_over() == false);
	tB->mark_board(6);
	REQUIRE(tB->game_over() == false);
	tB->mark_board(5);
	REQUIRE(tB->game_over() == false);
	tB->mark_board(7);
	REQUIRE(tB->game_over() == false);
	tB->mark_board(9);
	REQUIRE(tB->game_over() == false);
	tB->mark_board(8);
 	tB->game_over();
	REQUIRE(tB->game_over() == true);
 	REQUIRE(tB->get_winner() == "C");
}

TEST_CASE("Test win by first column") 
{
 	unique_ptr<TicTacToeBoard> tB = make_unique<TicTacToe3>();
 	tB->start_game("X");
 	tB->mark_board(1);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(3);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(4);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(6);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(7);
 	REQUIRE(tB->game_over() == true);

}

TEST_CASE("Test win by second column") 
{
	unique_ptr<TicTacToeBoard> tB = make_unique<TicTacToe3>();
	tB->start_game("X");
	tB->mark_board(2);
	REQUIRE(tB->game_over() == false);
	tB->mark_board(3);
	REQUIRE(tB->game_over() == false);
	tB->mark_board(5);
	REQUIRE(tB->game_over() == false);
	tB->mark_board(6);
	REQUIRE(tB->game_over() == false);
	tB->mark_board(8);
	REQUIRE(tB->game_over() == true);

}

TEST_CASE("Test win by third column") 
{
 	unique_ptr<TicTacToeBoard> tB = make_unique<TicTacToe3>();
 	tB->start_game("X");
 	tB->mark_board(3);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(2);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(6);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(4);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(9);
 	REQUIRE(tB->game_over() == true);
}

TEST_CASE("Test win by first row") 
{
 	unique_ptr<TicTacToeBoard> tB = make_unique<TicTacToe3>();
 	tB->start_game("X");
 	tB->mark_board(1);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(8);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(2);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(6);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(3);
 	REQUIRE(tB->game_over() == true);
}

TEST_CASE("Test win by second row") 
{
 	unique_ptr<TicTacToeBoard> tB = make_unique<TicTacToe3>();
 	tB->start_game("X");
 	tB->mark_board(4);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(3);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(5);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(2);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(6);
 	REQUIRE(tB->game_over() == true);
}

TEST_CASE("Test win by third row") 
{
 	unique_ptr<TicTacToeBoard> tB = make_unique<TicTacToe3>();
 	tB->start_game("X");
 	tB->mark_board(7);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(3);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(8);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(6);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(9);
 	REQUIRE(tB->game_over() == true);

}

TEST_CASE("Test win diagonally from top left") 
{
 	unique_ptr<TicTacToeBoard> tB = make_unique<TicTacToe3>();
 	tB->start_game("X");
 	tB->mark_board(1);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(3);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(5);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(6);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(9);
 	REQUIRE(tB->game_over() == true);
}

TEST_CASE("Test win diagonally from bottom left") 
{
 	unique_ptr<TicTacToeBoard> tB = make_unique<TicTacToe3>();
 	tB->start_game("X");
 	tB->mark_board(7);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(2);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(5);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(6);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(3);
 	REQUIRE(tB->game_over() == true);
}

TEST_CASE("Test TicTacToe manager winner total function") 
{
	TicTacToeManager tttM;
 	unique_ptr<TicTacToeBoard> xWin= make_unique<TicTacToe3>();
 	xWin->start_game("X");
 	xWin->mark_board(7);
	REQUIRE(xWin->game_over() == false);
 	xWin->mark_board(2);
	REQUIRE(xWin->game_over() == false);
 	xWin->mark_board(5);
	REQUIRE(xWin->game_over() == false);
 	xWin->mark_board(6);
	REQUIRE(xWin->game_over() == false);
 	xWin->mark_board(3);
 	xWin->game_over();
	REQUIRE(xWin->game_over() == true);
	tttM.save_game(xWin);

	unique_ptr<TicTacToeBoard> oWin= make_unique<TicTacToe3>();
 	oWin->start_game("O");
 	oWin->mark_board(7);
	REQUIRE(oWin->game_over() == false);
 	oWin->mark_board(2);
	REQUIRE(oWin->game_over() == false);
 	oWin->mark_board(5);
	REQUIRE(oWin->game_over() == false);
 	oWin->mark_board(6);
	REQUIRE(oWin->game_over() == false);
 	oWin->mark_board(3);
 	oWin->game_over();
	REQUIRE(oWin->game_over() == true);
	tttM.save_game(oWin);

	unique_ptr<TicTacToeBoard> tie = make_unique<TicTacToe3>();
 	tie->start_game("X");
	tie->mark_board(1);
	REQUIRE(tie->game_over() == false);
	tie->mark_board(2);
	REQUIRE(tie->game_over() == false);
	tie->mark_board(3);
	REQUIRE(tie->game_over() == false);
	tie->mark_board(4);
	REQUIRE(tie->game_over() == false);
	tie->mark_board(6);
	REQUIRE(tie->game_over() == false);
	tie->mark_board(5);
	REQUIRE(tie->game_over() == false);
	tie->mark_board(7);
	REQUIRE(tie->game_over() == false);
	tie->mark_board(9);
	REQUIRE(tie->game_over() == false);
	tie->mark_board(8);
 	tie->game_over();
	REQUIRE(tie->game_over() == true);
 	
	tttM.save_game(tie);

	int number_O_Wins = 0;
	int number_X_Wins = 0;
	int number_ties = 0;
	tttM.get_winner_totals(number_O_Wins,number_X_Wins,number_ties);

	REQUIRE(number_X_Wins == 1);
	REQUIRE(number_O_Wins == 1);
	REQUIRE(number_ties == 1);
}


TEST_CASE("Test first player set to X (4)") 
{
 	unique_ptr<TicTacToeBoard> tB= make_unique<TicTacToe4>();
 	tB->start_game("X");
 	REQUIRE(tB->get_player() == "X");

}
TEST_CASE("Test first player set to O (4)") 
{
 	unique_ptr<TicTacToeBoard> tB= make_unique<TicTacToe4>();
 	tB->start_game("O");
 	REQUIRE(tB->get_player() == "O");
}

TEST_CASE("Test to see if game ends in tie 4") 
{
 	unique_ptr<TicTacToeBoard> tB= make_unique<TicTacToe4>();
 	tB->start_game("X");
	tB->mark_board(1);
	REQUIRE(tB->game_over() == false);
	tB->mark_board(2);
	REQUIRE(tB->game_over() == false);
	tB->mark_board(3);
	REQUIRE(tB->game_over() == false);
	tB->mark_board(4);
	REQUIRE(tB->game_over() == false);
	tB->mark_board(7);
	REQUIRE(tB->game_over() == false);
	tB->mark_board(5);
	REQUIRE(tB->game_over() == false);
	tB->mark_board(8);
	REQUIRE(tB->game_over() == false);
	tB->mark_board(6);
	REQUIRE(tB->game_over() == false);
	tB->mark_board(9);
	REQUIRE(tB->game_over() == false); 
	tB->mark_board(11);
	REQUIRE(tB->game_over() == false);
	tB->mark_board(10);
	REQUIRE(tB->game_over() == false);
	tB->mark_board(12);
	REQUIRE(tB->game_over() == false);
	tB->mark_board(14);
	REQUIRE(tB->game_over() == false);
	tB->mark_board(13);
	REQUIRE(tB->game_over() == false);
	tB->mark_board(16);
	REQUIRE(tB->game_over() == false);
	tB->mark_board(15);
 	tB->game_over();
	REQUIRE(tB->game_over() == true);
 	REQUIRE(tB->get_winner() == "C");
}

TEST_CASE("Test win by first column 4") 
{
 	unique_ptr<TicTacToeBoard> tB= make_unique<TicTacToe4>();
 	tB->start_game("X");
 	tB->mark_board(1);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(3);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(5);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(6);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(9);
	REQUIRE(tB->game_over() == false);
	tB->mark_board(7);
	REQUIRE(tB->game_over() == false);
	tB->mark_board(13);
 	REQUIRE(tB->game_over() == true);
}

TEST_CASE("Test win by second column 4") 
{
	unique_ptr<TicTacToeBoard> tB= make_unique<TicTacToe4>();
	tB->start_game("X");
	tB->mark_board(2);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(3);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(6);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(8);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(10);
	REQUIRE(tB->game_over() == false);
	tB->mark_board(7);
	REQUIRE(tB->game_over() == false);
	tB->mark_board(14);
	REQUIRE(tB->game_over() == true);
}

TEST_CASE("Test win by third column 4") 
{
 	unique_ptr<TicTacToeBoard> tB= make_unique<TicTacToe4>();
 	tB->start_game("X");
 	tB->mark_board(3);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(2);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(7);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(6);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(11);
	REQUIRE(tB->game_over() == false);
	tB->mark_board(1);
	REQUIRE(tB->game_over() == false);
	tB->mark_board(15);
 	REQUIRE(tB->game_over() == true);
}
TEST_CASE("Test win by fourth column 4") 
{
 	unique_ptr<TicTacToeBoard> tB= make_unique<TicTacToe4>();
 	tB->start_game("X");
 	tB->mark_board(4);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(2);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(8);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(6);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(12);
	REQUIRE(tB->game_over() == false);
	tB->mark_board(1);
	REQUIRE(tB->game_over() == false);
	tB->mark_board(16);
 	REQUIRE(tB->game_over() == true);
}
TEST_CASE("Test win by first row 4") 
{
 	unique_ptr<TicTacToeBoard> tB= make_unique<TicTacToe4>();
 	tB->start_game("X");
 	tB->mark_board(1);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(9);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(2);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(6);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(3);
	REQUIRE(tB->game_over() == false);
	tB->mark_board(7);
	REQUIRE(tB->game_over() == false);
	tB->mark_board(4);
 	REQUIRE(tB->game_over() == true);
}

TEST_CASE("Test win by second row 4") 
{
 	unique_ptr<TicTacToeBoard> tB= make_unique<TicTacToe4>();
 	tB->start_game("X");
 	tB->mark_board(5);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(9);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(6);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(1);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(7);
	REQUIRE(tB->game_over() == false);
	tB->mark_board(2);
	REQUIRE(tB->game_over() == false);
	tB->mark_board(8);
 	REQUIRE(tB->game_over() == true);
}

TEST_CASE("Test win by third row 4") 
{
 	unique_ptr<TicTacToeBoard> tB= make_unique<TicTacToe4>();
 	tB->start_game("X");
 	tB->mark_board(9);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(1);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(10);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(6);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(11);
	REQUIRE(tB->game_over() == false);
	tB->mark_board(7);
	REQUIRE(tB->game_over() == false);
	tB->mark_board(12);
 	REQUIRE(tB->game_over() == true);
}

TEST_CASE("Test win by fourth row 4") 
{
 	unique_ptr<TicTacToeBoard> tB= make_unique<TicTacToe4>();
 	tB->start_game("X");
 	tB->mark_board(13);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(1);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(14);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(6);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(15);
	REQUIRE(tB->game_over() == false);
	tB->mark_board(7);
	REQUIRE(tB->game_over() == false);
	tB->mark_board(16);
 	REQUIRE(tB->game_over() == true);
}

TEST_CASE("Test win diagonally from top left 4") 
{
 	unique_ptr<TicTacToeBoard> tB= make_unique<TicTacToe4>();
 	tB->start_game("X");
 	tB->mark_board(1);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(5);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(6);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(2);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(11);
	REQUIRE(tB->game_over() == false);
	tB->mark_board(7);
	REQUIRE(tB->game_over() == false);
	tB->mark_board(16);
 	REQUIRE(tB->game_over() == true);
}

TEST_CASE("Test win diagonally from bottom left 4") 
{
 	unique_ptr<TicTacToeBoard> tB= make_unique<TicTacToe4>();
 	tB->start_game("X");
 	tB->mark_board(4);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(1);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(7);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(6);
	REQUIRE(tB->game_over() == false);
 	tB->mark_board(10);
	REQUIRE(tB->game_over() == false);
	tB->mark_board(2);
	REQUIRE(tB->game_over() == false);
	tB->mark_board(13);
 	REQUIRE(tB->game_over() == true);
}

TEST_CASE("Test TicTacToe manager winner total function 4") 
{
	TicTacToeManager tttM;
 	unique_ptr<TicTacToeBoard> xWin= make_unique<TicTacToe4>();
 	xWin->start_game("X");
	xWin->mark_board(4);
	REQUIRE(xWin->game_over() == false);
 	xWin->mark_board(1);
	REQUIRE(xWin->game_over() == false);
 	xWin->mark_board(7);
	REQUIRE(xWin->game_over() == false);
 	xWin->mark_board(6);
	REQUIRE(xWin->game_over() == false);
 	xWin->mark_board(10);
	REQUIRE(xWin->game_over() == false);
	xWin->mark_board(2);
	REQUIRE(xWin->game_over() == false);
	xWin->mark_board(13);
 	xWin->game_over();
	REQUIRE(xWin->game_over() == true);
	tttM.save_game(xWin);

	unique_ptr<TicTacToeBoard> oWin= make_unique<TicTacToe4>();
 	oWin->start_game("O");
 	oWin->mark_board(4);
	REQUIRE(oWin->game_over() == false);
 	oWin->mark_board(1);
	REQUIRE(oWin->game_over() == false);
 	oWin->mark_board(7);
	REQUIRE(oWin->game_over() == false);
 	oWin->mark_board(6);
	REQUIRE(oWin->game_over() == false);
 	oWin->mark_board(10);
	REQUIRE(oWin->game_over() == false);
	oWin->mark_board(2);
	REQUIRE(oWin->game_over() == false);
	oWin->mark_board(13);
 	oWin->game_over();
	REQUIRE(oWin->game_over() == true);
	tttM.save_game(oWin);

	unique_ptr<TicTacToeBoard> tie= make_unique<TicTacToe4>();
 	tie->start_game("O");
	tie->mark_board(1);
	REQUIRE(tie->game_over() == false);
	tie->mark_board(2);
	REQUIRE(tie->game_over() == false);
	tie->mark_board(3);
	REQUIRE(tie->game_over() == false);
	tie->mark_board(4);
	REQUIRE(tie->game_over() == false);
	tie->mark_board(7);
	REQUIRE(tie->game_over() == false);
	tie->mark_board(5);
	REQUIRE(tie->game_over() == false);
	tie->mark_board(8);
	REQUIRE(tie->game_over() == false);
	tie->mark_board(6);
	REQUIRE(tie->game_over() == false);
	tie->mark_board(9);
	REQUIRE(tie->game_over() == false); 
	tie->mark_board(11);
	REQUIRE(tie->game_over() == false);
	tie->mark_board(10);
	REQUIRE(tie->game_over() == false);
	tie->mark_board(12);
	REQUIRE(tie->game_over() == false);
	tie->mark_board(14);
	REQUIRE(tie->game_over() == false);
	tie->mark_board(13);
	REQUIRE(tie->game_over() == false);
	tie->mark_board(16);
	REQUIRE(tie->game_over() == false);
	tie->mark_board(15);
	tie->game_over();
	REQUIRE(tie->game_over() == true); 
	tttM.save_game(tie);

	int number_O_Wins = 0;
	int number_X_Wins = 0;
	int number_ties = 0;
	tttM.get_winner_totals(number_O_Wins,number_X_Wins,number_ties);

	REQUIRE(number_X_Wins == 1);
	REQUIRE(number_O_Wins == 1);
	REQUIRE(number_ties == 1);
}





	

	



	



	
	

	

