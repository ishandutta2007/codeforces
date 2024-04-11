#include <bits/stdc++.h>
using namespace std;

int k, n;

const int maxn = 1e6 + 5;
int dep[maxn];
int dp[maxn][2];
int dis[maxn];
int pre[maxn], suf[maxn];
vector<int> G[maxn];

void dfs(int u, int d){
    dep[u] = d; 
    dis[u] = 1e9;
    if(G[u].size() == 0){
        dis[u] = d;
        dp[u][0] = 1;
        dp[u][1] = 1;
        return;
    }
    for(auto v : G[u]){
        dfs(v, d + 1);
        dis[u] = min(dis[u], dis[v]);
    }
    pre[0] = 0;
    int sz = G[u].size();
    suf[sz + 1] = 0;
    for(int i = 1;i <= sz;i++){
        int v = G[u][i - 1];
        int val = 0;
        if(dis[v] - d <= k){
            val = dp[v][0]; 
        }
        pre[i] = pre[i - 1] + val;
    }
    dp[u][1] = 0;
    for(int i = sz;i >= 1;i--){
        int v = G[u][i - 1];
        int val = 0;
        if(dis[v] - d <= k){
            val = dp[v][0];
        }
        suf[i] = suf[i + 1] + val;
        dp[u][1] = max(dp[u][1], pre[i - 1] + suf[i + 1] + dp[v][1]);
    }
    dp[u][0] = pre[sz];
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for(int i = 2;i <= n;i++){
        int fa;
        cin >> fa;
        G[fa].push_back(i);
    }
    dfs(1, 1);
    //for(int i = 1;i <= n;i++){
    //    cout << dis[i] << " " << dp[i][0] << " " << dp[i][1] << endl;
    //}
    cout << dp[1][1] << endl;
    return 0;
}