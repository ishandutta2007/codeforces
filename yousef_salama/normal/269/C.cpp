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
#include <sstream>
#include <string.h>
#include <assert.h>
#include <numeric>
using namespace std;

const int MAXN = 200005;

int n, m, a[MAXN], b[MAXN], c[MAXN], wanted[MAXN], mark[MAXN];
vector <int> g[MAXN];

void dfs(int v){
    for(int i = 0; i < g[v].size(); i++){
        int e = g[v][i];
        if(mark[e] == 0){
            if(a[e] == v)mark[e] = 1;
            else mark[e] = 2;
            
            int u;
            if(v == a[e])u = b[e];
            else u = a[e];
            
            wanted[u] -= c[e];
            if(wanted[u] == 0 && u != n - 1)dfs(u);
        }
    }
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &a[i], &b[i], &c[i]);
        a[i]--, b[i]--;
        
        wanted[a[i]] += c[i], wanted[b[i]] += c[i];
        g[a[i]].push_back(i);
        g[b[i]].push_back(i);
    }
    
    for(int i = 0; i < n; i++)
        wanted[i] /= 2;
    
    dfs(0);
    for(int i = 0; i < m; i++)
        printf("%d\n", mark[i] - 1);
    return 0;
}