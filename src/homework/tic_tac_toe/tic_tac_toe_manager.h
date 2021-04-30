//h
#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H

#include<iostream>
#include "tic_tac_toe.h"
#include "vector"
#include <memory>
#include "tic_tac_toe_data.h"

class TicTacToeManager
{
    public:
        void save_game(std::unique_ptr<TicTacToeBoard>& b);
        void get_winner_totals(int& o, int& x, int& t);
        friend std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager);
        TicTacToeManager() = default;
        TicTacToeManager(TicTacToeData &d);
        ~TicTacToeManager();

    private:
        void update_winner_count(std::string winner);
        int x_win = 0;
        int o_win = 0;
        int ties = 0;
        std::vector<std::unique_ptr<TicTacToeBoard>> games;
        TicTacToeData data;
};
#endif