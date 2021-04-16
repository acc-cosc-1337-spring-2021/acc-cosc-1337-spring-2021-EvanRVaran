#include "tic_tac_toe.h"
#include<iostream>
#include<string>
using std::cin; using std::cout;

bool TicTacToeBoard::game_over()
{
    bool column_win;
    bool diagonal_win;
    bool row_win;

    column_win = check_column_win();
    diagonal_win = check_diagonal_win();
    row_win = check_row_win();

    if(column_win == true || diagonal_win == true || row_win == true)
    {
        set_winner();
        return true;
    }
    else
    {
        return check_board_full();
    }
}

void TicTacToeBoard::start_game(std::string first_player)
{
    player = first_player;
    clear_board();
}

void TicTacToeBoard::mark_board(int position)
{
    pegs[position - 1] = player;
    set_next_player();
}

std::string TicTacToeBoard::get_player()const
{
    return player;
}

bool TicTacToeBoard::check_board_full()
{
    for(int k = 0; k < 9; k++)
    {
        if(pegs[k] == " ")
        {
            return false;
        }
    }
    winner = "C";
    return true;
}

void TicTacToeBoard::clear_board()
{
    for(int k = 0; k < 9; k++)
    {
        pegs[k] = " ";
    }
}

void TicTacToeBoard::set_next_player()
{
    
    if(player == "X")
    {
        player = "O";
    }
    else
    {
        player = "X";
    }

}
std::string TicTacToeBoard::get_winner()
{
    return winner;
}

bool TicTacToeBoard::check_column_win()
{
    if(((pegs[0] == "X" && pegs[3] ==  "X" && pegs[6] == "X") || (pegs[0] == "O" && pegs[3] ==  "O" && pegs[6] == "O")) || ((pegs[1] == "X" && pegs[4] ==  "X" && pegs[7] == "X") || (pegs[1] == "O" && pegs[4] ==  "O" && pegs[7] == "O")) || ((pegs[2] == "X" && pegs[5] ==  "X" && pegs[8] == "X") || (pegs[2] == "O" && pegs[5] ==  "O" && pegs[8] == "O")))
    {
        return true;
    }
    else
    {
        return false;
    }
} 
bool TicTacToeBoard::check_row_win()
{
    if(((pegs[0] == "X" && pegs[1] ==  "X" && pegs[2] == "X") || (pegs[0] == "O" && pegs[1] ==  "O" && pegs[2] == "O")) || ((pegs[3] == "X" && pegs[4] ==  "X" && pegs[5] == "X") || (pegs[3] == "O" && pegs[4] ==  "O" && pegs[5] == "O")) || ((pegs[6] == "X" && pegs[7] ==  "X" && pegs[8] == "X") || (pegs[6] == "O" && pegs[7] ==  "O" && pegs[8] == "O")))
    {
        return true;
    }
    else
    {
        return false;
    }
} 
bool TicTacToeBoard::check_diagonal_win()
{
    if(((pegs[0] == "X" && pegs[4] ==  "X" && pegs[8] == "X") || (pegs[0] == "O" && pegs[4] ==  "O" && pegs[8] == "O")) || ((pegs[2] == "X" && pegs[4] ==  "X" && pegs[6] == "X") || (pegs[2] == "O" && pegs[4] ==  "O" && pegs[6] == "O"))) 
    {
        return true;
    }
    else
    {
        return false;
    }
}
void TicTacToeBoard::set_winner()
{
    if(winner != "C")
    {
        if(player == "X")
        {
            winner = "O";
        }
        else
        {
            winner = "X";
        }
    }
}   
std::ostream& operator<<(std::ostream& out, const TicTacToeBoard& game)
{
    for(int i = 0; i < 9; i++)
    {
        if(i % 3 == 0)
        {
            out << "\n";
        }
        out << game.pegs[i] + " "; //?
    }
    return out;
}
std::istream& operator>>(std::istream& in, TicTacToeBoard& game)
{
    std::string stringInput;
    cout << "Enter where the current player would like to mark the board (1-9): ";
    in >> stringInput;
    if(stringInput == "1" || stringInput == "2" || stringInput == "3" || stringInput == "4" || stringInput == "5" || stringInput == "6" || stringInput == "7" || stringInput == "8" || stringInput == "9")
	{
		game.mark_board(stoi(stringInput));
		cout << "The board currently looks like this: ";
        cout << game;
		cout << "\n";
	}
    return in;
}