#include <bits/stdc++.h>
using namespace std;

template <class comp = less<>> struct rmq {
    vector<vector<int>> st;
    rmq(const vector<int> &arr) : st(__lg(arr.size()) + 1) {
        st[0] = arr;
        for (int k = 1; k < st.size(); k++) {
            st[k] = st[k - 1];
            for (int i = 0; i + (1 << k) <= st[k].size(); i++) {
                int x = st[k - 1][i + (1 << (k - 1))];
                st[k][i] = comp()(st[k][i], x) ? st[k][i] : x;
            }
        }
    }

    int query(int l, int r) {
        int k = __lg(r - l + 1);
        int x = st[k][l], y = st[k][r - (1 << k) + 1];
        return comp()(x, y) ? x : y;
    }
};

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
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m, q;
        cin >> n >> m >> q;
        dsu T(n + m);
        vector<vector<int>> G(n + m);
        for (int i = 0, u, v; i < m; i++) {
            cin >> u >> v, u--, v--;
            u = T.find(u), v = T.find(v);
            if (u == v) continue;
            G[n + i] = {u, v};
            T.merge(n + i, u), T.merge(n + i, v);
        }
        int rt = T.find(0), tim = 0;
        vector<int> tid(n + m), mp(n + m), dep(n + m);
        vector<vector<int>> par(20, vector<int>(n + m, -1));
        auto dfs = [&](auto self, int u) -> void {
            mp[tid[u] = tim++] = u;
            for (int v : G[u]) {
                par[0][v] = u, dep[v] = dep[u] + 1;
                self(self, v);
            }
        };
        dfs(dfs, rt), tid.resize(n);
        for (int k = 1; k < 20; k++) {
            par[k] = par[k - 1];
            for (int i = 0; i < n + m; i++) {
                if (~par[k][i]) par[k][i] = par[k - 1][par[k][i]];
            }
        }
        auto lca = [&](int u, int v) {
            if (dep[u] < dep[v]) swap(u, v);
            for (int i = 19; ~i; i--) {
                if (~par[i][u] && dep[par[i][u]] >= dep[v]) u = par[i][u];
            }
            if (u == v) return u;
            for (int i = 19; ~i; i--) {
                if (~par[i][u] && ~par[i][v] && par[i][u] ^ par[i][v]) {
                    u = par[i][u], v = par[i][v];
                }
            }
            return par[0][u];
        };
        rmq<> mn(tid);
        rmq<greater<>> mx(tid);
        while (q--) {
            int l, r;
            cin >> l >> r, l--, r--;
            int u = mp[mn.query(l, r)], v = mp[mx.query(l, r)];
            cout << max(0, lca(u, v) - n + 1) << " ";
        }
        cout << "\n";
    }
    return 0;
}