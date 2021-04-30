#include "tic_tac_toe.h"
#include<iostream>
#include<string>
using std::cin; using std::cout;

TicTacToeBoard::TicTacToeBoard(int size) 
{ 
    pegs.resize(size*size, ""); 
}

TicTacToeBoard::TicTacToeBoard(std::vector<std::string> p, std::string win)
{ 
    pegs = p; 
    winner = win;
}

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
std::vector<std::string> TicTacToeBoard::get_pegs()const
{
    return pegs;
}

bool TicTacToeBoard::check_board_full()
{
    for(size_t k = 0; k < pegs.size(); k++)
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
    for(size_t k = 0; k < pegs.size(); k++)
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
    return false;
} 
bool TicTacToeBoard::check_row_win()
{
    return false;
} 
bool TicTacToeBoard::check_diagonal_win()
{
    return false;
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
    cout << game.pegs.size();

    if(game.pegs.size() == 9)
    {
        for(int i = 0; i < 9; i++)
        {
            if(i % 3 == 0)
            {
                out << "\n";
            }
            out << game.pegs[i] + " "; 
        }
        return out;
    }
    if(game.pegs.size() == 16)
    {
        for(int i = 0; i < 16; i++)
        {
            if(i % 4 == 0)
            {
                out << "\n";
            }
            out << game.pegs[i] + " "; 
        }
        return out;
    }

}
std::istream& operator>>(std::istream& in, TicTacToeBoard& game)
{
    std::string stringInput;
    if(game.pegs.size() == 9)
    {
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
    if(game.pegs.size() == 16)
    {
        cout << "Enter where the current player would like to mark the board (1-16): ";
        in >> stringInput;
        if(stringInput == "1" || stringInput == "2" || stringInput == "3" || stringInput == "4" || stringInput == "5" || stringInput == "6" || stringInput == "7" || stringInput == "8" || stringInput == "9" || stringInput == "10" || stringInput == "11" || stringInput == "12" || stringInput == "13" || stringInput == "14" || stringInput == "15" || stringInput == "16")
        {
            game.mark_board(stoi(stringInput));
            cout << "The board currently looks like this: ";
            cout << game;
            cout << "\n";
        }
        return in;
    }
}