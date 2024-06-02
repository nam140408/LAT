#include<bits/stdc++.h>
using namespace std;
char who_win(char a[64][64]){
    for (int i = 1; i <= 64; i++)
    {
        int cont = 1, cont2 = 1;
        for (int j = 2; j <= 64; j++)
        {
            if(a[j][i] == a[j - 1][i]) cont++;
            if(a[i][j] == a[i][j - 1]) cont2++;
            if(cont == 5) return  a[j][i];
            if(cont2 == 5) return a[i][j];
            if(a[j][i] != a[j - 1][i]) cont = 1;
        }
        
    }
    for (int i = 60; i >= 1; i--)
    {
        int cont = 0;
        for (int j = 1; j <= 64 - i + 1; j++)
        {
            
        }
        
        
    }    
}
int main(){
    
}