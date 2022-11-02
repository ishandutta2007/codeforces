#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10;

int n, t[N], h[N], a[N], b[N];

ll ans, f[N], g[N];

bool vis[N];

vector <int> e[N];

void dfs_(int u, int fa) {
    vector <ll> dp;
    vis[u] = 1;

    ll sum = 0;

    for (int v : e[u]) {
        if (v == fa) {
            continue;
        }

        dfs_(v, u);
    }

    for (int v : e[u]) {
        if (v == fa) {
            continue;
        }

        sum += f[v];
        dp.push_back(g[v] - f[v]);
    }

    sort(dp.begin(), dp.end());
    reverse(dp.begin(), dp.end());

    int m = dp.size();

    if (fa) {
        f[u] = 1ll*t[u]*min(a[u] + m, b[u] + 1) + sum;
        g[u] = 1ll*t[u]*min(a[u] + m + 1, b[u]) + sum;
        ll val = sum;

        for (int i = 0; i < m; i++) {
            val += dp[i];
            f[u] = max(f[u], val + 1ll*t[u]*min(a[u] + m - i - 1, b[u] + 2 + i));
            g[u] = max(g[u], val + 1ll*t[u]*min(a[u] + m - i, b[u] + 1 + i));
        }
    } else {
        ll res = sum + 1ll*t[u]*min(a[u] + m, b[u]), val = sum;

        for (int i = 0; i < m; i++) {
            val += dp[i];
            res = max(res, val + 1ll*t[u]*min(a[u] + m - i - 1, b[u] + i + 1));
        }

        ans -= res;
    }
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &t[i]);
    }

    for (int i = 1; i <= n; i++) {
        scanf("%d", &h[i]);
    }

    for (int u, v, i = 1; i < n; i++) {
        scanf("%d%d", &u, &v);

        if (h[u] > h[v]) {
            swap(u, v);
        }

        if (h[u] == h[v]) {
            e[u].push_back(v);
            e[v].push_back(u);
        } else {
            a[u]++;
            b[v]++;
        }

        ans += t[u] + t[v];
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs_(i, 0);
        }
    }

    printf("%lld\n", ans);
}