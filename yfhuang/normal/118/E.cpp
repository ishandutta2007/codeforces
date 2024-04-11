#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

int n, m;
const int maxn = 1e5 + 5;
vector<int> G[maxn];
bool vis[maxn];
bool bridge[maxn];
int dp[maxn];
int dep[maxn];
void dfs(int u, int fa, int d){
    vis[u] = true;
    dep[u] = d;
    int upward = 0, downward = 0;
    for(auto v : G[u]){
        if(v == fa)
            continue;
        if(vis[v]){
            if(dep[v] > dep[u]) downward++;
            else upward++;
        }else{
            dfs(v, u, d + 1);
        }        
    }
    dp[u] = upward - downward;
    for(auto v : G[u]){
        if(dep[v] == dep[u] + 1)
            dp[u] += dp[v];
    }
    if(dp[u] == 0){
        bridge[u] = 1;
    }
}

int u[maxn * 3], v[maxn * 3];

int main(){
    cin >> n >> m;
    for(int i = 1;i <= m;i++){
        scanf("%d%d", &u[i], &v[i]);
        G[u[i]].push_back(v[i]);
        G[v[i]].push_back(u[i]);
    }    
    dfs(1, 1, 0);
    bool flag = true;
    for(int i = 2;i <= n;i++){
        if(bridge[i])
            flag = false;
    }
    if(flag){
        for(int i = 1;i <= m;i++){
            if(dep[u[i]] == dep[v[i]] + 1){
                cout << v[i] << " " << u[i] << endl;
            }else if(dep[v[i]] == dep[u[i]] + 1){
                cout << u[i] << " " << v[i] << endl;
            }else{
                if(dep[u[i]] < dep[v[i]]){
                    swap(u[i], v[i]);
                }
                cout << u[i] << " " << v[i] << endl;
            } 
        }
    }else{
        cout << 0 << endl;
    }
    return 0;
}