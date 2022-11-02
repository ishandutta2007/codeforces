#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

vector <int> e[N], g[N];

int n, m, fa[N], d[N], f[N][20], a[N], b[N], q, c[N], tot, ans, dp[N];

void dfs_(int u) {
    d[u] = d[fa[u]] + 1, f[u][0] = fa[u];

    for (int v : e[u]) {
        if (d[v]) {
            continue;
        }

        fa[v] = u, dfs_(v);
        g[u].push_back(v);
    }
}

void dfs1_(int u) {
    for (int v : g[u]) {
        dfs1_(v);
        c[u] ^= c[v];
    }

    tot += c[u] > 0;
}

int lca_(int u, int v) {
    if (d[u] < d[v]) {
        swap(u, v);
    }

    int w = d[u] - d[v];

    for (int k = 19; k >= 0; k--) {
        if (w&(1<<k)) {
            u = f[u][k];
        }
    }

    if (u == v) {
        return u;
    }

    for (int k = 19; k >= 0; k--) {
        if (f[u][k] != f[v][k]) {
            u = f[u][k];
            v = f[v][k];
        }
    }

    return f[u][0];
}

void dfs2_(int u) {
    for (int v : g[u]) {
        dfs2_(v);

        dp[u] += dp[v];
    }

    ans += dp[u]/2, dp[u] %= 2;

    if (!c[u]) {
        ans += dp[u];
        dp[u] = 0;
    } else {
        dp[u] = 1;
    }
}

int main() {
    scanf("%d%d", &n, &m);

    for (int u, v, i = 1; i <= m; i++) {
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }

    dfs_(1);

    for (int k = 1; k < 20; k++) {
        for (int i = 1; i <= n; i++) {
            f[i][k] = f[f[i][k - 1]][k - 1];
        }
    }

    scanf("%d", &q);

    for (int i = 1; i <= q; i++) {
        scanf("%d%d", &a[i], &b[i]);
        c[a[i]] ^= 1, c[b[i]] ^= 1;
    }

    dfs1_(1);

    if (!tot) {
        puts("YES");

        vector <int> tmp;

        for (int i = 1, x; i <= q; i++) {
            x = lca_(a[i], b[i]);
            printf("%d\n", d[a[i]] + d[b[i]] - 2*d[x] + 1);
            tmp.clear();

            while (a[i] != x) {
                printf("%d ", a[i]);
                a[i] = fa[a[i]];
            }

            printf("%d ", x);

            while (b[i] != x) {
                tmp.push_back(b[i]);
                b[i] = fa[b[i]];
            }

            for (int j = tmp.size() - 1; j >= 0; j--) {
                printf("%d ", tmp[j]);
            }

            puts("");
        }

        return 0;
    }

    puts("NO");

    dfs2_(1);

    printf("%d\n", ans);
}