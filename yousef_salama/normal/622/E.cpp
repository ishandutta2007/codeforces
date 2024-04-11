//In the name of Allah

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
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <assert.h>
#include <complex>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
using namespace std;

int n, xi, yi;
vector <int> g[500005], v;

void dfs(int i, int parent, int d){
    bool leaf = true;
    for(int j = 0; j < g[i].size(); j++){
        int u = g[i][j];
        if(u == parent)continue;
        
        leaf = false;
        dfs(u, i, d + 1);
    }
    if(leaf)v.push_back(d);
}

int main(){
    scanf("%d", &n);
    for(int e = 0; e < (n - 1); e++){
        scanf("%d %d", &xi, &yi);
        xi--, yi--;
        
        g[xi].push_back(yi);
        g[yi].push_back(xi);
    }
    
    
    int r = 0;
    for(int i = 0; i < g[0].size(); i++){
        v.clear();
        dfs(g[0][i], 0, 1);
        
        sort(v.begin(), v.end());
        
        for(int j = 0; j < v.size(); j++){
            if(j == 0)r = max(r, v[j]);
            else{
                v[j] = max(v[j - 1] + 1, v[j]);
                r = max(r, v[j]);
            }
        }
    }
    printf("%d\n", r);
    
    return 0;
}