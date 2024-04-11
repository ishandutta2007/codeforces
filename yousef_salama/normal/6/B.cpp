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
using namespace std;
int main(){
    int n, m;
    char c;
    cin >> n >> m >> c;
    string g[n];
    for(int i = 0; i < n; i++)
        cin >> g[i];
    int di[] = {1, -1, 0, 0};
    int dj[] = {0, 0, -1, 1};
    int cnt = 0;
    set <char> s;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)if(g[i][j] == c)
            for(int k = 0; k < 4; k++){
                int x = i + di[k], y = j + dj[k];
                if(x < n && x >= 0 && y < m && y >= 0)
                    if(g[x][y] != c && g[x][y] != '.' && !s.count(g[x][y])){
                        cnt++;
                        s.insert(g[x][y]);
                    }
            }
    cout << cnt << endl;
    return 0;
}