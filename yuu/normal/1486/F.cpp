#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> g[300001];
int h[300001];
int f[300001][20];

void dfs(int u) {
    for (auto&& v : g[u])
        if (h[v]) {
            swap(v, g[u].back());
            g[u].pop_back();
            break;
        }
    for (int i = 0; f[f[u][i]][i]; i++) f[u][i + 1] = f[f[u][i]][i];
    for (auto&& v : g[u]) {
        h[v] = h[u] + 1;
        f[v][0] = u;
        dfs(v);
    }
}

// lca, first, second
tuple<int, int, int> get_lca(int u, int v) {
    if (u == v) return {u, u, u};
    if (h[u] < h[v]) swap(u, v);
    for (int i = __lg(h[u] - h[v]); i >= 0; i--)
        if (h[f[u][i]] > h[v]) u = f[u][i];
    if (h[u] > h[v]) {
        if (f[u][0] == v) return {v, u, u};
        else u = f[u][0];
    }
    for (int i = __lg(h[u]); i >= 0; i--) {
        if (f[u][i] != f[v][i]) {
            u = f[u][i];
            v = f[v][i];
        }
    }
    return {f[u][0], u, v};
}
int single[300001];
vector<pair<int, int>> lca[300001];
int up[300001];
int64_t ans = 0;
map<int, int> single_lca_count;
map<pair<int, int>, int> pair_lca_count;
int64_t lca_count;
void remove_pairs(int u, int v) {
    if (u > v) swap(u, v);
    if (u < v) {
        lca_count -= single_lca_count[u];
        lca_count -= single_lca_count[v];
        lca_count += pair_lca_count[{u, v}];
    } else {
        lca_count -= single_lca_count[u];
    }
}

void readd_pairs(int u, int v) {
    if (u > v) swap(u, v);
    if (u < v) {
        lca_count += single_lca_count[u];
        lca_count += single_lca_count[v];
        lca_count -= pair_lca_count[{u, v}];
    } else {
        lca_count += single_lca_count[u];
    }
}

void clear() {
    lca_count = 0;
    single_lca_count.clear();
    pair_lca_count.clear();
}

void add_pair(int u, int v) {
    if (u > v) swap(u, v);
    lca_count++;
    single_lca_count[u]++;
    if (u != v) {
        single_lca_count[v]++;
        pair_lca_count[{u, v}]++;
    }
}
void process(int u) {
    if (g[u].empty()) {  // leaf
        assert(lca[u].empty());
        ans += (static_cast<int64_t>(single[u])) * (single[u] - 1) / 2;
        ans += (static_cast<int64_t>(single[u])) * (up[u]);
    } else {
        for (auto&& v : g[u]) process(v);
        for (auto&& [x, y] : lca[u]) {
            up[x]--;
            if (x != y) up[y]--;
        }

        clear();
        for (auto&& [x, y] : lca[u]) add_pair(x, y);
        // single match
        ans += (static_cast<int64_t>(single[u])) * (single[u] - 1) / 2;
        ans += (static_cast<int64_t>(single[u])) * (up[u]);
        for (auto&& v : g[u]) ans += (static_cast<int64_t>(single[u])) * (up[v]);
        ans += (static_cast<int64_t>(single[u])) * (lca[u].size());
        // lca + up match
        ans += (static_cast<int64_t>(up[u])) * (lca[u].size());
        for (auto&& v : g[u]) {
            remove_pairs(v, v);
            ans += lca_count * up[v];
            readd_pairs(v, v);
        }
        // lca + lca match
        int64_t temp = 0;
        for (auto&& [x, y] : lca[u]) {
            remove_pairs(x, y);
            temp += lca_count;
            readd_pairs(x, y);
        }
        assert(temp % 2 == 0);
        ans += temp / 2;
        for (auto&& v : g[u]) up[u] += up[v];
    }
}

void solve() {
    cin >> n;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    h[1] = 1;
    dfs(1);
    cin >> m;
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        auto [root, first, second] = get_lca(u, v);
        if (root == first) {
            assert(root == second);
            single[root]++;
        } else {
            assert(root != second);
            lca[root].emplace_back(first, second);
            if (first != second) {
                up[u]++;
                up[v]++;
            } else {
                if (u == root) {
                    up[v]++;
                } else {
                    assert(v == root);
                    up[u]++;
                }
            }
        }
    }
    process(1);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}