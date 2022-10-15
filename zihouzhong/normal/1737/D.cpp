#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector mn(n, vector(n, INT_MAX)), d(n, vector(n, (int)1e9));
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        mn[u][v] = min(mn[u][v], w), d[u][v] = 1;
        swap(u, v);
        mn[u][v] = min(mn[u][v], w), d[u][v] = 1;
    }
    for (int i = 0; i < n; i++) {
        d[i][i] = 0;
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    vector f(n, vector<int>(n));
    vector<tuple<int, int, int>> ord;
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            f[u][v] = d[0][u] + d[n - 1][v] + 1;
            f[u][v] = min(f[u][v], d[0][u] + d[n - 1][u] + 2);
            ord.emplace_back(f[u][v], u, v);
        }
    }
    sort(ord.begin(), ord.end());
    queue<pair<int, int>> Q;
    vector inq(n, vector<bool>(n));
    for (auto [_, u, v] : ord) {
        Q.emplace(u, v), inq[u][v] = 1;
    }
    while (!Q.empty()) {
        auto [u, v] = Q.front(); Q.pop();
        inq[u][v] = 0;
        auto upd = [&](int i, int j, int y) {
            if (f[i][j] > y) {
                f[i][j] = y;
                if (!inq[i][j]) Q.emplace(i, j);
            }
        };
        upd(v, u, f[u][v]);
        for (int i = 0; i < n; i++) {
            if (mn[i][v] != INT_MAX) upd(u, i, f[u][v] + 1);
            if (mn[u][i] != INT_MAX) upd(i, v, f[u][v] + 1);
        }
    }
    long long ans = LLONG_MAX;
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if (mn[u][v] == INT_MAX) continue;
            ans = min(ans, 1LL * mn[u][v] * f[u][v]);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}