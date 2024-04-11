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
#include <string.h>
using namespace std;
int main(){
//    freopen("a.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    string g[n];
    for(int i = 0; i < n; i++)
        cin >> g[i];
    int di[] = {0, 0, 1, -1};
    int dj[] = {1, -1, 0, 0};
    int cnt = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)if(g[i][j] == 'W'){
            for(int k = 0; k < 4; k++){
                int x = i + di[k], y = j + dj[k];
                if(x < n && x >= 0 && y < m && y >= 0){
                    if(g[x][y] == 'P'){
                        cnt++;
                        break;
                    }
                }
            }
        }
    cout << cnt << endl;
    return 0;
}