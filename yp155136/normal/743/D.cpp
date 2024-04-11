#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 200006;
const ll INF = (1ll<<60);

vector<int> G[N];
ll a[N];
ll ans = -INF;

ll dp[2][N];

//dp[0][i] --> root at i's max answer
//dp[1][i] --> select root i's max answer

void dfs(int now,int par) {
    vector<ll> v;
    dp[1][now] = a[now];
    dp[0][now] = -INF;
    for (int i:G[now]) {
        if (i == par) continue;
        dfs(i, now);
        dp[1][now] += max(dp[1][i], -INF);
        dp[0][now] = max(dp[0][now],dp[0][i]);
        v.push_back(dp[0][i]);
    }
    dp[0][now] = max(dp[0][now], dp[1][now]);
    sort(v.begin(), v.end());
    if (v.size() >= 2) {
        reverse(v.begin(), v.end());
        ans = max(ans, v[0] + v[1]);
    }
}

int main () {
    int n; scanf("%d",&n);
    for (int i = 1;i <= n; ++i ) {
        scanf("%lld",&a[i]);
    }
    for (int i = 1; i < n ; ++i)  {
        int u, v; scanf("%d%d",&u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 1);
    if (ans == -INF) puts("Impossible");
    else printf("%lld\n", ans);
}