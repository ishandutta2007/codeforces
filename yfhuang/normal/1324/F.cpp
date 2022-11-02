#include <bits/stdc++.h>
using namespace std;

int n;
const int maxn = 2e5 + 5;

int a[maxn];
int dp[maxn];
int dp1[maxn];
vector<int> G[maxn];

void dfs1(int u, int fa){
    dp[u] = (a[u] == 1) - (a[u] == 0);
    for(auto v : G[u]){
        if(v == fa)
            continue;
        dfs1(v, u);
        dp[u] += max(0, dp[v]);
    }
}

void dfs2(int u, int fa){
    int now = (a[u] == 1) - (a[u] == 0);
    now += max(0, dp1[u]);
    int pre = 0;
    for(auto v : G[u]){
        if(v == fa)
            continue;
        dp1[v] += pre;
        pre += max(0, dp[v]);
    }
    int suf = 0;
    for(int i = G[u].size() - 1;i >= 0;i--){
        int v = G[u][i];
        if(v == fa)
            continue;
        dp1[v] += suf + now;
        suf += max(0, dp[v]);
        dfs2(v, u);
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i < n;i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1(1, 1);
    dfs2(1, 1);
    for(int i = 1;i <= n;i++){
        //cout << i << " " << dp[i] << " " << dp1[i] << endl;
        cout << dp[i] + max(0, dp1[i]) << " ";
    }
    return 0;
}