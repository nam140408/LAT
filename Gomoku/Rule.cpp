#include <bits/stdc++.h>
using namespace std;
// Who_win is a funtion which shows who wins in a board game.
string who_win(vector<char> *Board_game, vector<double> *Point_board){
    for (int i = 1; i <= 100; i++)
    {
        for (int j = 1; j <= 100; j++)
        {
            if( Point_board[i][j] == (double)5 ) return "The winner is " + Board_game[i][j];
        }
    }
    return "Nobody wins";
}