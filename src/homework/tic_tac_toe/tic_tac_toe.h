//h
#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include "vector"
#include<iostream>
class TicTacToeBoard
{
    protected:
        virtual bool check_column_win();
        virtual bool check_row_win();
        virtual bool check_diagonal_win();
        std::vector<std::string> pegs; 

    public:
        bool game_over();
        void start_game(std::string first_player);
        void mark_board(int position);
        std::string get_player()const;
        std::string get_winner();
        friend std::ostream& operator<<(std::ostream& out, const TicTacToeBoard& game);
        friend std::istream& operator>>(std::istream& in, TicTacToeBoard& game);
        TicTacToeBoard(){}
        TicTacToeBoard(int size) { pegs.resize(size*size, ""); }

    private:
        void set_next_player();
        bool check_board_full();
        void clear_board();
        void set_winner();
        std::string player;
        std::string winner;

};
#endif
