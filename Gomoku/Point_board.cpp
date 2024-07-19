#include <bits/stdc++.h>
using namespace std;
void line(int direct, int end, int val, int x, int y, vector<char>* Board_game, vector<double>* &Pb){
    if(end == 2) return;
    double cost = -1;
    char player = Board_game[x][y];
    if(Board_game[x][y] == 'X') cost = 1;

    if(Board_game[x][y + direct] == ' '){
        if(Pb[x][y + direct] == 0) Pb[x][y + direct] = cost;
        Pb[x][y + direct] += val;
        if(Board_game[x][y - direct] != ' ' && Board_game[x][y - direct] != player){
            Pb[x][y + direct] = Pb[x][y + direct] - val + 0.5 * (-cost);
            val = 0.5 * cost; 
        }
        else if(Board_game[x][y - direct] != ' ' && Board_game[x][y - direct] == player) val = cost;
        Pb[x][y] = 0;
        end ++;
        line(-direct, end, val, x, y, Board_game, Pb);
    }
    if(Board_game[x][y + direct] != ' ' && Board_game[x][y + direct] == player){
        Pb[x][y] = 0;
        val = cost + val;
        line(direct, end, val, x, y + direct, Board_game, Pb);
    }
    
    if(Board_game[x][y + direct] != ' ' && Board_game[x][y + direct] != player){
        Pb[x][y] = 0;
        val = cost * 0.5;
        line(direct, end, val, x, y + direct, Board_game, Pb);
    }
}
// vector<double>* Point_board(int x, int y, vector<char> *Board_game, vector<double> *Pb){
//     line(1, 1, Pb[x][y], x, y, Board_game, Pb);
//}
int main(){
    freopen("check.inp", "r", stdin);
    freopen("check.out", "w", stdout);
    vector<char>* Board_game = new vector<char>[17];
    vector<double>* Pb = new vector<double>[17];
    for (int i = 1; i <= 16; i++)
    {
        for(int j = 1; j <= 16; j++) Board_game[i].push_back(' ');
    }
    for (int i = 1; i <= 16; i++)
    {
        for(int j = 1; j <= 16; j++) Pb[i].push_back(0);
    }
    Board_game[10][10] = 'X';
    line(1, 0, Pb[10][10], 10, 10, Board_game, Pb);

    Board_game[10][11] = 'X';
    line(1, 0, 0, 10, 11, Board_game, Pb);
    // Board_game[10][13] = 'X';
    // line(1, 0, Pb[10][13], 10, 13, Board_game, Pb);
    // Board_game[10][14] = 'X';
    // line(1, 0, Pb[10][14], 10, 14, Board_game, Pb);
    
    cout << "ok \n";
    //Board_game[10][14] = 'O';
    //line(1, 0, Pb[10][12], 10, 12, Board_game, Pb);
    for (int i = 1; i <= 16; i++)
    {
        for(int j = 0; j <= 15; j++) cout << Pb[i][j] << " ";
        cout << "\n";
    }
}