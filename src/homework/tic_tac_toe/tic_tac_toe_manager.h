//h
#include<iostream>
#include "tic_tac_toe.h"
#include "vector"

class TicTacToeManager
{
    public:
        void save_game(TicTacToeBoard b);
        void get_winner_totals(int& o, int& x, int& t);
        friend std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager);

    private:
        void update_winner_account(std::string winner);
        int x_win = 0;
        int o_win = 0;
        int ties = 0;
        std::vector<TicTacToeBoard> games;
};