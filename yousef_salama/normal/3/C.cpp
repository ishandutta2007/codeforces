#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <limits.h>
#include <limits>
using namespace std;
bool win(int g[3][3], int player){
    for(int i = 0; i < 3; i++)
        if(g[i][0] == player && g[i][1] == player && g[i][2] == player)return 1;
    for(int i = 0; i < 3; i++)
        if(g[0][i] == player && g[1][i] == player && g[2][i] == player)return 1;
    if(g[0][0] == player && g[1][1] == player && g[2][2] == player)return 1;
    if(g[0][2] == player && g[1][1] == player && g[2][0] == player)return 1;
    return 0;
}
bool tie(int s[3][3]){
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(!s[i][j])return false;
    return true;
}
int main(){
    string s[3];
    for(int i = 0; i < 3; i++)
        cin >> s[i];
    int numX = 0, numO = 0;
    int g[3][3];
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++){
            if(s[i][j] == 'X'){
                g[i][j] = 1;
                numX++;
            }
            else if(s[i][j] == '0'){
                g[i][j] = 2;
                numO++;
            }
            else g[i][j] = 0;
        }
    if(numX - numO > 1 || numO - numX > 0 || win(g, 1) && win(g, 2))cout << "illegal" << endl;
    else if(win(g, 2) && numX > numO)cout << "illegal" << endl;
    else if(win(g, 1) && numX == numO)cout << "illegal" << endl;
    else if(win(g, 1))cout << "the first player won" << endl;
    else if(win(g, 2))cout << "the second player won" << endl;
    else if(tie(g))cout << "draw" << endl;
    else if(numX == numO)cout << "first" << endl;
    else cout << "second" << endl;
}