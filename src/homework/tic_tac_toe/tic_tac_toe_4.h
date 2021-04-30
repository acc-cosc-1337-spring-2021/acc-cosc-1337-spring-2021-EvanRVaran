//h
#ifndef TIC_TAC_TOE_4_H
#define TIC_TAC_TOE_4_H

#include "tic_tac_toe.h"
#include<iostream>

class TicTacToe4: public TicTacToeBoard
{
    private:
        bool check_column_win();
        bool check_diagonal_win();
        bool check_row_win();
    public:
        TicTacToe4(): TicTacToeBoard(4)
        {

        };
        TicTacToe4(std::vector<std::string>p, std::string winner):TicTacToeBoard(p, winner){};

};
#endif