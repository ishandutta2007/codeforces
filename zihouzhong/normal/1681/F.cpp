#include <bits/stdc++.h>
using namespace std;

const int maxn = 500010;
int n, dep[maxn], tid[maxn], sz[maxn], fa[maxn][20];
int down[maxn], up[maxn], par[maxn], mark[maxn];
array<int, 3> e[maxn];
vector<int> G[maxn], H[maxn], id[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1, u, v, x; i < n; i++) {
        scanf("%d %d %d", &u, &v, &x), e[i] = {u, v, x};
        G[u].push_back(v), G[v].push_back(u);
    }
    auto dfs = [&](auto self, int u) -> void {
        static int tim = 0;
        tid[u] = ++tim, sz[u] = 1;
        dep[u] = dep[fa[u][0]] + 1;
        for (int i = 1; 1 << i < dep[u]; i++) {
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        }
        for (int v : G[u]) if (v ^ fa[u][0]) {
            fa[v][0] = u, self(self, v), sz[u] += sz[v];
        }
    };
    dfs(dfs, 1);
    auto lca = [&](int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        for (int i = 19; ~i; i--) {
            if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
        }
        if (u == v) return u;
        for (int i = 19; ~i; i--) {
            if (fa[u][i] ^ fa[v][i]) u = fa[u][i], v = fa[v][i];
        }
        return fa[u][0];
    };
    for (int i = 1; i < n; i++) {
        if (dep[e[i][0]] < dep[e[i][1]]) swap(e[i][0], e[i][1]);
        id[e[i][2]].push_back(e[i][0]);
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) if (!id[i].empty()) {
        vector<int> V = {1};
        for (int x : id[i]) {
            V.push_back(x), V.push_back(fa[x][0]);
        }
        sort(V.begin(), V.end(), [&](int u, int v) { return tid[u] < tid[v]; });
        V.resize(unique(V.begin(), V.end()) - V.begin());
        for (int j = 0, $ = V.size(); j < $ - 1; j++) {
            V.push_back(lca(V[j], V[j + 1]));
        }
        sort(V.begin(), V.end(), [&](int u, int v) { return tid[u] < tid[v]; });
        V.resize(unique(V.begin(), V.end()) - V.begin());
        for (int x : V) H[x].clear(), mark[x] = 0;
        for (int x : id[i]) mark[x] = 1;
        vector<int> st = {1};
        for (int j = 1; j < V.size(); j++) {
            while (!st.empty() && tid[V[j]] >= tid[st.back()] + sz[st.back()]) st.pop_back();
            H[par[V[j]] = st.back()].push_back(V[j]), st.push_back(V[j]);
        }
        auto dfs1 = [&](auto self, int u) -> void {
            down[u] = 0;
            for (int v : H[u]) {
                self(self, v);
                if (mark[v]) down[u] += sz[v];
                else down[u] += down[v];
            }
        };
        auto dfs2 = [&](auto self, int u) -> void {
            int all = 0;
            for (int v : H[u]) {
                if (mark[v]) all += sz[v];
                else all += down[v];
            }
            for (int v : H[u]) {
                int _all = all;
                if (mark[v]) _all -= sz[v];
                else _all -= down[v];
                if (mark[u]) up[v] = _all + n - sz[u];
                else up[v] = up[u] + _all;
                self(self, v);
            }
        };
        dfs1(dfs1, 1);
        up[1] = 0, dfs2(dfs2, 1);
        for (int x : id[i]) {
            ans += 1LL * (sz[x] - down[x]) * (n - sz[x] - up[x]);
        }
    }
    printf("%lld\n", ans);
    return 0;
}