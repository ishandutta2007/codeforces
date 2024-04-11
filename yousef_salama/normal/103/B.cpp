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
int n, m, x, y;
bool g[105][105], v[105];
void dfs(int i){
    v[i] = true;
    for(int j = 0; j < n; j++)
        if(g[i][j] && !v[j])dfs(j);
}
int main(){
    cin >> n >> m;
    for(int itr = 0; itr < m; itr++){
        cin >> x >> y;
        g[x - 1][y - 1] = true;
        g[y - 1][x - 1] = true;
    }
    if(m != n){
        cout << "NO" << endl;
        return 0;
    }
    dfs(0);
    for(int i = 0; i < n; i++)
        if(!v[i]){
            cout << "NO" << endl;
            return 0;
        }
    cout << "FHTAGN!" << endl;
    return 0;
}