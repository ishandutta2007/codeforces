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
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <sstream>
#define oo 1 << 25
using namespace std;
bool v[8][8];
int di[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dj[] = {-1, 1, -2, 2, -2, 2, -1, 1};
string rook, knight;
int main(){
    cin >> rook >> knight;
    memset(v, 0, sizeof v);
    rook[1]--;
    knight[1]--;
    int x = rook[0] - 'a', y = rook[1] - '0';
    for(int i = 0; i < 8; i++)
        v[i][y] = 1;
    for(int i = 0; i < 8; i++)
        v[x][i] = 1;
    x = knight[0] - 'a', y = knight[1] - '0';
    v[x][y] = 1;
    for(int k = 0; k < 8; k++){
        int i = x + di[k], j = y + dj[k];
        if(i >= 0 && i < 8 && j >= 0 && j < 8)
            v[i][j] = 1;
    }
    int ans = 0;
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++){
            bool wrong = v[i][j];
            for(int k = 0; k < 8; k++){
                int x = i + di[k], y = j + dj[k];
                if(x >= 0 && x < 8 && y >= 0 && y < 8)
                    if(x == rook[0] - 'a' && y == rook[1] - '0')wrong = 1;
            }
            if(!wrong)ans++;
        }
    cout << ans << endl;
    return 0;
}