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
int n, g[105][105], a[105], v[105], d[105];
bool dfs(int value, int i){
    if(a[i] == value)return true;
    v[i] = 1;
    for(int j = 0; j < n; j++)if(!v[j] && g[i][j])
        if(dfs(value, j))return true;
    return false;
}
bool Can(){
    for(int i = 0; i < n; i++){
        memset(v, 0, sizeof v);
        if(!dfs(i + 1, i))return false;
    }
    return true;
}
int main(){
    memset(g, 0, sizeof g);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++){
        cin >> d[i];
        if(i - d[i] >= 0)g[i][i - d[i]] = g[i - d[i]][i] = 1;
        if(i + d[i] < n)g[i][i + d[i]] = g[i + d[i]][i] = 1;
    }
    if(Can())cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}