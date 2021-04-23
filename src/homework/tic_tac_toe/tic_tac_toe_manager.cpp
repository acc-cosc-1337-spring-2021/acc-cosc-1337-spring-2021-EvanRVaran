#include "tic_tac_toe_manager.h"
#include<iostream>
#include<string>
#include<vector>
using std::cin; using std::cout;

void TicTacToeManager::get_winner_totals(int& o, int& x, int& t)
{
    o = o_win;
    x = x_win;
    t = ties;
}

void TicTacToeManager::save_game(std::unique_ptr<TicTacToeBoard>& b)
{
    update_winner_count(b -> get_winner());
    games.push_back(std::move(b));
}

void TicTacToeManager::update_winner_count(std::string winner)
{
    if(winner == "X")
    {
        x_win++;
    }
    else if(winner == "O")
    {
        o_win++;
    }
    else
    {
        ties++;
    }
}

std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager)
{
    cout << "All boards that have been played: ";
    for(int i= 0; i < manager.games.size(); i++)
    {
        out << *manager.games[i];
        cout << "\n";
    }
    return out;
}
