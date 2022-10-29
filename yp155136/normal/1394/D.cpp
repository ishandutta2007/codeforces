#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = (1ll << 40);
const int N = 200006;

ll t[N], h[N];
ll dp[2][N];

vector<int> G[N];

ll final_ans = INF;

void dfs(int now, int par) {
    vector<int> sons;
    for (int i: G[now]) {
        if (i != par) {
            sons.push_back(i);
            dfs(i, now);
        }
    }
    if ((int)sons.size() == 0) {
        dp[0][now] = dp[1][now] = t[now];
    }
    else if (now != par) {
        // set impossible
        priority_queue<ll, vector<ll>, greater<ll> > pq;
        int n = (int)sons.size();
        for (int i: sons) {
            if (h[now] > h[i]) {
                dp[1][i] = INF;
            }
            if (h[now] < h[i]) {
                dp[0][i] = INF;
            }
            // cerr << "i = " << i << " , dp0 " << dp[0][i] << " , dp1 = " << dp[1][i] << endl;
        }
        // calculate dp[0][now]
        dp[0][now] = INF;
        while (!pq.empty()) pq.pop();
        ll sum = 0;
        for (int i: sons) {
            sum += dp[0][i];
            pq.push(dp[1][i] - dp[0][i]);
        }
        for (int _0 = n; _0 >= 0; --_0) {
            int _1 = n - _0 + 1;
            dp[0][now] = min(dp[0][now], sum + max(_0, _1) * t[now]);
            if (!pq.empty()) {
                sum += pq.top();
                pq.pop();
            }
        }
        // calculate dp[1][now]
        dp[1][now] = INF;
        while (!pq.empty()) pq.pop();
        sum = 0;
        for (int i: sons) {
            sum += dp[0][i];
            pq.push(dp[1][i] - dp[0][i]);
        }
        for (int _0 = n; _0 >= 0; --_0) {
            int _1 = n - _0;
            // cerr << "_0 = " << _0 << " , sum = " << sum << endl;
            dp[1][now] = min(dp[1][now], sum + max(_0 + 1, _1) * t[now]);
            if (!pq.empty()) {
                sum += pq.top();
                pq.pop();
            }
        }
    }
    else {
        final_ans = INF;
        // priority_queue<ll> pq;
        priority_queue<ll, vector<ll>, greater<ll> > pq;
        int n = (int)sons.size();
        for (int i: sons) {
            if (h[now] > h[i]) {
                dp[1][i] = INF;
            }
            if (h[now] < h[i]) {
                dp[0][i] = INF;
            }
        }
        // calculate dp[0][now]
        while (!pq.empty()) pq.pop();
        ll sum = 0;
        for (int i: sons) {
            sum += dp[0][i];
            pq.push(dp[1][i] - dp[0][i]);
        }
        for (int _0 = n; _0 >= 0; --_0) {
            int _1 = n - _0;
            final_ans = min(final_ans, sum + max(_0, _1) * t[now]);
            if (!pq.empty()) {
                sum += pq.top();
                pq.pop();
            }
        }
    }
    // cerr << "now = " << now << " , dp0 = " << dp[0][now] << " , dp1 = " << dp[1][now] << endl;
}

int main () {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &t[i]);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &h[i]);
    }
    for (int i = 1; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(1, 1);
    printf("%lld\n", final_ans);
}