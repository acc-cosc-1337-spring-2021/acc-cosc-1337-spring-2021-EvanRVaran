#include "tic_tac_toe.h"
#include<iostream>
#include<string>
using std::cin; using std::cout;

// TicTacToeBoard tTTB;

bool TicTacToeBoard::game_over()
{
    return check_board_full();
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
        cout << "Changing to O ";
        player = "O";
    }
    else
    {
        cout << "Changing to X ";
        player = "X";
    }
}