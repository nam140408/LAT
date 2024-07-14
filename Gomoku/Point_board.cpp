#include <bits/stdc++.h>
using namespace std;
pair<int,int> line(int x, int y, vector<char> *Board_game, vector<double> *Pb){
    
}
vector<double>* Point_board(int x, int y, vector<char> *Board_game, vector<double> *Pb){
    int px = x, py = y;
    while(px > 0 || (Board_game[x][y] == Board_game[px][py] && Board_game[x][y] != ' ')){
        px--;
        if(Board_game[px][py] == ' ' && Board_game[px + 1][py] == Board_game[x][y]) Pb[px][py] = line(x, y, Board_game, Pb);
    }
}