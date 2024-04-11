#include <bits/stdc++.h>
using namespace std;

struct dsu {
    vector<int> fa, sz;
    dsu(int n) : fa(n), sz(n, 1) { iota(fa.begin(), fa.end(), 0); }

    int find(int x) {
        while (x != fa[x]) x = fa[x] = fa[fa[x]];
        return x;
    }
    bool same(int x, int y) { return find(x) == find(y); }
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        sz[x] += sz[y], fa[y] = x;
        return true;
    }
    int size(int x) { return sz[find(x)]; }

    vector<vector<int>> groups() {
        vector<vector<int>> res(fa.size());
        for (int i = 0; i < fa.size(); i++) {
            res[find(i)].push_back(i);
        }
        res.erase(remove_if(res.begin(), res.end(),
            [&](const auto &v) { return v.empty(); }), res.end());
        return res;
    }
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<array<int, 2>>> G(n);
    vector<array<int, 2>> E(m);
    for (int i = 0; i < m; i++) {
        cin >> E[i][0] >> E[i][1], E[i][0]--, E[i][1]--;
        G[E[i][0]].push_back({E[i][1], i});
        G[E[i][1]].push_back({E[i][0], i});
    }
    vector<bool> mark(m);
    dsu T(n);
    for (int i = 0; i < m; i++) {
        mark[i] = T.merge(E[i][0], E[i][1]);
    }
    string res(n, '1');
    vector<int> fa(n, -1), dep(n);
    auto dfs = [&](auto self, int u) -> void {
        if (u) dep[u] = dep[fa[u]] + 1;
        for (auto &e : G[u]) if (e[0] ^ fa[u]) {
            if (mark[e[1]]) fa[e[0]] = u, self(self, e[0]);
        }
    };
    dfs(dfs, 0);
    vector<vector<int>> par(20, vector<int>(n, -1));
    par[0] = fa;
    for (int i = 1; i < 20; i++) {
        for (int j = 0; j < n; j++) {
            par[i][j] = par[i - 1][j];
            if (~par[i][j]) par[i][j] = par[i - 1][par[i][j]];
        }
    }
    auto jump = [&](int x, int d) {
        while (d && ~x) {
            int i = __builtin_ctz(d);
            x = par[i][x], d ^= 1 << i;
        }
        return x;
    };
    vector<int> inc(n);
    int need = 0;
    for (int i = 0; i < m; i++) if (!mark[i]) {
        need++;
        int u = E[i][0], v = E[i][1];
        if (dep[u] < dep[v]) swap(u, v);
        if (v == jump(u, dep[u] - dep[v])) {
            inc[u]++;
            inc[0]++, inc[jump(u, dep[u] - dep[v] - 1)]--;
        } else {
            inc[u]++, inc[v]++;
        }
    }
    auto down = [&](auto self, int u) -> void {
        if (inc[u] ^ need) res[u] = '0';
        for (auto &e : G[u]) if (e[0] ^ fa[u]) {
            if (mark[e[1]]) inc[e[0]] += inc[u], self(self, e[0]);
        }
    };
    down(down, 0);
    cout << res << "\n";
    return 0;
}