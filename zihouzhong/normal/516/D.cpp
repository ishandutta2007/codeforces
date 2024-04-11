#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 200010;
int n, q, p[maxn], fa[maxn], w[maxn];
ll f[maxn], g[maxn], up[maxn];
vector<array<int, 2>> G[maxn];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main() {
    scanf("%d", &n);
    for (int i = 1, u, v, w; i < n; i++) {
        scanf("%d %d %d", &u, &v, &w);
        G[u].push_back({v, w}), G[v].push_back({u, w});
    }
    auto chk = [&](int u, ll d) {
        g[u] = max(g[u], d);
        if (g[u] > f[u]) swap(g[u], f[u]);
    };
    function<void(int, int)> dfs1 = [&](int u, int fa) {
        for (auto &e : G[u]) if (e[0] ^ fa) {
            dfs1(e[0], u), chk(u, f[e[0]] + e[1]);
        }
    };
    function<void(int, int)> dfs2 = [&](int u, int fa) {
        for (auto &e : G[u]) if (e[0] ^ fa) {
            chk(e[0], e[1] + (f[e[0]] + e[1] == f[u] ? g[u] : f[u])), dfs2(e[0], u);
        }
        for (auto &e : G[u]) {
            make_pair(f[u], u) < make_pair(f[e[0]], e[0]) ? up[e[0]] = u : up[u] = e[0];
        }
    };
    dfs1(1, 0), dfs2(1, 0);
    scanf("%d", &q);
    iota(p + 1, p + n + 1, 1);
    sort(p + 1, p + n + 1, [&](int u, int v) {
        return make_pair(f[u], u) < make_pair(f[v], v);
    });
    while (q--) {
        long long d;
        scanf("%lld", &d);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            fa[i] = i, w[i] = 1;
        }
        for (int i = n, j = n; i; i--) {
            while (f[p[j]] > f[p[i]] + d) w[find(p[j--])]--;
            ans = max(ans, w[p[i]]);
            w[fa[p[i]] = up[p[i]]] += w[p[i]];
        }
        printf("%d\n", ans);
    }
    return 0;
}