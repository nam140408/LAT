#include <bits/stdc++.h>
using namespace std;

vector<char>* Board_game(char c, int x, int y, vector<char> *b){
    b[x][y] = c;
    return b;
}