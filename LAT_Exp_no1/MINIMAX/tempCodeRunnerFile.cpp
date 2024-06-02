#include <bits/stdc++.h>
using namespace std;
#define int long long
class Tree{
public:
    int x, y, val;
    vector<Tree> node;  
    Tree(int x, int y, int val){
        this->x = x;
        this->y = y;
        this->val = val;
    }  
};
void add_node(Tree node_adding, int level_now, int level_need, Tree &a){
    if(level_now == level_need && level_now == 0){
        a.x = node_adding.x;
        a.y = node_adding.y;
        a.val = node_adding.val;
    }
    else if(level_now == level_need && level_now != 0) a.node.push_back(node_adding);
    else{
        if(level_now > 0) return add_node(node_adding, level_now + 1, level_need, a.node[0]);
        else return add_node(node_adding, level_now + 1, level_need, a);
    }
}
Tree Print_node_in_one_level(int level_now, int level_need, Tree a){
    if(level_now == level_need) return a;
    else{
        if(level_now > 0) return Print_node_in_one_level(level_now + 1, level_need, a.node[0]);
        else return Print_node_in_one_level(level_now + 1, level_need, a);
    }
}

void Create_height_node(int height_now, int height_need, Tree &a){
    if(height_now != height_need){
        a.node.push_back(Tree(0,0,0));
        Create_height_node(height_now + 1, height_need, a.node[0]);
    }
}
signed main(){
    freopen("Minimax.INP","r",stdin);
    freopen("Minimax.OUT","w",stdout);
    int height, quantity;
    cin >> height >> quantity;
    Tree a = Tree(0,0,0);
    Create_height_node(0,height,a);
    //Tree b = Tree(-1,0,0);
    //a = b;
    //add_node(Tree(1,1,0), 0, 1, a);
    for (int i = 0; i <= height; i++)
    {
        /*if(i == 0){
            int x, y;
            cin >> x >> y;
            a = Tree(x,y,0);
            Create_height_node(0,height, a);
            continue;
        }*/
        for (int j = 1; j <= pow(quantity,i); j++)
        {
            int x, y;
            cin >> x >> y;
            add_node(Tree(x,y,0), 0, i, a);
        }
    }
    cout << a.x << " - " << a.y << endl;
    for (int i = 1; i <= height; i++)
    {
        for (int j = 1; j <= pow(quantity,i); j++)
        {
            Tree print = Print_node_in_one_level(0,i,a);
            cout << print.node[j].x << " - " << print.node[j].y << " ";
        }
        cout << endl;
    }
}
