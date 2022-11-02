#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int dp[maxn][2]; // 1 choose 0 not choose
int n;
vector<int> G[maxn];
int ans;

void dfs(int u, int fa){
    dp[u][1] = 1;
    dp[u][0] = 0;
    int son = 0;
    for(auto v : G[u]){
        if(v == fa)
            continue;
        son++;
        dfs(v, u);
    }
    int pre = -1;
    for(int i = 0; i < G[u].size();i++){
        int v = G[u][i];
        if(v == fa)
            continue;
        ans = max(ans, dp[u][1] + dp[v][0]);
        dp[u][1] = max(dp[u][1], dp[v][0] + 1);
        ans = max(ans, max(dp[v][0], dp[v][1]) + son - 1 + (fa != u));
        if(pre != -1){
            ans = max(ans, dp[u][0] + max(dp[v][0], dp[v][1]) + son - 2 + (fa != u));
        }
        pre = max(pre, max(dp[v][0], dp[v][1]));
        dp[u][0] = pre;
    }
    if(son >= 1)
        dp[u][0] += son - 1;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1;i < n;i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }    
    ans = 0;
    dfs(1, 1);
    cout << ans << endl;
    return 0;
}