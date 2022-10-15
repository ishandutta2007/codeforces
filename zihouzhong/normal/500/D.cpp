#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, q, sz[maxn], cur[maxn];
vector<array<int, 3>> G[maxn];
double ans, coef[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1, u, v, w; i < n; i++) {
        scanf("%d %d %d", &u, &v, &w), cur[i] = w;
        G[u].push_back({v, w, i});
        G[v].push_back({u, w, i});
    }
    function<void(int, int)> dfs = [&](int v, int fa) {
        sz[v] = 1;
        for (auto &e : G[v]) if (e[0] ^ fa) {
            dfs(e[0], v), sz[v] += sz[e[0]];
            coef[e[2]] = 1LL * sz[e[0]] * (sz[e[0]] - 1) * (n - sz[e[0]]);
            coef[e[2]] += 1LL * (n - sz[e[0]]) * (n - sz[e[0]] - 1) * sz[e[0]];
            ans += coef[e[2]] * e[1];
        }
    };
    dfs(1, 0), scanf("%d", &q);
    while (q--) {
        int id, w;
        scanf("%d %d", &id, &w);
        ans -= coef[id] * (cur[id] - w), cur[id] = w;
        printf("%.9f\n", ans / (1LL * n * (n - 1) * (n - 2) / 6));
    }
    return 0;
}