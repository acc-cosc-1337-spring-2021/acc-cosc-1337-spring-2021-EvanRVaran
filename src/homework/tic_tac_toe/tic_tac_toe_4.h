//h
#ifndef TIC_TAC_TOE_4_H
#define TIC_TAC_TOE_4_H

#include "tic_tac_toe.h"

class TicTacToe4: public TicTacToeBoard
{
    private:
        bool check_column_win();
        bool check_diagonal_win();
        bool check_row_win();
    public:
        TicTacToe4(): TicTacToeBoard(4)
        {}

};
#endif