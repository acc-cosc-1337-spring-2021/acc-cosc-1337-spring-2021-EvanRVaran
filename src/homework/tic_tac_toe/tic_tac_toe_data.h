//h
#ifndef TIC_TAC_TOE_DATA_H
#define TIC_TAC_TOE_DATA_H

#include "vector"
#include<iostream>
#include <memory>
#include "tic_tac_toe.h"

class TicTacToeData
{
    public:
        void save_games(const std::vector<std::unique_ptr<TicTacToeBoard>>& games); 
        std::vector<std::unique_ptr<TicTacToeBoard>> get_games();
};

#endif