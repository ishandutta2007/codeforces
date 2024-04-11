#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> g[200001];
int f[200001][20];
bool done[200001];
int h[200001];
void dfs(int u) {
    done[u] = 1;
    for (int i = 0; f[f[u][i]][i]; i++) f[u][i + 1] = f[f[u][i]][i];
    for (auto&& v : g[u]) {
        if (done[v]) continue;
        h[v] = h[u] + 1;
        f[v][0] = u;
        dfs(v);
    }
}

int lca(int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    for (int i = __lg(h[u] - h[v]); i >= 0; i--) {
        if (h[f[u][i]] >= h[v]) u = f[u][i];
    }
    if (u == v) return u;
    for (int i = __lg(h[u]); i >= 0; i--) {
        if (f[u][i] != f[v][i]) {
            u = f[u][i];
            v = f[v][i];
        }
    }
    return f[u][0];
}
int dist(int u, int v) { return h[u] + h[v] - h[lca(u, v)] * 2; }

bool between(int x, int u, int r) {
    if (h[x] > h[u] || h[x] < h[r]) return false;
    int d = dist(u, x) + dist(r, x);
    return d == (h[u] - h[r]);
}

vector<int> query;
void solve() {
    cin >> n;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    h[1] = 1;
    dfs(1);
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int k;
        cin >> k;
        query.resize(k);
        for (auto&& x : query) cin >> x;
        int u = query[0];
        pair<int, int> far = {0, u};
        for (auto&& x : query) far = max(far, {dist(u, x), x});
        u = far.second;
        far = {0, u};
        for (auto&& x : query) far = max(far, {dist(u, x), x});
        int v = far.second;
        int r = lca(u, v);
        for (auto&& x : query) {
            if (between(x, u, r) || between(x, v, r)) continue;
            cout << "NO\n";
            goto next_i;
        }
        cout << "YES\n";
    next_i:;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}