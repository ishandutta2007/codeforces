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

int n, V, e, a[305], b[305], xi, yi, dist[305][305];
bool g[305][305];

stack <int> m, l;
bool vis[305];

int ans;
vector <int> ans1, ans2, ans3;

long long dfs2(int i){
   vis[i] = true;
   
   long long ret = b[i] - a[i];
   for(int j = 0; j < n; j++)if(g[i][j] && !vis[j]){
       ret += dfs2(j);
   }
   return ret;
}
void dfs(int i){
    vis[i] = true;
    
    if(a[i] < b[i])l.push(i);
    if(a[i] > b[i])m.push(i);

    for(int j = 0; j < n; j++)if(g[i][j] && !vis[j]){
        dfs(j);
    }
}

void flow(int u, int v, int d){
    ans++;
    
    ans1.push_back(u + 1);
    ans2.push_back(v + 1);
    ans3.push_back(d);
    
    a[u] -= d;
    a[v] += d;
}

void solve(int u, int v, int d){
    if(u == v)return;
    
    int i;
    for(i = 0; i < n; i++)if(g[v][i]){
        if(dist[v][u] == 1 + dist[i][u])break;
    }
    
    if(a[i] >= d){
        flow(i, v, d);
        solve(u, i, d);
    }else{
        int t = a[i];
        
        flow(i, v, t);
        solve(u, i, d);
        flow(i, v, d - t);
    }
}
int main(){
    scanf("%d %d %d", &n, &V, &e);
    
    for(int i = 0; i < n; i++)scanf("%d", &a[i]);
    for(int i = 0; i < n; i++)scanf("%d", &b[i]);
    
    memset(dist, 63, sizeof dist);
    
    while(e--){
        scanf("%d %d", &xi, &yi);
        xi--, yi--;
        
        g[xi][yi] = g[yi][xi] = true;
        dist[xi][yi] = dist[yi][xi] = 1;
    }
    
    for(int i = 0; i < n; i++)
        dist[i][i] = 0;
    for(int k = 0; k < n; k++)
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    
    
    for(int i = 0; i < n; i++)if(!vis[i]){
        if(dfs2(i) != 0){
            printf("NO\n");
            return 0;
        }
    }
    
    memset(vis, 0, sizeof vis);
    for(int i = 0; i < n; i++)if(!vis[i]){
        dfs(i);
        
        
        while(!l.empty() || !m.empty()){
            int u = m.top();
            int v = l.top();
            
            int x = a[u] - b[u];
            int y = b[v] - a[v];
            solve(u, v, min(x, y));
            
            if(a[u] == b[u])m.pop();
            if(a[v] == b[v])l.pop();
        }
    }
    
    printf("%d\n", ans);
    for(int i = 0; i < ans; i++)
        printf("%d %d %d\n", ans1[i], ans2[i], ans3[i]);
    
    return 0;
}