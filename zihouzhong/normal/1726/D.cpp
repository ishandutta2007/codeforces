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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> res(m);
    dsu T(n);
    vector<tuple<int, int, int>> mst, others;
    set<int> S;
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v, u--, v--;
        if (T.merge(u, v)) {
            mst.emplace_back(u, v, i);
        } else {
            S.insert(u), S.insert(v);
            others.emplace_back(u, v, i);
        }
    }
    if (others.size() < 3 || S.size() > 3) {
        for (auto &[u, v, i] : others) {
            res[i] = 1;
        }
    } else {
        auto [u1, v1, i1] = others[0];
        auto [u2, v2, i2] = others[1];
        auto [u3, v3, i3] = others[2];
        res[i1] = res[i2] = 1;
        T = n, T.merge(u3, v3);
        for (auto &[u, v, i] : mst) {
            if (!T.merge(u, v)) { res[i] = 1; break; }
        }
    }
    for (int x : res) {
        cout << x;
    }
    cout << "\n";
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