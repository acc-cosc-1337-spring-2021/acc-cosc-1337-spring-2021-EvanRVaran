//h
#ifndef TIC_TAC_TOE_3_H
#define TIC_TAC_TOE_3_H

#include "tic_tac_toe.h"
#include<iostream>

class TicTacToe3: public TicTacToeBoard
{
    private:
        bool check_column_win();
        bool check_diagonal_win();
        bool check_row_win();

    public:
        TicTacToe3():TicTacToeBoard(3)
        {
        
        };
        TicTacToe3(std::vector<std::string> p, std::string winner):TicTacToeBoard(p, winner){};
 
};
#endif