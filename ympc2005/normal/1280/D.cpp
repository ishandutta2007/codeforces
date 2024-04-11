#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, ll> pil;

const int N = 3005, mod = 1e9 + 7;

int n, m, sz[N], a[N];

vector <int> e[N];

pil f[N][N], g[N];

pil operator + (pil a, pil b) { return pil(a.first + b.first, a.second + b.second); }

void dfs_(int u, int fa) {
    sz[u] = 0;
    f[u][0] = pil(0, a[u]);

    for (int v : e[u]) {
        if (fa == v) {
            continue;
        }

        dfs_(v, u);

        for (int i = 0; i <= sz[u] + sz[v]; i++) {
            g[i] = pil(-1e9, -1e18);
        }

        for (int i = 0; i <= sz[u]; i++) {
            for (int j = 0; j <= sz[v]; j++) {
                g[i + j] = max(g[i + j], f[u][i] + f[v][j]);
            }
        }

        sz[u] += sz[v];

        for (int i = 0; i <= sz[u]; i++) {
            f[u][i] = g[i];
        }
    }

    if (u == 1) {
        printf("%d\n", f[1][m - 1].first + (f[1][m - 1].second > 0));
    }

    sz[u]++;
    f[u][sz[u]] = pil(-1e9, -1e18);

    for (int i = sz[u]; i; i--) {
        f[u][i] = max(f[u][i], pil(f[u][i - 1].first + (f[u][i - 1].second > 0), 0));
    }
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        scanf("%d%d", &n, &m);

        for (int i = 1; i <= n; i++) {
            e[i].clear();
            a[i] = 0;
        }

        for (int x, i = 1; i <= n; i++) {
            scanf("%d", &x);
            a[i] -= x;
        }

        for (int x, i = 1; i <= n; i++) {
            scanf("%d", &x);
            a[i] += x;
        }

        for (int u, v, i = 1; i < n; i++) {
            scanf("%d%d", &u, &v);
            e[u].push_back(v);
            e[v].push_back(u);
        }

        dfs_(1, 0);
        //printf("%d\n", f[1][m].first);
    }
}