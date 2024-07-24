#include "Combine_lib.cpp"
using namespace std;
void line(int direct, int x, int y, vector<char>* Board_game, vector<fodop>* &Pb){
    char player = Board_game[x][y];
    double cost = -1;
    bool kt = false;
    if(Board_game[x][y] == 'X') cost = 1;
    Pb[x][y].val = 0;
    if(player == Board_game[x][y - 1]){
        Pb[x][y].no4_2 = Pb[x][y - 1].no4_2 + cost;
        Pb[x][y - 1].no4_1 = Pb[x][y].no4_1 + cost;
    }
    if(player == Board_game[x][y + 1]){
        Pb[x][y].no4_1 = Pb[x][y + 1].no4_1 + cost;
        Pb[x][y + 1].no4_2 = Pb[x][y].no4_2 + cost;
    }
    
    if(player != Board_game[x][y - 1] && Board_game[x][y - 1] != ' '){
        Pb[x][y].no4_2 = (- cost) * 0.5;
    }
    if(player != Board_game[x][y + 1] && Board_game[x][y + 1] != ' '){
        Pb[x][y].no4_1 = (- cost) * 0.5;
    }
    //cout << "shit" << endl;
    
    if(direct == 0) kt = true;
    if(Board_game[x][y - 1] != ' ' && (direct == -1 || kt)) line(-1, x, y - 1, Board_game, Pb);
    if(Board_game[x][y + 1] != ' ' && (direct == 1 || kt)) line(1, x, y + 1, Board_game, Pb);

    if(Board_game[x][y - 1] == ' '){
        Pb[x][y - 1].no4_1 += cost;
        Pb[x][y - 1].val = Pb[x][y - 1].no4_1 + Pb[x][y - 1].no4_2; 
    }
    if(Board_game[x][y + 1] == ' '){
        Pb[x][y+1].no4_2 += cost;
        Pb[x][y + 1].val = Pb[x][y].no4_2 + Pb[x][y].no4_1; 
    }
}
// vector<double>* Point_board(int x, int y, vector<char> *Board_game, vector<double> *Pb){
//     line(1, 1, Pb[x][y], x, y, Board_game, Pb);
//}
int main(){
    //freopen("check.inp", "r", stdin);
    freopen("check.out", "w", stdout);
    vector<char>* Board_game = new vector<char>[18];
    
    vector<fodop>* Pb = new vector<fodop>[18];
    for (int i = 1; i <= 17; i++)
    {
        for(int j = 1; j <= 17; j++) Board_game[i].push_back(' ');
    }
    for (int i = 1; i <= 17; i++)
    {
        pair<double, double> ta;
        ta.first = ta.second = 0;
        fodop t;
        t.no1 = ta;
        t.no2 = ta;
        t.no3 = ta;
        t.no4 = ta;
        t.val = 0;
        for(int j = 1; j <= 17; j++) Pb[i].push_back(t);
    }
    Board_game[10][10] = 'X';
    line(0, 10, 10, Board_game, Pb);

    Board_game[10][11] = 'X';
    line(0, 10, 11, Board_game, Pb);

    Board_game[10][13] = 'X';
    line(0, 10, 13, Board_game, Pb);
    // Board_game[10][14] = 'X';
    // line(10, 14, Board_game, Pb);

    //Board_game[10][14] = 'O';
    //line(1, 0, Pb[10][12], 10, 12, Board_game, Pb);
    for (int i = 1; i <= 16; i++)
    {
        for(int j = 1; j <= 16; j++) cout << Pb[i][j].val << " ";
        cout << "\n";
    }

    for (int i = 1; i <= 16; i++)
    {
        for(int j = 1; j <= 16; j++){
            if(Board_game[i][j] != ' ') cout << Board_game[i][j] << " ";
            if(Board_game[i][j] == ' ') cout << "* ";
        }
        cout << "\n";
    }
}