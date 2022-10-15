#include <bits/stdc++.h>
using namespace std;

const int P = 998244353;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }
    vector<vector<int>> id(*max_element(a.begin(), a.end()) + 1);
    for (int i = 0; i < n; i++) {
        id[a[i]].push_back(i);
    }
    vector<vector<int>> G(n);
    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v, u--, v--;
        G[u].push_back(v), G[v].push_back(u);
    }
    vector<int> tid(n), sz(n), dep(n);
    vector par(__lg(n) + 1, vector(n, -1));
    {
        int tim = 0;
        auto dfs = [&](auto self, int u, int fa) -> void {
            tid[u] = tim++, sz[u] = 1;
            if (~fa) dep[u] = dep[par[0][u] = fa] + 1;
            for (int v : G[u]) if (v != fa) {
                self(self, v, u), sz[u] += sz[v];
            }
        };
        dfs(dfs, 0, -1);
        for (int i = 1; i < par.size(); i++) {
            par[i] = par[i - 1];
            for (int j = 0; j < n; j++) {
                if (~par[i][j]) par[i][j] = par[i - 1][par[i][j]];
            }
        }
    }
    auto lca = [&](int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        int d = dep[u] - dep[v];
        while (d) {
            int i = __builtin_ctz(d);
            u = par[i][u], d ^= 1 << i;
        }
        if (u == v) return u;
        for (int i = par.size() - 1; ~i; i--) {
            if (par[i][u] != par[i][v]) u = par[i][u], v = par[i][v];
        }
        return par[0][u];
    };
    vector<bool> pr(id.size());
    vector<vector<int>> H(n);
    vector<int> num(n);
    int ans = 0;
    for (int p = 2; p < pr.size(); p++) {
        if (pr[p]) continue;
        vector<int> ver;
        for (int x = p; x < id.size(); x += p) {
            ver.insert(ver.end(), id[x].begin(), id[x].end());
        }
        if (ver.empty()) continue;
        sort(ver.begin(), ver.end(), [&](int u, int v) {
            return tid[u] < tid[v];
        });
        int tot = ver.size();
        for (int i = 0, t = ver.size(); i + 1 < t; i++) {
            ver.push_back(lca(ver[i], ver[i + 1]));
        }
        sort(ver.begin(), ver.end(), [&](int u, int v) {
            return tid[u] < tid[v];
        });
        ver.resize(unique(ver.begin(), ver.end()) - ver.begin());
        vector<int> st{ver[0]};
        for (int i = 1; i < ver.size(); i++) {
            while (tid[st.back()] + sz[st.back()] <= tid[ver[i]]) {
                st.pop_back();
            }
            H[st.back()].push_back(ver[i]), st.push_back(ver[i]);
        }
        auto dfs = [&](auto self, int u) -> void {
            num[u] = a[u] % p == 0;
            for (int v : H[u]) {
                self(self, v), num[u] += num[v];
                ans = (ans + 1LL * (tot - num[v]) * (tot - num[v] - 1) / 2
                    * num[v] % P * (dep[v] - dep[u])) % P;
                ans = (ans + 1LL * num[v] * (num[v] - 1) / 2 * (tot -
                    num[v]) % P * (dep[v] - dep[u])) % P;
            }
        };
        dfs(dfs, ver[0]);
        for (int u : ver) {
            H[u].clear();
        }
        for (int x = p + p; x < pr.size(); x += p) {
            pr[x] = 1;
        }
    }
    cout << ans << "\n";
    return 0;
}