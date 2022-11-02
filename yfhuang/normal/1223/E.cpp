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

const int maxn = 5e5 + 5;
typedef pair<int, int> pii;
typedef long long LL;
vector<pii> G[maxn];

int q, n, k;

LL dp[maxn][2];

void dfs(int u, int fa){
    //cout << u << " " << fa << endl;
    LL base = 0; 
    vector<LL> tmp;
    for(auto x : G[u]){
        int v = x.first;
        int len = x.second;
        if(v == fa)
            continue;
        dfs(v, u); 
        base += dp[v][0];
        tmp.push_back(dp[v][1] + len - dp[v][0]);
    }
    dp[u][0] = base;
    dp[u][1] = base;
    sort(tmp.begin(), tmp.end());
    int m = tmp.size();
    for(int i = 0;i < min(k, m);i++){
        dp[u][0] = max(dp[u][0], dp[u][0] + tmp[m - 1 - i]);
        if(i < k - 1)
            dp[u][1] = max(dp[u][1], dp[u][1] + tmp[m - 1 - i]); 
    }
}

int main(){
    cin >> q;
    while(q--){
        cin >> n >> k;
        for(int i = 1;i <= n;i++){
            G[i].clear();
        }
        for(int i = 1;i < n;i++){
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            G[u].push_back(make_pair(v, w));
            G[v].push_back(make_pair(u, w));
        }
        dfs(1, 1);
        cout << max(dp[1][0], dp[1][1]) << endl;
    }
    return 0;
}