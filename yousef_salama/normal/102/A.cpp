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
int main(){
    int n, m, a, b;
    cin >> n >> m;
    int p[n];
    for(int i = 0; i < n; i++)
        cin >> p[i];
    int g[n][n];
    memset(g, 0, sizeof g);
    while(m--){
        cin >> a >> b;
        g[a - 1][b - 1] = 1;
        g[b - 1][a - 1] = 1;
    }
    int minX = 1 << 25;
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            for(int k = j + 1; k < n; k++)
                if(g[i][j] && g[i][k] && g[j][k])
                    minX = min(minX, p[i] + p[j] + p[k]);
    if(minX == 1 << 25)cout << -1 << endl;
    else cout << minX << endl;
    return 0;
}