#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
using namespace std;

const int maxn = 3005;

int n;

vector<int> G[maxn];
int par[maxn][maxn];
int sz[maxn][maxn];
void dfs(int u, int fa, int root){
    par[root][u] = fa;
    sz[root][u] = 1;
    for(auto v : G[u]){
        if(v == fa)
            continue;
        dfs(v, u, root);
        sz[root][u] += sz[root][v];
    }
}

long long dp[maxn][maxn];

long long Dp(int u, int v){
    //cout << u << " " << v << endl;
    if(u == v)
        return dp[u][v] = 0;
    if(dp[u][v] != -1)
        return dp[u][v];
    dp[u][v] = sz[u][v] * sz[v][u] + max(Dp(u, par[u][v]), Dp(par[v][u],v));
    return dp[u][v];
}

int main(){
    cin >> n;
    for(int i = 1;i <= n - 1;i++){
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i = 1;i <= n;i++){
        dfs(i, i, i);
    }
    //cout << "#" << endl;
    memset(dp, -1, sizeof(dp));
    long long ans = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            ans = max(ans, Dp(i, j));
        }
    }
    cout << ans << endl;
    return 0;
}