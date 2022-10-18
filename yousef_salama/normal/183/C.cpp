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
using namespace std;

const int MAXN = 100005;

int n, m, ai, bi, k;
vector < pair <int, bool> > g[MAXN];

int color[MAXN];
bool vis[MAXN];

void dfs(int v){
    vis[v] = true;
    for(int i = 0; i < g[v].size(); i++){
        int u = g[v][i].first;
        bool inverse = g[v][i].second;
        
        int cu;
        if(inverse)cu = color[v] - 1;
        else cu = color[v] + 1;
          
        if(!vis[u]){
            color[u] = cu;
            dfs(u);
        }else k = __gcd(k, abs(cu - color[u]));
    }
}
int main(){
    scanf("%d %d", &n, &m);
    while(m--){
        scanf("%d %d", &ai, &bi);
        ai--, bi--;
        
        g[ai].push_back(make_pair(bi, false));
        g[bi].push_back(make_pair(ai, true));
    }
    
    k = 0;
    
    memset(vis, false, sizeof vis);
    for(int i = 0; i < n; i++)if(!vis[i]){
        color[i] = 0;
        dfs(i);
    }
    
    printf("%d\n", k == 0 ? n : k);
    
    return 0;
}