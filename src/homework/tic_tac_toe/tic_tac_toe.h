//h
#include<iostream>
class TicTacToeBoard
{
    public:
        bool game_over();
        void start_game(std::string first_player);
        void mark_board(int position);
        std::string get_player()const;
        void display_board()const;
        std::string get_winner();

    private:
        void set_next_player();
        bool check_board_full();
        void clear_board();
        bool check_column_win();
        bool check_row_win();
        bool check_diagonal_win();
        void set_winner();
        std::string player;
        std::string pegs[9] = {" "," "," "," "," "," "," "," "," "};
        std::string winner;
};
