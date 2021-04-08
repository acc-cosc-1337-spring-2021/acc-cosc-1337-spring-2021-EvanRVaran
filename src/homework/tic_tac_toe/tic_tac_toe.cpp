#include "tic_tac_toe.h"
#include<iostream>
#include<string>
using std::cin; using std::cout;

// TicTacToeBoard tTTB;

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

void TicTacToeBoard::display_board()const
{
    for(int i = 0; i < 9; i++)
    {
        if(i % 3 == 0)
        {
            cout << "\n";
        }
        cout << pegs[i] + " ";
    }
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