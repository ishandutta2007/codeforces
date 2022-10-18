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
#include <unordered_map>

using namespace std;

int n, k, ki[200005], ai, ui, vi;
vector <int> G[200005];

long long X[200005];
long long dfs(int i, int d, int par){
    long long ret = (long long)ki[i] * d;
    X[i] = ki[i];
    
    for(int j = 0; j < G[i].size(); j++){
        int u = G[i][j];
        if(u != par){
            ret += dfs(u, d + 1, i);
            X[i] += X[u];
        }
    }
    return ret;
}

long long solve(int i, long long r, int par){
    long long ret = 0;
    
    vector <int> v;
    v.push_back(ki[i]);
    v.push_back(2 * k - X[i]);
    
    for(int j = 0; j < G[i].size(); j++){
        int u = G[i][j];
        if(u != par){
            ret = max(ret, solve(u, r + (2 * k - X[u]) - X[u], i));
            v.push_back(X[u]);
        }
    }
    
    bool f = true;
    for(int j = 0; j < v.size(); j++)
        if(2 * k - v[j] < v[j])f = false;
    if(f)ret = max(ret, r);
    
    return ret;
}
int main(){
    scanf("%d %d", &n, &k);
    for(int i = 0; i < 2 * k; i++){
        scanf("%d", &ai);
        ki[--ai]++;
    }
    
    for(int e = 0; e < (n - 1); e++){
        scanf("%d %d", &ui, &vi);
        ui--, vi--;
        
        G[ui].push_back(vi);
        G[vi].push_back(ui);
    }
    
    long long r = dfs(0, 0, -1);
    printf("%I64d\n", solve(0, r, -1));
    
    return 0;
}