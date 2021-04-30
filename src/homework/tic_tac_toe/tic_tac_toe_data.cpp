//cpp
#include "vector"
#include<iostream>
#include <memory>
#include "tic_tac_toe_data.h"
#include<fstream>
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
using namespace std;


void TicTacToeData::save_games(const std::vector<std::unique_ptr<TicTacToeBoard>>& games)
{
    std::ofstream file;
    file.open("TicTacToe_File.txt");

    for(size_t i = 0; i < games.size(); i++)
    {
        for (size_t k = 0; k < (*games[i]).get_pegs().size(); k++)
        {
            file << (*games[i]).get_pegs()[k];
        }
        file << (*games[i]).get_winner() + "\n";
    }
    file.close();
}
std::vector<std::unique_ptr<TicTacToeBoard>> TicTacToeData::get_games()
{
    vector<unique_ptr<TicTacToeBoard>> games;
    std::ifstream file;
    file.open("TicTacToe_File.txt");
    std::string line;
    std::string winner;

    if(file.is_open())
    {
        while(getline(file,line))
        {
            std::vector<std::string> pegs;
            pegs.reserve(100);

            for(size_t i = 1; i < line.size(); i++)
            {
                string newline = "";
                newline = string(1, line[i-1]);
                pegs.push_back(newline);
            }

            winner = line[line.size()-1];
            unique_ptr<TicTacToeBoard> tb;

            if(pegs.size() == 9)
            {
                TicTacToeBoard test = TicTacToeBoard(pegs, winner);
                tb = make_unique<TicTacToe3>(pegs, winner);
            }
            else if(pegs.size() == 16)
            {
                tb = make_unique<TicTacToe4>(pegs, winner);
            }

            games.push_back(move(tb));
            
        }

        file.close();
    }

    return games;
}