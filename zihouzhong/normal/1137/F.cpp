#include <bits/stdc++.h>
using namespace std;

template <typename T> struct fenwick_tree {
    int n;
    vector<T> a;
    fenwick_tree(int n = 0) : n(n), a(n + 1) {}

    void add(int p, T v) {
        for (int i = p + 1; i <= n; i += i & -i) a[i] += v;
    }
    T sum(int l, int r) { // [l, r)
        return sum(r) - sum(l);
    }

  private:
    T sum(int p) {
        T ans = 0;
        for (int i = p; i > 0; i -= i & -i) ans += a[i];
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> G(n);
    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v, u--, v--;
        G[u].push_back(v), G[v].push_back(u);
    }
    vector<int> fa(n, -1), sz(n), tid(n), dep(n), top(n), mx(n);
    iota(mx.begin(), mx.end(), 0);
    int rt = n - 1;
    {
        int tim = 0;
        vector son(n, -1);
        auto dfs1 = [&](auto self, int u) -> void {
            sz[u] = 1;
            for (int v : G[u]) if (v != fa[u]) {
                fa[v] = u, dep[v] = dep[u] + 1;
                self(self, v), sz[u] += sz[v];
                mx[u] = max(mx[u], mx[v]);
                if (!~son[u] || sz[v] > sz[son[u]]) son[u] = v;
            }
        };
        auto dfs2 = [&](auto self, int u, int anc) -> void {
            tid[u] = tim++, top[u] = anc;
            if (~son[u]) self(self, son[u], anc);
            for (int v : G[u]) {
                if (v != fa[u] && v != son[u]) self(self, v, v);
            }
        };
        dfs1(dfs1, rt), dfs2(dfs2, rt, rt);
    }
    fenwick_tree<int> T(n + q);
    set<tuple<int, int, int>> S;
    for (int i = 0; i < n; i++) {
        T.add(mx[i], 1);
        S.emplace(tid[i], tid[i], mx[i]);
    }
    auto split = [&](int i) {
        auto it = S.lower_bound({i, 0, 0});
        if (it != S.end() && get<0>(*it) == i) return it;
        auto [l, r, x] = *--it;
        S.erase(it), S.emplace(l, i - 1, x);
        return S.emplace(i, r, x).first;
    };
    auto assign = [&](int l, int r, int x) {
        auto itr = split(r + 1), itl = split(l);
        for (auto it = itl; it != itr; it++) {
            auto &[l, r, x] = *it;
            T.add(x, -(r - l + 1));
        }
        T.add(x, r - l + 1);
        S.erase(itl, itr), S.emplace(l, r, x);
    };
    auto upd = [&](int u, int v, int x) {
        for (; top[u] != top[v]; u = fa[top[u]]) {
            if (dep[top[u]] < dep[top[v]]) swap(u, v);
            assign(tid[top[u]], tid[u], x);
        }
        if (tid[u] > tid[v]) swap(u, v);
        assign(tid[u], tid[v], x);
    };
    auto lca = [&](int u, int v) {
        for (; top[u] != top[v]; u = fa[top[u]]) {
            if (dep[top[u]] < dep[top[v]]) swap(u, v);
        }
        return tid[u] < tid[v] ? u : v;
    };
    vector<int> id(n);
    iota(id.begin(), id.end(), 0);
    auto when = [&](int u) {
        int x = get<2>(*prev(S.lower_bound({tid[u] + 1, 0, 0})));
        return T.sum(0, x) + dep[u] + dep[id[x]] - 2 * dep[lca(u, id[x])];
    };
    while (q--) {
        string op;
        int u, v;
        cin >> op >> u, u--;
        if (op == "up") {
            if (u != rt) upd(u, rt, id.size() - 1);
            assign(tid[u], tid[u], id.size());
            id.push_back(rt = u);
        } else if (op == "when") {
            cout << when(u) + 1 << "\n";
        } else {
            cin >> v, v--;
            cout << (when(u) < when(v) ? u : v) + 1 << "\n";
        }
    }
    return 0;
}